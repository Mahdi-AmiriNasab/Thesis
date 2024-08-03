function [eq_step, soc, time, inconsistency, eq_overlap] = plot_final(soc_in, mp, best_ep, ep_arr, lg_time, lg_inconsistency, lg_eq_overlap)

    % equalization steps storage
    eq_step.source_queue_cells = [];            % [start_cell, stop_cell]       step 1
                                                %           .                   step 2
                                                %           .                   step 3
                                                %           .                   step n

    eq_step.destination_queue_cells = [];       % [start_cell, stop_cell]       step 1
                                                %           .                   step 2
                                                %           .                   step 3
                                                %           .                   step n

    eq_step.source_target_soc_av = [];          % [src cluster average soc]     step 1
                                                %           .                   step 2
                                                %           .                   step 3
                                                %           .                   step n     

    eq_step.destination_target_soc_av = [];     % [des cluster average soc]     step 1
                                                %           .                   step 2
                                                %           .                   step 3
                                                %           .                   step n  


    soc_profile = [] ;

    soc = soc_in;
    itteration = 0;
    ep = best_ep;

    % Right y-axis labels
    right_y_labels = {'(الف)', '(ب)', '(ج)', '(د)', '(ه)', '(و)'};
    
    % clustering
    [cluster] = pso_DBSCAN(soc, mp, ep);

    % Create a named figure
    figure('Name', 'Balancing Result');
    tile_counter = 0;
    fg_row = 2; fg_column = 3;
    t = tiledlayout(fg_row, fg_column);  % Create a 2x3 grid layout
    
    % Font and line width settings
    font_name = 'Helvetica';
    font_size = 22;
    line_width = 2.5;
    tick_font_size = 18; % Add this line to set tick font size

    % plot the clustering result
    nexttile;
    visualization(soc, cluster);
    yyaxis left;
    ylabel('% SOC', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
    xlabel('Cells', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
    set(gca, 'FontSize', tick_font_size); % Set the tick font size
    yyaxis right;
    set(gca, 'YColor', 'none');
    h = ylabel(right_y_labels{tile_counter + 1}, 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
    set(h, 'Rotation', 90, 'HorizontalAlignment', 'left', 'VerticalAlignment', 'middle');

    tile_counter = tile_counter + 1;
    balancing_fig_counter = 1; % Initialize figure counter for balancing results

    soc_profile(1, :) = soc;
    blc_time_total = 0;

    while cluster.clt_max_count > 1
    
        % balancing
        [soc_transfered, soc, blc_time, eq_step(itteration + 1)] = balance_soc(cluster, soc, mp, ep, 2200, 2000);

        % store charge profile
        soc_profile(itteration + 2, :) = soc;
        
        % clustering
        [cluster] = pso_DBSCAN(soc, mp, ep);

        % Create a new named figure if needed
        if(tile_counter >= fg_row * fg_column)
            tile_counter = 0;
        end
        if tile_counter == 0
            figure('Name', sprintf('Balancing Result %d', balancing_fig_counter));
            balancing_fig_counter = balancing_fig_counter + 1; % Increment figure counter for balancing results
            t = tiledlayout(fg_row, fg_column);  % Create a 2x3 grid layout
        end
        nexttile(t);
        visualization(soc, cluster);
        yyaxis left;
        ylabel('% SOC', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
        xlabel('Cells', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
        set(gca, 'FontSize', tick_font_size); % Set the tick font size
        yyaxis right;
        set(gca, 'YColor', 'none');
        h = ylabel(right_y_labels{tile_counter + 1}, 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
        set(h, 'Rotation', 90, 'HorizontalAlignment', 'left', 'VerticalAlignment', 'middle');

        tile_counter = tile_counter + 1;

        % count each balancing iteration
        itteration = itteration + 1;
        
        % sorting cluster.clt_res_soc_av 
        V = cluster.clt_res_soc_av;
        V(V(:,2) == 0, 2) = Inf;
        cluster.clt_res_soc_av = sortrows(V, 2, 'ascend');
        cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2) == Inf, 2) = 0;
        blc_time_total = blc_time_total + blc_time;
    
        if itteration > 20
            % error("maximum itteration reached");
            % disp("maximum itteration reached");
            break;
        end
    end
    
    % fill null the remaining tiles in a figure
    while (tile_counter < fg_row * fg_column)
        nexttile(t);
        title(''); % Clear any title or content
        tile_counter = tile_counter + 1;
    end

    % Define a cell array of markers for each line
    markers = {'o', '+', '*', '.', 'x', 's', 'd', '^', 'v'};

    figure('Name', 'SOC profile');
    font_name = 'Helvetica';
    font_size = 22;
    line_width = 2.5;
    tick_font_size = 18; % Add this line to set tick font size

    soc_profile(any(isnan(soc_profile), 2), :) = [];  % Remove any row with NaN

    overlap_pack = 0;
    %no_ovp_plot_flag = 0;
    % summing equalization overlap value of each cell after balancing 
    for n = 1:cluster.cell_cnt
        overlap_cell = calculate_overlap(soc_profile(:, n)');
        overlap_pack = overlap_pack + overlap_cell;
    end
    %no_ovp_plot_flag = 0;

        
    % results
    time = blc_time_total;
    inconsistency = max(soc) - min(soc);
    eq_overlap = overlap_pack;

    hold on;
    for i = 1:size(soc_profile, 2)
        plot(soc_profile(:, i), 'LineWidth', line_width, 'Marker', markers{i});
    end
    hold off;
    
    ylabel('%SOC', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set the color to black
    xlabel('steps', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set x-axis color to black
    
    set(gca, 'FontSize', tick_font_size); % Set the tick font size
    
    % Set x-axis to integer values only without decimation
    xticks(0:length(soc_profile)-1);
    xtickformat('%.0f'); % Ensure no decimal points
    
    legend('Cell 1', 'Cell 2', 'Cell 3', 'Cell 4', 'Cell 5', 'Cell 6', 'Cell 7', 'Cell 8', 'Cell 9');
    % Ensure tile_counter is cleared at the very end
    clear soc_transfered V blc_time tile_counter

    if coder.target('MATLAB')

        % Create a new figure
        figure('Name', 'sto');
    
        % Create a 3x1 tiled layout
        tiledlayout(3, 1);
    
        % Font and line width settings
        font_name = 'Helvetica';
        font_size = 22;
        line_width = 2.5;
        tick_font_size = 18; % Add this line to set tick font size
    
        % First plot
        nexttile;
        yyaxis left;
        set(gca, 'YColor', 'k'); % Set y-axis ticks to black
        plot(ep_arr', lg_inconsistency, 'LineWidth', line_width);
        ylabel('% SOC', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set the color to black
        yyaxis right;
        set(gca, 'YColor', 'none'); % Hide right y-axis tick labels and line
        if coder.target('MATLAB')
            % ylabel('(الف)', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Add label
        else
            ylabel('(a)', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Add label
        end
    
        title('inconsistency', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set title color to black
        xlabel('eps', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set x-axis color to black
        set(gca, 'FontSize', tick_font_size); % Set the tick font size
    
        % Second plot
        nexttile;
        yyaxis left;
        set(gca, 'YColor', 'k'); % Set y-axis ticks to black
        plot(ep_arr', lg_time, 'LineWidth', line_width);
        ylabel('time(S)', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set the color to black
        yyaxis right;
        set(gca, 'YColor', 'none'); % Hide right y-axis tick labels and line
        if coder.target('MATLAB')
            % ylabel('(ب)', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Add label
        else
            ylabel('(b)', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Add label
        end
    
        title('equalization time', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set title color to black
        xlabel('eps', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set x-axis color to black
        set(gca, 'FontSize', tick_font_size); % Set the tick font size
    
        % Third plot
        nexttile;
        yyaxis left;
        set(gca, 'YColor', 'k'); % Set y-axis ticks to black
        plot(ep_arr', lg_eq_overlap, 'LineWidth', line_width);
        ylabel('% SOC', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set the color to black
        yyaxis right;
        set(gca, 'YColor', 'none'); % Hide right y-axis tick labels and line
        if coder.target('MATLAB')
            % ylabel('(ج)', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Add label
        else
            ylabel('(c)', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Add label
        end
    
        title('equalization overlap', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set title color to black
        xlabel('eps', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k'); % Set x-axis color to black
        set(gca, 'FontSize', tick_font_size); % Set the tick font size
    
        end
    
   
end
