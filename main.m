
%% start clustering

clear 
close all
cell_count = 9;
% soc = fix(rand (1, cell_count) * 100);
soc = [7    88    10    95    52    50    48    42    76];
soc_init = soc;


mp = 2;
ep = 1;


% clustering
[cluster] = pso_DBSCAN(soc, mp, ep);
figure;
visualization(soc, cluster);


% %figure;
% tile_counter = 0;
% fg_row = 2; fg_column = 3;
% tiledlayout(fg_row ,fg_column);  % Create a 2x1 grid layout
% 
% 
% % plot the clustering result
% nexttile;
% visualization(soc, cluster);
% tile_counter = tile_counter + 1;


itteration = 0;
soc_transfered_total = 0;
blc_time_total = 0;

ep_domain = 0.1:0.1:20;



[lg_time, lg_inconsistency, lg_eq_overlap] = log_clustering(soc, mp, ep_domain);
[global_best, eq_step, stio] = pso(soc, 2, 0.8, 0.2, 0);

src_q_cls = zeros(50, 2);
dst_q_cls = zeros(50, 2);
src_trg_soc_av = zeros(50, 1);
dst_trg_soc_av = zeros(50, 1);

%% preparing output steps
for n = 1:length(eq_step)
    src_q_cls(n, :) = eq_step(n).source_queue_cells;
    dst_q_cls(n, :) = eq_step(n).destination_queue_cells;
    src_trg_soc_av(n, 1) = eq_step(n).source_target_soc_av;
    dst_trg_soc_av(n, 1) = eq_step(n).destination_target_soc_av;

end

% clustering
[cluster] = pso_DBSCAN(stio.soc, mp, global_best.position);

figure;
visualization(stio.soc, cluster);



% while cluster.clt_max_count > 1
% 
%     %% clustering and balancing
% 
%     % balancing
%     [soc_transfered, soc, blc_time] = balance_soc(cluster, soc, mp, ep, 1, 2200, 2000);
% 
%     % clustering
%     [cluster] = pso_DBSCAN(soc, mp, ep);
% 
%     % plot the balancing result
%     if(tile_counter >= fg_row * fg_column)
%         figure;
%         tiledlayout(fg_row ,fg_column);  % Create a 2x1 grid layout
%         tile_counter = 0;
%     end
%     nexttile;
%     visualization(soc, cluster);
%     tile_counter = tile_counter + 1;
% 
%     % count each balancing itteration
%     itteration = itteration + 1;
% 
%     if itteration > 20
%         error("maximum itteration reached")
%     end
% 
%     % sorting cluster.clt_res_soc_av 
%     V = cluster.clt_res_soc_av;
%     V(V(:,2)==0,2) = Inf;
%     cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
%     cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;
%     soc_transfered_total = soc_transfered_total + soc_transfered;
%     blc_time_total = blc_time_total + blc_time;
% end
% clear soc_transfered V fg_column fg_row tile_counter blc_time
% 
% soc_inconsistency = max(soc) - min(soc);
% 


