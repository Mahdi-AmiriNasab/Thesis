
function [clt] = pso_DBSCAN(socs, minPts, eps)
%% initialization
cell_cnt = length(socs);
%socs = fix(rand (1, cell_cnt) * 100);
% eps = 10;
% minPts = 3;
%% clustering
clt.average = fix(mean(socs));
error = [(1:cell_cnt); socs - repmat(clt.average, 1, cell_cnt)];

dbscan_res_clm = dbscan(error(2, :)', eps, minPts);
%data_cluster = [error(2, :); dbscan_res_clm'];

% finding adjacent clusters
s_index = 1;                        % stores cluster indices
s_column = 1;                       % stores number of each cells in the cluster
av_index = 1;                       % stores the index average of each cluster
clt.dbscan_res = dbscan_res_clm';
clt.clt_res_cell = zeros(cell_cnt, cell_cnt);   % init maximum number of clusters containig cell indices
clt.clt_res_soc = zeros(cell_cnt, cell_cnt);    % init maximum number of clusters containig cell socs
clt.clt_res_soc_av = zeros(cell_cnt, 2);        % init maximum number of clusters containig cell socs
for n = 1:cell_cnt

    if (clt.clt_res_cell(s_index, s_column) == 0)
        clt.clt_res_cell(s_index, s_column) = n;
        clt.clt_res_soc(s_index, s_column) = socs(1, n);
    else
        % find simularities whilest the data is not noise
        if(clt.dbscan_res(1, n) == clt.dbscan_res(1, n-1) && clt.dbscan_res(1, n) ~= -1) 
            s_column = s_column + 1; 
            clt.clt_res_cell(s_index, s_column) = n;
            clt.clt_res_soc(s_index, s_column) = socs(1, n);
        else
            % update the cluster index if no similarities found
            s_column = 1;           
            s_index = s_index + 1;
            clt.clt_res_cell(s_index, s_column) = n;
            clt.clt_res_soc(s_index, s_column) = socs(1, n);
        end
    end
    % calculating average of each cluster
    mn_tmp = mean(nonzeros(clt.clt_res_soc(s_index, :)));
    if(~isnan(mn_tmp))
        clt.clt_res_soc_av(s_index, 1) = fix(mn_tmp);
        clt.clt_res_soc_av(s_index, 2) = s_index;
    end

end

% sorting
clt.clt_res_soc_av = sortrows(clt.clt_res_soc_av, 1, 'descend');

%% finding noise

s_column = 1;
c_column = 1;
clt.noise_soc = zeros (2, cell_cnt);            % to store noise vs soc
clt.cluster_soc = zeros (2, cell_cnt);      % to store cluster vs average soc
for n = 1:cell_cnt

    if clt.clt_res_cell(n , 1) ~= 0         % noise detected
        if (clt.clt_res_cell(n, 2) == 0)
            clt.noise_soc(1, s_column) = clt.clt_res_cell(n, 1);
            clt.noise_soc(2, s_column) = socs(1, clt.clt_res_cell(n, 1));
            s_column = s_column + 1;
        else    %cluster detected
            clt.cluster_soc(1, c_column) = n;
            % find the corresponding soc of the index (n)
            found_index = find(clt.clt_res_soc_av(:, 2) == n);
            % check if the found_index is not empty
            if ~isempty(found_index)
                clt.cluster_soc(2, c_column) = clt.clt_res_soc_av(found_index(1, 1) ,1);
            end
            c_column = c_column + 1;
        end
        
    end
end

if all(clt.noise_soc(2, :) == 0)
    clt.noise_max = [0 ;0];
    clt.noise_min = [0 ;0];
else
    % maximum niose
    non_zero_indices = clt.noise_soc(2, :) ~= 0;
    clt.noise_min(2, 1) = min(clt.noise_soc(2, non_zero_indices));
    tmp = find(socs == clt.noise_min(2, 1));
    clt.noise_min(1, 1) = tmp(1, 1);
    
    % minimum niose
    clt.noise_max(2, 1) = max(clt.noise_soc(2, :));
    tmp = find(socs == clt.noise_max(2, 1));
    clt.noise_max(1, 1) = tmp(1, 1);

end

vis = [];

for i = 1:size(clt.clt_res_cell ,1)
    nonZeroIndices = find(clt.clt_res_cell(i,:));
    vis = [vis; repmat(i, length(nonZeroIndices), 1)];
end

%% vizualization
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
colorbar;
end