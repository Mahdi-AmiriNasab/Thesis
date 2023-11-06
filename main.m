
%% start clustering

clear;
close all
cell_count = 9;
%soc = fix(rand (1, cell_count) * 100);
soc = [69    31    95     3    43    38    76    79    18];
%soc = [69    31    95     20    43    38    76    79    18];
mp  = 2;
ep = 10;
[cluster] = pso_DBSCAN(soc, mp, ep);
itteration = 0;
soc_transfered = 0;

while cluster.clt_max_count > 1

    %% finding the noise neighbors
    % calculation for noise_max
    
    % sorting cluster.clt_res_soc_av 
    V = cluster.clt_res_soc_av;
    V(V(:,2)==0,2) = Inf;
    cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
    cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;
    
    [soc_transfered, soc] = balance_soc(cluster, soc);

	% clear noise_max_cell_soc_new noise_min_cell_soc_new soc_new
	% clear closest_cluster_n closest_cluster_x diff_lower diff_upper
	% clear neighbor_distance_n neighbor_distance_x r target_clt_soc
	% clear V target_transfer_soc value value_lower value_lower

    figure;
    %% vizualization
    vis = [];
    
    for i = 1:size(clt.clt_res_cell ,1)
        nonZeroIndices = find(clt.clt_res_cell(i,:));
        vis = [vis; repmat(i, length(nonZeroIndices), 1)];
    end
    
    clustering_v= vis + 2;  % Adjust cluster indices for visualization
    
    num_clusters = length(unique(clustering_v));  % Get the number of unique elements in clustering_v
    my_colormap = hsv(num_clusters);  % Generate a colormap with num_clusters colors
    unique_clusters = unique(clustering_v);
    color_map = containers.Map('KeyType', 'double', 'ValueType', 'any');
    for i = 1:num_clusters
        color_map(unique_clusters(i)) = my_colormap(i, :);
    end
    color_v = zeros(length(clustering_v), 3);  % Initialize color_v
    for i = 1:length(clustering_v)
        color_v(i, :) = color_map(clustering_v(i));
    end
    
    scatter(1:length(socs'), socs', 100, clustering_v', 'filled');
    yline(clt.average, '-', 'clt.average');
    
    xlim([1 cell_cnt]); ylim([0 100]);
    mp  = 2;
    ep = 10;
    [cluster] = pso_DBSCAN(soc, mp, ep);
    
    itteration = itteration + 1;
    
    if itteration > 20
        error("maximum itteration reached")
    end

end













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

