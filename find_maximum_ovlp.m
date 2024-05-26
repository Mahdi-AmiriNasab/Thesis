
%% start clustering

clear 
close all
cell_count = 9;
cell_cap_Ah = 2.2;

%soc = [39    39    20    72    81    92    51    11    60]; % good one

%soc = [1    10    20    30    40    50    50    50    50]; % test
lg_eq_overlap_total = [];
for n = 1:20
    soc = fix(rand (1, cell_count) * 100);
    
    while any(soc == 0)
        soc = fix(rand (1, cell_count) * 100);
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
    lg_eq_overlap_total(:, n) = lg_eq_overlap(:, 1);
    close all;
    display(n)
end
plot(max(lg_eq_overlap_total));
toplot = max(lg_eq_overlap_total)';

