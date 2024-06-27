function [soc_transfered, soc_out, blc_time, eq_step] = balance_soc(cluster, soc_in, mp, ep, capacity, blc_current)

	%% init
	blc_time = 0;
	blc_range = ep;
	soc_out = soc_in;
    soc_transfered_s = 0; soc_transfered_d = 0;
	soc_transfered = 0;
	cell_count = length(soc_in);

	% equalization steps storage
	eq_step.source_queue_cells = [0, 0];		% [start_cell, stop_cell]

	eq_step.destination_queue_cells = [0, 0];	% [start_cell, stop_cell]       

	eq_step.source_target_soc_av = 0;    		% [src cluster average soc]  

	eq_step.destination_target_soc_av = 0; 		% [des cluster average soc]

    soc_diff_s = 0; % Initialize soc_diff_s
    soc_diff_d = 0; % Initialize soc_diff_d

	% validity of source/destination cluster neighbors (valid by default)
	snlc_validity = 1;
	snuc_validity = 1;

	dnlc_validity = 1;
	dnuc_validity = 1;

	% conditional flag
	soc_mismatch = 1;

	% valid balance range soc
	%blc_range = 2;

	% assaign weight to each noise cluster by each cell in it
	% number of elements in noise clusters
	source_clt_cnt = nnz(cluster.clt_res_cell(cluster.noise_max(1, 1), :));
	destination_clt_cnt = nnz(cluster.clt_res_cell(cluster.noise_min(1, 1), :));

	%% define source and destination clusters
	source_clt = cluster.noise_max;
	destination_clt = cluster.noise_min;

    % find neighbor cells of each source and destination cell
	% source cluster neighbors
	source_cells = cluster.clt_res_cell(source_clt(1, 1), 1:source_clt_cnt);

	source_neighbor_lower_cell = min(source_cells) - 1;
	
	% the source cell must have a lower value neighbor
	% check the validity of lower cell
	if source_neighbor_lower_cell  > 0
		if soc_out(1, source_neighbor_lower_cell) < source_clt(2 ,1)
			snlc_validity = 1;
		else
			snlc_validity = 0;
        end
	else
		snlc_validity = 0;
	end

	source_neighbor_upper_cell = max(source_cells) + 1;

	% check the validity of upper cell
	if source_neighbor_upper_cell <= cell_count
		if soc_out(1, source_neighbor_upper_cell) < source_clt(2 ,1)
			snuc_validity = 1;
		else
			snuc_validity = 0;
        end
	else
		snuc_validity = 0;
	end

	% check if any valid neighbor found
	if snlc_validity || snuc_validity
		% we are good
	else
		% select a source cluster with valid neighbors

		% sorting
		soc_sorted_clusters = sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2, 'ascend');
	    % pick the maximum soc cluster regarding noise 
		[source_clt(2, 1), source_clt(1, 1)] = max(soc_sorted_clusters([1:cluster.clt_max_count]', 1));

		% number of elements in the clusters
		source_clt_cnt = nnz(cluster.clt_res_cell(source_clt(1, 1), :));

		% source cluster neighbors
		source_cells = cluster.clt_res_cell(source_clt(1, 1), 1:source_clt_cnt);
		source_neighbor_lower_cell = min(source_cells) - 1;
		source_neighbor_upper_cell = max(source_cells) + 1;

    end

	% destination cluster neighbors
	destination_cells = cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt);

	destination_neighbor_lower_cell = min(destination_cells) - 1;

	% the destination cell must have a lower value neighbor
	% check the validity of lower cell
	if destination_neighbor_lower_cell  > 0
		if soc_out(1, destination_neighbor_lower_cell) > destination_clt(2 ,1)
			dnlc_validity = 1;
		else
			dnlc_validity = 0;
        end
	else
		dnlc_validity = 0;
	end
	
	destination_neighbor_upper_cell = max(destination_cells) + 1;

	% check the validity of upper cell
	if destination_neighbor_upper_cell <= cell_count
		if soc_out(1, destination_neighbor_upper_cell) > destination_clt(2 ,1)
			dnuc_validity = 1;
		else
			dnuc_validity = 0;
		end
	else
		dnuc_validity = 0;
	end

	% check if any valid neighbor found
	if dnlc_validity || dnuc_validity
		% we are good
	else
		% select a destination cluster with valid neighbors

		% sorting
		soc_sorted_clusters = sortrows(cluster.clt_res_soc_av(1:cluster.clt_max_count,:), 2, 'ascend');
		% pick the minimum soc cluster regarding noise 
		[destination_clt(2, 1), destination_clt(1, 1)] = min(soc_sorted_clusters([1:cluster.clt_max_count]', 1));

		% number of elements in the clusters
		destination_clt_cnt = nnz(cluster.clt_res_cell(destination_clt(1, 1), :));

		% destination cluster neighbors
		destination_cells = cluster.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt);
		destination_neighbor_lower_cell = min(destination_cells) - 1;
		destination_neighbor_upper_cell = max(destination_cells) + 1;
		
	end

	% store source and destination clusters
	eq_step.source_queue_cells = [source_neighbor_lower_cell + 1, source_neighbor_upper_cell - 1];
	eq_step.destination_queue_cells = [destination_neighbor_lower_cell + 1, destination_neighbor_upper_cell - 1];
	 
	%% calculate soc step to balance
	% assign step = 1 to lower cluster member count
	if destination_clt_cnt < source_clt_cnt

		step_source = (blc_range/2) / source_clt_cnt * destination_clt_cnt; 
		step_destination = (blc_range/2);

	else

		step_source = (blc_range/2);
		step_destination = (blc_range/2) / destination_clt_cnt * source_clt_cnt;

	end

	
	
	% soc sweep initialization
	sweep_source = source_clt(2, 1);
	sweep_destination = destination_clt(2, 1);

	% calculation for noise_max
	% selecting maximum noise to calculate neighbor distances
	clt_number_max = source_clt(1, 1);
	clt_number_min = destination_clt(1, 1);

	noise_max_pre = source_clt;
	noise_min_pre = destination_clt;


	%% equalizing

	while soc_mismatch

		% % clustering
		% [cluster] = pso_DBSCAN(soc_out, mp, ep);

        % % sorting cluster.clt_res_soc_av 
	    % V = cluster.clt_res_soc_av;
	    % V(V(:,2)==0,2) = Inf;
	    % cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
	    % cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;
        % clear V

		% soc sweep
		sweep_source = sweep_source - step_source;
		sweep_destination = sweep_destination + step_destination;

		
		% pick the neighbor values if neighbors are available in both sides
		% watch for the zero index
		if source_neighbor_lower_cell - 1 > 0

			% subtract noise value and lower neighbor value
			value_lower_diff_s = abs(soc_out(1, source_neighbor_lower_cell) - sweep_source); 
			% if the differential is within the valid range
			if value_lower_diff_s < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
				eq_step.source_target_soc_av = sweep_source;	% store the target soc of neighbors
			end
				
		end
		% watch for the maximum boundaries
		if source_neighbor_upper_cell + 1 <= cell_count

			% subtract noise value and lower neighbor value
			value_higher_diff_s = abs(soc_out(1, source_neighbor_upper_cell) - sweep_source); 
			% if the differential is within the valid range
			if value_higher_diff_s < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
				eq_step.source_target_soc_av = sweep_source;	% store the target soc of neighbors
			end
		end


	
		% pick the neighbor values if neighbors are available in both sides
		% watch for the zero index
		if destination_neighbor_lower_cell - 1 > 0

			% subtract noise value and lower neighbor value
			value_lower_diff_d = abs(soc_out(1, destination_neighbor_lower_cell) - sweep_destination); 
			% if the differential is within the valid range
			if value_lower_diff_d < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
				eq_step.destination_target_soc_av = sweep_destination;	% store the target soc of neighbors
			end
				
		end
		% watch for the maximum boundaries
		if destination_neighbor_upper_cell + 1 <= cell_count

			% subtract noise value and lower neighbor value
			value_higher_diff_d = abs(soc_out(1, destination_neighbor_upper_cell) - sweep_destination); 
			% if the differential is within the valid range
			if value_higher_diff_d < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
				eq_step.destination_target_soc_av = sweep_destination; % store the target soc of neighbors	
			end
		end

		% transfer charges

		soc_new = soc_out;

		% calculate amount of increment and decreament after each sweep
		inc = step_source;
		soc_new(1 ,source_cells) = soc_new(1 ,source_cells) - inc;
		
		dec = step_destination;
		soc_new(1 ,destination_cells) = soc_new(1 ,destination_cells) + dec;	

		soc_out = soc_new;

        % increament/decreament soc calculation (both are equal)
		soc_transfered_s = soc_transfered_s + inc * source_clt_cnt;
        soc_transfered_d = soc_transfered_d + dec * destination_clt_cnt;
		% round to avoid unwanted mismatch
		
		%#codegen
		if coder.target('MATLAB')
			% This code will only be executed in the MATLAB environment
			soc_transfered_s = round(soc_transfered_s, 2);
			soc_transfered_d = round(soc_transfered_d, 2);
		else
			soc_transfered_s = round(soc_transfered_s * 100) / 100;
			soc_transfered_d = round(soc_transfered_d * 100) / 100;
		end

        
        if(soc_transfered_s ~= soc_transfered_d)
            error("soc transfer mismatch");
        else
			soc_transfered =  soc_transfered_s;
			soc_diff_s = soc_transfered_s / source_clt_cnt; % single cell soc transfer
			soc_diff_d = soc_transfered_d / destination_clt_cnt; % single cell  soc transfer
		end
				
        if sweep_destination > 100 || sweep_destination < 0 ...
            || sweep_source > 100 || sweep_source < 0
           error("soc sweep limit exceed");
        end
        
        if coder.target('MATLAB')
            clear dec inc
        end
	end

		%% calculate balancing time
		source_batt_number = source_clt_cnt;
		destination_batt_number = destination_clt_cnt;
        
	
		
		% calculate balancing current
		if (source_batt_number > destination_batt_number)
			blc_current_actual = ((destination_batt_number / source_batt_number)/3 + 1/6) * blc_current;
            cap_diff = soc_diff_s / 100 * capacity; % calculate transfered capacity for source
		elseif source_batt_number < destination_batt_number
            cap_diff = soc_diff_d / 100 * capacity; % calculate transfered capacity for source
			blc_current_actual = ((source_batt_number / destination_batt_number)/3 + 1/6) * blc_current;
		else
			blc_current_actual = ((1)/3 + 1/6) * blc_current;
             cap_diff = soc_diff_s / 100 * capacity; % calculate transfered capacity for source
		end

		% calculate the final balancing time (hour)
		blc_time = cap_diff / blc_current_actual;

		% convert to seconds
		blc_time = blc_time * 60 * 60;


end