
%% start clustering

clear 
close all
cell_count = 9;
cell_cap_Ah = 2.2;

soc = [39    39    20    72    81    92    51    11    60]; % good one

%soc = [1    10    20    30    40    50    50    50    50]; % test

%soc = fix(rand (1, cell_count) * 100);

if any(soc == 0)
    error("soc equal to 0 is not supproted")
end
soc_init = soc;


mp = 2;
ep = 1;

itteration = 0;
soc_transfered_total = 0;
blc_time_total = 0;

ep_domain = 0.1:0.1:20;


global no_ovp_plot_flag;

[lg_time, lg_inconsistency, lg_eq_overlap, ~] = log_clustering(soc, mp, ep_domain);
no_ovp_plot_flag = 0;
[global_best, eq_step, stio] = pso(soc, 2, 0, 0.7, 0.3);

src_q_cls = zeros(50, 2);
dst_q_cls = zeros(50, 2);
src_trg_soc_av = zeros(50, 1);
dst_trg_soc_av = zeros(50, 1);

% plot the final result obtained using PSO
[eq_step] = plot_final(soc_init, mp, global_best.position);

%% preparing output steps for for matlab simulink file
for n = 1:length(eq_step)
    src_q_cls(n, :) = eq_step(n).source_queue_cells;
    dst_q_cls(n, :) = eq_step(n).destination_queue_cells;
    src_trg_soc_av(n, 1) = eq_step(n).source_target_soc_av;
    dst_trg_soc_av(n, 1) = eq_step(n).destination_target_soc_av;

end
