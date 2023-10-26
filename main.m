
%% start clustering
clear;
cell_count = 9;
soc = fix(rand (1, cell_count) * 100);
mp  = 2;
ep = 10;
[cluster] = pso_DBSCAN(soc, mp, ep);

%% find the closest cluster to extermum niose

% collecting soc average of each cluster with cluster index in v
vi = 1;
v = [];
for n = 1:cell_count
    if cluster.clt_res_cell(n , 1) ~= 0
        if cluster.clt_res_cell(n, 2) ~= 0
            v(1, vi) = n;
            v(2, vi) = cluster.clt_res_soc_av(n, 1);    
            vi = vi + 1;
        end
    end
end 

% proposed 
% if there is any noise 
if cluster.noise_max(2, :) == 0x00 && cluster.noise_min(2, :) == 0x00
    noise_status = e_noise_stat.noise_not_found;
else
    noise_status = e_noise_stat.noise_found;
end

% if there is any cluster
if all(cluster.cluster_soc(1, :) == 0) 
    cluster_status = e_cluster_stat.cluster_not_found;
else
    cluster_status = e_cluster_stat.cluster_found;
end


if noise_status == e_noise_stat.noise_found        
    % find the index of the closest soc cluster averages to the noise values
    [~, index_x] = min(abs(cluster.clt_res_soc_av(:, 1) - cluster.noise_max(2, 1)));
    [~, index_n] = min(abs(cluster.clt_res_soc_av(:, 1) - cluster.noise_min(2, 1)));
    
    nearest_valuemx_x = cluster.clt_res_soc_av(index_x);
    nearest_valuemx_n = cluster.clt_res_soc_av(index_n);
else
    
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

