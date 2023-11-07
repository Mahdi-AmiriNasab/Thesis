
%% start clustering

clear;
close all
cell_count = 9;
%soc = fix(rand (1, cell_count) * 100);
%soc = [69    23    25    24    66    67    55    55    67];
soc = [2    3    50    1    4    6    49    4    5];

soc_init = soc;


mp = 2;
ep = 1;

% clustering
[cluster] = pso_DBSCAN(soc, mp, ep);

%figure;
tile_counter = 0;
fg_row = 2; fg_column = 3;
tiledlayout(fg_row ,fg_column);  % Create a 2x1 grid layout


% plot the clustering result
nexttile;
visualization(soc, cluster);
tile_counter = tile_counter + 1;


itteration = 0;
soc_transfered = 0;



while cluster.clt_max_count > 1

    %% clustering and balancing
    
    % balancing
    [soc_transfered, soc] = balance_soc(cluster, soc, mp, ep);
    
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
    
    if itteration > 20
        error("maximum itteration reached")
    end

    % sorting cluster.clt_res_soc_av 
    V = cluster.clt_res_soc_av;
    V(V(:,2)==0,2) = Inf;
    cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
    cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;

end

soc_inconsistency = max(soc) - min(soc);













% unify the soc
% soc_uni = unique(cluster.clt_res_soc_av(1, :)); % in order to prevent error on interp1 function
% 
% nearest_value_mx_x = interp1(cluster.clt_res_soc_av(1, :), cluster.clt_res_soc_av(1, :) ...
%     , cluster.noise_max(2, 1), 'nearest', 'extrap');
% nearest_value_mx_n = interp1(cluster.clt_res_soc_av(1, :), cluster.clt_res_soc_av(1, :), cluster.noise_min(2, 1), 'nearest', 'extrap');



% to compare with the reference paper

% if ~isempty(v)
% 
%     if length(v(2, :)) >= 2
%         % nearest value to maximum noise
%         nearest_value_mx_n = interp1(v(2, :), v(2, :), cluster.noise_max(2, 1), 'nearest', 'extrap');
%         % nearest value to minimum noise
%         nearest_value_mn_n = interp1(v(2, :), v(2, :), cluster.noise_min(2, 1), 'nearest', 'extrap');
%     else
%         nearest_value_mn_m = v(2, 1);
%         nearest_value_mn_n = v(2, 1);
%     end
% end

