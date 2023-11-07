function [soc_transfered, soc_out] = balance_soc(clt, soc_in, mp, ep)

	%% init
	soc_out = soc_in;
    soc_transfered_s = 0; soc_transfered_d = 0;
	soc_transfered = 0;
	cell_count = length(soc_in);

	% conditional flag
	soc_mismatch = 1;

	% valid balance range soc
	blc_range = 2;

	% assaign weight to each noise cluster by each cell in it
	% number of elements in noise clusters
	source_clt_cnt = nnz(clt.clt_res_cell(clt.noise_max(1, 1), :));
	destination_clt_cnt = nnz(clt.clt_res_cell(clt.noise_min(1, 1), :));

	% define source and destination clusters
	source_clt = clt.noise_max;
	destination_clt = clt.noise_min;

    % find neighbor cells of each source and destination cell
	% source cluster neighbors
	source_cells = clt.clt_res_cell(source_clt(1, 1), 1:source_clt_cnt);
    source_neighbor_lower_cell = min(source_cells) - 1;
    source_neighbor_upper_cell = max(source_cells) + 1;
	% destination cluster neighbors
	destination_cells = clt.clt_res_cell(destination_clt(1, 1), 1:destination_clt_cnt);
    destination_neighbor_lower_cell = min(destination_cells) - 1;
    destination_neighbor_upper_cell = max(destination_cells) + 1;


	% calculate soc step to balance
	% assign step = 1 to lower cluster member count
	if destination_clt_cnt < source_clt_cnt

		step_source = 1 / source_clt_cnt * destination_clt_cnt; 
		step_destination = 1;

	else

		step_source = 1;
		step_destination = 1 / destination_clt_cnt * source_clt_cnt;

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

		% clustering
		[cluster] = pso_DBSCAN(soc_out, mp, ep);

        % sorting clt.clt_res_soc_av 
	    V = cluster.clt_res_soc_av;
	    V(V(:,2)==0,2) = Inf;
	    cluster.clt_res_soc_av = sortrows(V, 2,'ascend');
	    cluster.clt_res_soc_av(cluster.clt_res_soc_av(:,2)==Inf,2) = 0;
        clear V

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
			end
				
		end
		% watch for the maximum boundaries
		if source_neighbor_upper_cell + 1 <= cell_count

			% subtract noise value and lower neighbor value
			value_higher_diff_s = abs(soc_out(1, source_neighbor_upper_cell) - sweep_source); 
			% if the differential is within the valid range
			if value_higher_diff_s < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
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
			end
				
		end
		% watch for the maximum boundaries
		if destination_neighbor_upper_cell + 1 <= cell_count

			% subtract noise value and lower neighbor value
			value_higher_diff_d = abs(soc_out(1, destination_neighbor_upper_cell) - sweep_destination); 
			% if the differential is within the valid range
			if value_higher_diff_d < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
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

        if(soc_transfered_s ~= soc_transfered_d)
            error("soc transfer mismatch");
        else
            soc_transfered =  soc_transfered_s;
        end

        clear dec inc

	end

end