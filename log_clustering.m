function [lg_time, lg_inconsistency, lg_soc_transfer] = log_clustering(soc_in, mp, ep_arr)

lg_time = zeros(length(ep_arr), 1);
lg_inconsistency = zeros(length(ep_arr), 1);
lg_soc_transfer = zeros(length(ep_arr), 1);

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
            error("maximum itteration reached")
        end
    
    end
    
    clear soc_transfered V  blc_time
    
    ep_i = find(ep_arr == ep);
    
    lg_time(ep_i) = blc_time_total;
    lg_inconsistency(ep_i) = max(soc) - min(soc);
    lg_soc_transfer(ep_i) = soc_transfered_total;

end

close all 

figure;
plot(ep_arr', lg_inconsistency);
title('inconsistency')
xlabel('eps')
ylabel('% SOC')



figure;

plot(ep_arr', lg_time);
title('equalization time')
xlabel('eps')
ylabel('time(h)')


figure;
plot(ep_arr', lg_soc_transfer);
title('SOC transfer')
xlabel('eps')
ylabel('% SOC')




end

