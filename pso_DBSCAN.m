
function [cluster] = pso_DBSCAN(socs, minPts, eps)
%% initialization
cell_cnt = length(socs);
cluster.cell_cnt = length(socs);
%socs = fix(rand (1, cell_cnt) * 100);
% eps = 10;
% minPts = 3;
%% clustering
cluster.average = fix(mean(socs));
error = [(1:cell_cnt); socs - repmat(cluster.average, 1, cell_cnt)];

dbscan_res_clm = dbscan(error(2, :)', eps, minPts);
%data_cluster = [error(2, :); dbscan_res_clm'];

% finding adjacent clusters
s_index = 1;                        % stores cluster indices
s_column = 1;                       % stores number of each cells in the cluster
av_index = 1;                       % stores the index average of each cluster
cluster.dbscan_res = dbscan_res_clm';
cluster.clt_res_cell = zeros(cell_cnt, cell_cnt);   % init maximum number of clusters containig cell indices
cluster.clt_res_soc = zeros(cell_cnt, cell_cnt);    % init maximum number of clusters containig cell socs
cluster.clt_res_soc_av = zeros(cell_cnt, 2);        % init maximum number of clusters containig cell socs
for n = 1:cell_cnt

    if (cluster.clt_res_cell(s_index, s_column) == 0)
        cluster.clt_res_cell(s_index, s_column) = n;
        cluster.clt_res_soc(s_index, s_column) = socs(1, n);
    else
        % find simularities whilest the data is not noise
        if(cluster.dbscan_res(1, n) == cluster.dbscan_res(1, n-1) && cluster.dbscan_res(1, n) ~= -1) 
            s_column = s_column + 1; 
            cluster.clt_res_cell(s_index, s_column) = n;
            cluster.clt_res_soc(s_index, s_column) = socs(1, n);
        else
            % update the cluster index if no similarities found
            s_column = 1;           
            s_index = s_index + 1;
            cluster.clt_res_cell(s_index, s_column) = n;
            cluster.clt_res_soc(s_index, s_column) = socs(1, n);
        end
    end
    % calculating average of each cluster
    mn_tmp = mean(nonzeros(cluster.clt_res_soc(s_index, :)));
    if(~isnan(mn_tmp))
        cluster.clt_res_soc_av(s_index, 1) = fix(mn_tmp);
        cluster.clt_res_soc_av(s_index, 2) = s_index;
    end

end

% sorting
cluster.clt_res_soc_av = sortrows(cluster.clt_res_soc_av, 1, 'descend');

cluster.clt_max_count = max(cluster.clt_res_soc_av(:, 2));

%% finding noises

s_column = 1;
c_column = 1;
cluster.clt_noise_soc = zeros (2, cell_cnt);        % to store noise vs soc
cluster.clt_soc = zeros (2, cell_cnt);      % to store cluster vs average soc
for n = 1:cell_cnt

    if cluster.clt_res_cell(n , 1) ~= 0         % noise detected
        if (cluster.clt_res_cell(n, 2) == 0)
            cluster.clt_noise_soc(1, s_column) = n;%cluster.clt_res_cell(n, 1);
            cluster.clt_noise_soc(2, s_column) = socs(1, cluster.clt_res_cell(n, 1));
            s_column = s_column + 1;
        else    %cluster detected
            cluster.clt_soc(1, c_column) = n;
            % find the corresponding soc of the index (n)
            found_index = find(cluster.clt_res_soc_av(:, 2) == n);
            % check if the found_index is not empty
            if ~isempty(found_index)
                cluster.clt_soc(2, c_column) = cluster.clt_res_soc_av(found_index(1, 1) ,1);
            end
            c_column = c_column + 1;
        end
        
    end
end

cluster.noise_max = [0; 0];
cluster.noise_min = [0; 0];
cluster.single_noise = [0; 0];

% if no single noise found
if all(cluster.clt_noise_soc == 0)
	cluster.noise_status = e_noise_stat.noise_not_found;
    % minimum cluster as noise
    non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0;
    cluster.noise_min(2, 1) = min(cluster.clt_res_soc_av(non_zero_indices, 1));
    tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_min(2, 1));
    cluster.noise_min(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2);

    % maximum cluster as noise
    non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0;
    cluster.noise_max(2, 1) = max(cluster.clt_res_soc_av(non_zero_indices, 1));
    tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_max(2, 1));
    cluster.noise_max(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2);

% if just one noise found
elseif nnz(cluster.clt_noise_soc(2, :)) == 1

	cluster.noise_status = e_noise_stat.noise_single_found;

	single_noise = cluster.clt_noise_soc(:, 1);
	search_indices = 1 : cell_cnt;
	if single_noise(2, 1) > cluster.average

		% maximum single noise
		cluster.noise_max = single_noise;

		% minimum cluster as noise
		non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0;
		cluster.noise_min(2, 1) = min(cluster.clt_res_soc_av(non_zero_indices, 1));
		tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_min(2, 1));
		cluster.noise_min(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2);
		
	else

		% maximum cluster as noise
		non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0;
		cluster.noise_max(2, 1) = max(cluster.clt_res_soc_av(non_zero_indices, 1));
		tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_max(2, 1));
		cluster.noise_max(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2);

		% minimum single noise
		cluster.noise_min = single_noise;
		
	end

% if several noises available
else
    
	cluster.noise_status = e_noise_stat.noise_found;
    % indice to clear the noise cluster
    indice_to_clear = 0;

    clt_noise_soc_cpy = cluster.clt_noise_soc;
    
    % minimum niose
    non_zero_indices =  clt_noise_soc_cpy(1, :) ~= 0;
    [cluster.noise_min(2, 1), indice_to_clear] = min( clt_noise_soc_cpy(2, non_zero_indices));
    %tmp = find( clt_noise_soc_cpy(2, non_zero_indices) == cluster.noise_min(2, 1));
    cluster.noise_min =  clt_noise_soc_cpy(:, indice_to_clear);
    

    % clear the picked noise as minimum to avoid repeated selection
    clt_noise_soc_cpy(1, indice_to_clear) = -1;
    clt_noise_soc_cpy(2, indice_to_clear) = -1;
    

    % maximum niose
    [cluster.noise_max(2, 1), indice_to_clear] = max( clt_noise_soc_cpy(2, non_zero_indices));
    %tmp = find( clt_noise_soc_cpy(2, non_zero_indices) == cluster.noise_max(2, 1));
    cluster.noise_max =  clt_noise_soc_cpy(:, indice_to_clear);
   

    clear tmp clt_noise_soc_cpy non_zero_indices

end


end