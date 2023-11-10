function cost = balance_costF(soc_in, mp, ep)

%[lg_time, lg_inconsistency, lg_eq_overlap] = log_clustering(soc_in, mp, ep_arr)

lg_time = 0;
lg_inconsistency = 0;
lg_eq_overlap = 0;

w_time = 0;           % weight for time
w_inconsistency = 0;  % weight for inconsitency
w_eq_overlap = 1;     % weight for overlap equalization
    

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
        disp("maximum itteration reached");
        break;
    end

end

clear soc_transfered V  blc_time

lg_time = blc_time_total;
lg_inconsistency = max(soc) - min(soc);

% summing equalization overlap value of each cell after balancing 
for n = 1:cluster.cell_cnt
    OE = calculate_overlap(soc_profile(:, n)');
    lg_eq_overlap = lg_eq_overlap + OE;
end

% combined cost
cost = w_time * lg_time + w_inconsistency * lg_inconsistency + w_eq_overlap * lg_eq_overlap;

end