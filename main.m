
%% start clustering

clear;
close all
cell_count = 9;
%soc = fix(rand (1, cell_count) * 100);
soc = [69    31    95     3    43    38    76    79    18];
mp  = 2;
ep = 10;
[cluster] = pso_DBSCAN(soc, mp, ep);

%% tagging

% if there is any noise 
if cluster.noise_max(2, :) == 0x00 && cluster.noise_min(2, :) == 0x00
    noise_status = e_noise_stat.noise_not_found;
else
    noise_status = e_noise_stat.noise_found;
end

% if there is any cluster
if all(cluster.clt_soc(1, :) == 0) 
    cluster_status = e_cluster_stat.cluster_not_found;
else
    cluster_status = e_cluster_stat.cluster_found;
end

%% finding the noise neighbors
% calculation for noise_max

% sorting cluster.clt_res_soc_av 
V = cluster.clt_res_soc_av;
V(V(:,2)==0,2) = Inf;
cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;

r = cluster.noise_max(1, 1);            % select the cluster number of the noise
value = cluster.clt_res_soc_av(r,1);    % select the containing value

% pick the neighbor values
% watch for the zero index
if r - 1 > 0
    value_lower = cluster.clt_res_soc_av(r - 1,1);  
else
    value_lower = cluster.clt_res_soc_av(r ,1);  
end
% watch for the maximum boundaries
if r + 1 <= cluster.clt_max_count
    value_upper = cluster.clt_res_soc_av(r + 1,1);
else
    value_upper = cluster.clt_res_soc_av(r ,1);
end

% differantion of the neighbor values
diff_lower = abs(value - value_lower);
diff_upper = abs(value - value_upper);

% store closest values and its index
neighbor_distance_x = min(diff_lower, diff_upper);
if neighbor_distance_x == diff_lower
    closest_cluster_x = cluster.clt_res_soc_av(r - 1, :);
else
    closest_cluster_x = cluster.clt_res_soc_av(r + 1, :);
end

% calculation for noise_min

r = cluster.noise_min(1, 1);            % select the cluster number of the noise
value = cluster.clt_res_soc_av(r,1);    % select the containing value

% pick the neighbor values
% watch for the zero index
if r - 1 > 0
    value_lower = cluster.clt_res_soc_av(r - 1,1);  
else
    value_lower = cluster.clt_res_soc_av(r ,1);  
end
% watch for the maximum boundaries
if r + 1 <= cluster.clt_max_count
    value_upper = cluster.clt_res_soc_av(r + 1,1);
else
    value_upper = cluster.clt_res_soc_av(r ,1);
end

% differantion of the neighbor values
diff_lower = abs(value - value_lower);
diff_upper = abs(value - value_upper);

% store closest values and its index
neighbor_distance_n = min(diff_lower, diff_upper);
if neighbor_distance_n == diff_lower
    closest_cluster_n = cluster.clt_res_soc_av(r - 1, :);
else
    closest_cluster_n = cluster.clt_res_soc_av(r + 1, :);
end

target_clt_soc = [0 0]; % stores the cluster and target soc to reach
target_transfer_soc = 0;    % stores the soc to transfer

% decide the target cluster soc
if neighbor_distance_x < neighbor_distance_n
    target_clt_soc =  closest_cluster_x;
    target_transfer_soc = neighbor_distance_x;
else
    target_clt_soc =  closest_cluster_n;
    target_transfer_soc = neighbor_distance_n;
end
%clear temporary variables used
clear r V value_upper value_lower diff_lower diff_upper

%% transfer charges

soc_new = soc;
noise_max_new = cluster.noise_max;
noise_min_new = cluster.noise_min;

noise_max_new(2, 1) = noise_max_new(2, 1) - target_transfer_soc;
noise_min_new(2, 1) = noise_min_new(2, 1) + target_transfer_soc;
soc_new(1, noise_min_new(1, 1)) = noise_min_new(2, 1);
soc_new(1, noise_max_new(1, 1)) = noise_max_new(2, 1);

figure;
mp  = 2;
ep = 10;
[cluster] = pso_DBSCAN(soc_new, mp, ep);
soc = soc_new;










%% finding the noise neighbors
% calculation for noise_max

% sorting cluster.clt_res_soc_av 
V = cluster.clt_res_soc_av;
V(V(:,2)==0,2) = Inf;
cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;

r = cluster.noise_max(1, 1);            % select the cluster number of the noise
value = cluster.clt_res_soc_av(r,1);    % select the containing value

% pick the neighbor values
% watch for the zero index
if r - 1 > 0
    value_lower = cluster.clt_res_soc_av(r - 1,1); 
else
    value_lower = cluster.clt_res_soc_av(r ,1);  
end
% watch for the maximum boundaries
if r + 1 <= cluster.clt_max_count
    value_upper = cluster.clt_res_soc_av(r + 1,1);
else
    value_upper = cluster.clt_res_soc_av(r ,1);
end

% differantion of the neighbor values
diff_lower = abs(value - value_lower);
diff_upper = abs(value - value_upper);

% watch boundaries
if r - 1 > 0
    % store closest values and its index
    neighbor_distance_x = min(diff_lower, diff_upper);
    
    if neighbor_distance_x == diff_lower
        closest_cluster_x = cluster.clt_res_soc_av(r - 1, :);
    else
        closest_cluster_x = cluster.clt_res_soc_av(r + 1, :);
    end
else
    % store closest values and its index
    neighbor_distance_x = diff_upper;
    closest_cluster_x = cluster.clt_res_soc_av(r + 1, :);
end
% calculation for noise_min

r = cluster.noise_min(1, 1);            % select the cluster number of the noise
value = cluster.clt_res_soc_av(r,1);    % select the containing value

% pick the neighbor values
% watch for the zero index
if r - 1 > 0
    value_lower = cluster.clt_res_soc_av(r - 1,1);  
else
    value_lower = cluster.clt_res_soc_av(r ,1);  
end
% watch for the maximum boundaries
if r + 1 <= cluster.clt_max_count
    value_upper = cluster.clt_res_soc_av(r + 1,1);
else
    value_upper = cluster.clt_res_soc_av(r ,1);
end

% differantion of the neighbor values
diff_lower = abs(value - value_lower);
diff_upper = abs(value - value_upper);

if r + 1 <= cluster.clt_max_count
    % store closest values and its index
    neighbor_distance_n = min(diff_lower, diff_upper);

    if neighbor_distance_n == diff_lower
        closest_cluster_n = cluster.clt_res_soc_av(r - 1, :);
    else
        closest_cluster_n = cluster.clt_res_soc_av(r + 1, :);
    end
else
    % store closest values and its index
    neighbor_distance_n = diff_lower;
    closest_cluster_n = cluster.clt_res_soc_av(r - 1, :);
end
target_clt_soc = [0 0]; % stores the cluster and target soc to reach
target_transfer_soc = 0;    % stores the soc to transfer

% decide the target cluster soc
if neighbor_distance_x < neighbor_distance_n
    target_clt_soc =  closest_cluster_x;
    target_transfer_soc = neighbor_distance_x;
else
    target_clt_soc =  closest_cluster_n;
    target_transfer_soc = neighbor_distance_n;
end
%clear temporary variables used
clear r V value_upper value_lower diff_lower diff_upper

%% transfer charges

soc_new = soc;
noise_max_cell_soc_new = [0; 0];
noise_max_cell_soc_new(1, 1) = cluster.clt_res_cell(cluster.noise_max(1, 1), 1);
noise_max_cell_soc_new(2, 1) = cluster.noise_max(2, 1);

noise_min_cell_soc_new = [0; 0];
noise_min_cell_soc_new(1, 1) = cluster.clt_res_cell(cluster.noise_min(1, 1), 1);
noise_min_cell_soc_new(2, 1) = cluster.noise_min(2, 1);


noise_max_cell_soc_new(2, 1) = noise_max_cell_soc_new(2, 1) - target_transfer_soc;
noise_min_cell_soc_new(2, 1) = noise_min_cell_soc_new(2, 1) + target_transfer_soc;
soc_new(1, noise_min_cell_soc_new(1, 1)) = noise_min_cell_soc_new(2, 1);
soc_new(1, noise_max_cell_soc_new(1, 1)) = noise_max_cell_soc_new(2, 1);

figure;
mp  = 2;
ep = 10;
[cluster] = pso_DBSCAN(soc_new, mp, ep);














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

