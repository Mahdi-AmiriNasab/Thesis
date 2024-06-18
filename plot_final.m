function [eq_step] = plot_final(soc_in, mp, best_ep)

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

    % plot the clustering result
    nexttile;
    visualization(soc, cluster);
    yyaxis left;
    ylabel('% SOC', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
    xlabel('Cells', 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
    yyaxis right;
    set(gca, 'YColor', 'none');
    h = ylabel(right_y_labels{tile_counter + 1}, 'FontName', font_name, 'FontSize', font_size, 'Color', 'k');
    set(h, 'Rotation', 90, 'HorizontalAlignment', 'left', 'VerticalAlignment', 'middle');

    tile_counter = tile_counter + 1;
    balancing_fig_counter = 1; % Initialize figure counter for balancing results
    
    while cluster.clt_max_count > 1
    

        % balancing
        [~, soc, ~, eq_step(itteration + 1)] = balance_soc(cluster, soc, mp, ep, 2200, 2000);

        % store charge profile
        % soc_profile(itteration + 2, :) = soc;
        
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

    % Ensure tile_counter is cleared at the very end
    clear soc_transfered V blc_time tile_counter
end
