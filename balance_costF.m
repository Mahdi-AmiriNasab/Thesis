function [cost, eq_step, soc, time, inconsistency, eq_overlap] = balance_costF(soc_in, mp, ep, w_time, w_inconsistency, w_eq_overlap)

	cell_count = length(soc_in);
    
	if coder.target('MATLAB')

	% equalization steps storage
	eq_step.source_queue_cells = [];            % [start_cell, stop_cell]       step 1
                                            %           .                   step 2
                                            %           .                   step 3
                                            %           .                   step n

	eq_step.destination_queue_cells = [];       % [start_cell, stop_cell]       step 1
                                            %           .                   step 2
                                            %           .                   step 3
                                            %           .                   step n

	eq_step.source_target_soc_av = [];          % [src cluster average soc]     step 1
                                            %           .                   step 2
                                            %           .                   step 3
                                            %           .                   step n     

	eq_step.destination_target_soc_av = [];     % [des cluster average soc]     step 1
                                            %           .                   step 2
                                            %           .                   step 3
                                            %           .                   step n  

	else
		eq_step = struct('source_queue_cells', zeros(0,2),...
		'destination_queue_cells', zeros(0,2),...
		'source_target_soc_av', zeros(0,1),...
		'destination_target_soc_av', zeros(0,1));
		max_itteration = 50; % or whatever the maximum value of itteration is

		% Initialize eq_step as an empty structure array with max_itteration elements
		eq_step = repmat(struct('source_queue_cells', zeros(0,2),...
		'destination_queue_cells', zeros(0,2),...
		'source_target_soc_av', zeros(0,1),...
		'destination_target_soc_av', zeros(0,1)), 1, max_itteration);
		
		coder.varsize('eq_step.source_queue_cells', [inf, 2], [1, 0]);
		coder.varsize('eq_step.destination_queue_cells', [inf, 2], [1, 0]);
		coder.varsize('eq_step.source_target_soc_av', [inf, 1], [1, 0]);
		coder.varsize('eq_step.destination_target_soc_av', [inf, 1], [1, 0]);
	end
    
    coder.varsize('soc_profile', [inf, cell_count], [1, 0]); % Variable rows, fixed 9 columns, 0 and 1 shows which one dimension is variable
    soc_profile = NaN(100, cell_count);

   
                                            

lg_time = 0;
lg_inconsistency = 0;
lg_eq_overlap = 0;
persistent max_t_res; % assume eps = 0.1        

% maximum possible values
max_lg_time = 1.5;
max_lg_inconsistency = 100;
max_lg_eq_overlap = 300;


% w_time = 0.8;           % weight for time
% w_inconsistency = 0.2;  % weight for inconsitency
% w_eq_overlap = 0;     % weight for overlap equalization
    

soc = soc_in;
itteration = 0;
soc_transfered_total = 0;
blc_time_total = 0;
soc_profile(itteration + 1, :) = soc;


% clustering
[cluster] = pso_DBSCAN(soc, mp, ep);

while cluster.clt_max_count > 1


    % balancing
    [soc_transfered, soc, blc_time, eq_step(itteration + 1)] = balance_soc(cluster, soc, mp, ep, 2200, 2000);

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

lg_time = blc_time_total;
lg_inconsistency = max(soc) - min(soc);
global no_ovp_plot_flag;

no_ovp_plot_flag = 0;
% summing equalization overlap value of each cell after balancing 
for n = 1:cluster.cell_cnt
    OE = calculate_overlap(soc_profile(:, n)');
    lg_eq_overlap = lg_eq_overlap + OE;
end
no_ovp_plot_flag = 0;

% results
time = lg_time;
inconsistency = lg_inconsistency;
eq_overlap = lg_eq_overlap;

% normalize each component

% calculating maximum time just once
if isempty(max_t_res)
    ep = 0.1;
    [max_t_res, ~, ~, ~] = log_clustering(soc_in, mp, ep);
end

lg_time = lg_time / max_t_res;
lg_inconsistency = lg_inconsistency / max_lg_inconsistency;
lg_eq_overlap = lg_eq_overlap / max_lg_eq_overlap;

% combined cost
cost = w_time * lg_time + w_inconsistency * lg_inconsistency + w_eq_overlap * lg_eq_overlap;

end