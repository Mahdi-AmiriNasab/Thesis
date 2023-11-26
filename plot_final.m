function plot_final(soc_in, mp, best_ep)

    soc = soc_in;
    itteration = 0;
    ep = best_ep;
    
    % clustering
    [cluster] = pso_DBSCAN(soc, mp, ep);

    figure;
    tile_counter = 0;
    fg_row = 2; fg_column = 3;
    tiledlayout(fg_row ,fg_column);  % Create a 2x1 grid layout

    % plot the clustering result
    nexttile;
    visualization(soc, cluster);
    tile_counter = tile_counter + 1;
    
    while cluster.clt_max_count > 1
    
    
        % balancing
        [soc_transfered, soc, blc_time] = balance_soc(cluster, soc, mp, ep, 1, 2200, 2000);

        % store charge profile
        soc_profile(itteration + 2, :) = soc;
        
        % clustering
        [cluster] = pso_DBSCAN(soc, mp, ep);

        % plot the balancing result
        if(tile_counter >= fg_row * fg_column)
            figure;
            tiledlayout(fg_row ,fg_column);  % Create a 2x1 grid layout
            tile_counter = 0;
        end
        nexttile;
        visualization(soc, cluster);
        tile_counter = tile_counter + 1;

        % count each balancing itteration
        itteration = itteration + 1;
        
        % sorting cluster.clt_res_soc_av 
        V = cluster.clt_res_soc_av;
        V(V(:,2)==0,2) = Inf;
        cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
        cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;
    
        if itteration > 20
            % error("maximum itteration reached");
            % disp("maximum itteration reached");
            break;
        end
    
    end
    
    % fill null the remaining tiles in a figure
    while (tile_counter < fg_row * fg_column)
        nexttile;
        tile_counter = tile_counter + 1;
    end

    clear soc_transfered V  blc_time tile_counter
    
    
    
    
    
    end
    
    