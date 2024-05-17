function [lg_time, lg_inconsistency, lg_eq_overlap] = log_clustering(soc_in, mp, ep_arr)

coder.extrinsic('plot', 'nexttile', 'tiledlayout');

cell_count = length(soc_in);

soc_profile = zeros(1, cell_count);
coder.varsize('soc_profile', [inf, cell_count], [1, 0]); % Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is variable
soc_profile = NaN(100, cell_count);

lg_time = zeros(length(ep_arr), 1);
lg_inconsistency = zeros(length(ep_arr), 1);
lg_eq_overlap = zeros(length(ep_arr), 1);

for ep = ep_arr 

    soc = soc_in;
    itteration = 0;
    soc_transfered_total = 0;
    blc_time_total = 0;

    soc_profile(itteration + 1, :) = soc;
    
    
    % clustering
    [cluster] = pso_DBSCAN(soc, mp, ep);
    
    while cluster.clt_max_count > 1
    
    
        % balancing
        [soc_transfered, soc, blc_time] = balance_soc(cluster, soc, mp, ep, 1, 2200, 2000);

        % store charge profile
        soc_profile(itteration + 2, :) = soc;
        
        % clustering
        [cluster] = pso_DBSCAN(soc, mp, ep);
    
        itteration = itteration + 1;
        
        % sorting cluster.clt_res_soc_av 
        V = cluster.clt_res_soc_av;
        V(V(:,2)==0,2) = Inf;
        cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
        cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;
        soc_transfered_total = soc_transfered_total + soc_transfered;
        blc_time_total = blc_time_total + blc_time;
    
        if itteration > 20
            % error("maximum itteration reached");
            % disp("maximum itteration reached");
            break;
        end
    
    end
    
    if coder.target('MATLAB')
        clear soc_transfered V  blc_time
    end
    
    soc_profile(any(isnan(soc_profile), 2), :) = [];  % Remove any row with NaN
  
    ep_i = find(ep_arr == ep);
    
    lg_time(ep_i) = blc_time_total;
    lg_inconsistency(ep_i) = max(soc) - min(soc);
    global no_ovp_plot_flag;
    no_ovp_plot_flag = 0;
    % summing equalization overlap value of each cell after balancing 
    for n = 1:cluster.cell_cnt
        OE = calculate_overlap(soc_profile(:, n)');
        lg_eq_overlap(ep_i) = lg_eq_overlap(ep_i) + OE;
    end
    

end


figure;
tiledlayout(3 ,1);  % Create a 2x1 grid layout

nexttile;
plot(ep_arr', lg_inconsistency);
title('inconsistency')
xlabel('eps')
ylabel('% SOC')




nexttile;
plot(ep_arr', lg_time);
title('equalization time')
xlabel('eps')
ylabel('time(h)')

nexttile;
plot(ep_arr', lg_eq_overlap);
title('equalization overlap')
xlabel('eps')
ylabel('% SOC')




end

