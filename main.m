
%% start clustering

clear;
close all
cell_count = 9;
soc = fix(rand (1, cell_count) * 100);
%soc = [10    10    60     40    40    40    90    88    96];
%soc = [69    31    95     20    43    38    76    79    18];
mp = 2;
ep = 10;

% clustering
[cluster] = pso_DBSCAN(soc, mp, ep);

% plot the clustering result
visualization(soc, cluster);

itteration = 0;
soc_transfered = 0;

while cluster.clt_max_count > 1

    %% clustering and balancing
    
    % balancing
    [soc_transfered, soc] = balance_soc(cluster, soc, mp, ep);
    
    % clustering
    [cluster] = pso_DBSCAN(soc, mp, ep);
    
    % plot the balancing result
    visualization(soc, cluster);
    
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

