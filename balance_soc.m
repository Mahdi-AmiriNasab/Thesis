function [soc_transfered, soc_out] = balance_soc(clt, soc_in)

	% conditional flag
	soc_mismatch = 1;

	% valid balance range soc
	blc_range = 2;

	% assaign weight to each noise cluster by each cell in it
	% number of elements in noise clusters
	noise_max_clt_cnt = nnz(clt.clt_res_cell(clt.noise_max(1, 1), :));
	noise_min_clt_cnt = nnz(clt.clt_res_cell(clt.noise_min(1, 1), :));

	% calculate soc step to balance
	% assign step = 1 to lower cluster member count
	if noise_min_clt_cnt < noise_max_clt_cnt

		step_noise_max = 1 / noise_max_clt_cnt * noise_min_clt_cnt; 
		step_noise_min = 1;

	else

		step_noise_max = 1;
		step_noise_min = 1 / noise_min_clt_cnt * noise_max_clt_cnt;

	end

	% sorting clt.clt_res_soc_av 
	V = clt.clt_res_soc_av;
	V(V(:,2)==0,2) = Inf;
	clt.clt_res_soc_av = sortrows(V, 2,'ascend');
	clt.clt_res_soc_av(clt.clt_res_soc_av(:,2)==Inf,2) = 0;
	
	% soc sweep initialization
	sweep_max = clt.noise_max(2, 1);
	sweep_min = clt.noise_min(2, 1);
	while soc_mismatch

		% soc sweep
		sweep_max = sweep_max - step_noise_max;
		sweep_min = sweep_min + step_noise_min;

		% update soc data

		%% finding the noise neighbors
		% calculation for noise_max

		% selecting maximum noise to calculate neighbor distances
		clt_number = clt.noise_max(1, 1);        % select the cluster number of the noise


		% pick the neighbor values if neighbors are available in both sides
		% watch for the zero index
		if clt_number - 1 > 0

			% subtract noise value and lower neighbor value
			value_lower_diff_x = abs(clt.clt_res_soc_av(clt_number - 1,1) - sweep_max); 
			% if the differential is within the valid range
			if value_lower_diff_x < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
			end
				
		end
		% watch for the maximum boundaries
		if clt_number + 1 <= clt.clt_max_count

			% subtract noise value and lower neighbor value
			value_higher_diff_x = abs(clt.clt_res_soc_av(clt_number + 1,1) - sweep_max); 
			% if the differential is within the valid range
			if value_higher_diff_x < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
			end
		end

		% selecting minimum noise to calculate neighbor distances
		% calculation for noise_min
		clt_number = clt.noise_min(1, 1);            % select the cluster number of the noise
	
		% pick the neighbor values if neighbors are available in both sides
		% watch for the zero index
		if clt_number - 1 > 0

			% subtract noise value and lower neighbor value
			value_lower_diff_n = abs(clt.clt_res_soc_av(clt_number - 1,1) - sweep_min); 
			% if the differential is within the valid range
			if value_lower_diff_n < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
			end
				
		end
		% watch for the maximum boundaries
		if clt_number + 1 <= clt.clt_max_count

			% subtract noise value and lower neighbor value
			value_higher_diff_n = abs(clt.clt_res_soc_av(clt_number + 1,1) - sweep_min); 
			% if the differential is within the valid range
			if value_higher_diff_n < blc_range 
				soc_mismatch = 0; % the neighbors are balanced
			end
		end

	end


	
% assaign weight to each noise cluster by each cell in it
% number of elements in noise clusters
noise_max_clt_cnt = nnz(clt.clt_res_cell(clt.noise_max(1, 1), :));
noise_min_clt_cnt = nnz(clt.clt_res_cell(clt.noise_min(1, 1), :));


target_clt_soc = [0 0]; % stores the cluster and target soc to reach



%% transfer charges

soc_new = soc_in;

nzi = clt.clt_res_cell(clt.noise_max(1, 1), :);
nzi = nzi(nzi ~= 0);
soc_new(1 ,nzi) = soc_new(1 ,nzi) - abs(clt.noise_max(2, 1) - sweep_max);

nzi = clt.clt_res_cell(clt.noise_min(1, 1), :);
nzi = nzi(nzi ~= 0);
soc_new(1 ,nzi) = soc_new(1 ,nzi) + abs(clt.noise_max(2, 1) - sweep_max);

soc_out = soc_new;
soc_transfered = sweep_max * noise_max_clt_cnt;




end