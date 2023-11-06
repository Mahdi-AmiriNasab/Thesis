
function [clt] = pso_DBSCAN(socs, minPts, eps)
%% initialization
cell_cnt = length(socs);
%socs = fix(rand (1, cell_cnt) * 100);
% eps = 10;
% minPts = 3;
%% clustering
clt.average = fix(mean(socs));
error = [(1:cell_cnt); socs - repmat(clt.average, 1, cell_cnt)];

dbscan_res_clm = dbscan(error(2, :)', eps, minPts);
%data_cluster = [error(2, :); dbscan_res_clm'];

% finding adjacent clusters
s_index = 1;                        % stores cluster indices
s_column = 1;                       % stores number of each cells in the cluster
av_index = 1;                       % stores the index average of each cluster
clt.dbscan_res = dbscan_res_clm';
clt.clt_res_cell = zeros(cell_cnt, cell_cnt);   % init maximum number of clusters containig cell indices
clt.clt_res_soc = zeros(cell_cnt, cell_cnt);    % init maximum number of clusters containig cell socs
clt.clt_res_soc_av = zeros(cell_cnt, 2);        % init maximum number of clusters containig cell socs
for n = 1:cell_cnt

    if (clt.clt_res_cell(s_index, s_column) == 0)
        clt.clt_res_cell(s_index, s_column) = n;
        clt.clt_res_soc(s_index, s_column) = socs(1, n);
    else
        % find simularities whilest the data is not noise
        if(clt.dbscan_res(1, n) == clt.dbscan_res(1, n-1) && clt.dbscan_res(1, n) ~= -1) 
            s_column = s_column + 1; 
            clt.clt_res_cell(s_index, s_column) = n;
            clt.clt_res_soc(s_index, s_column) = socs(1, n);
        else
            % update the cluster index if no similarities found
            s_column = 1;           
            s_index = s_index + 1;
            clt.clt_res_cell(s_index, s_column) = n;
            clt.clt_res_soc(s_index, s_column) = socs(1, n);
        end
    end
    % calculating average of each cluster
    mn_tmp = mean(nonzeros(clt.clt_res_soc(s_index, :)));
    if(~isnan(mn_tmp))
        clt.clt_res_soc_av(s_index, 1) = fix(mn_tmp);
        clt.clt_res_soc_av(s_index, 2) = s_index;
    end

end

% sorting
clt.clt_res_soc_av = sortrows(clt.clt_res_soc_av, 1, 'descend');

%% finding noises

s_column = 1;
c_column = 1;
clt.clt_noise_soc = zeros (2, cell_cnt);        % to store noise vs soc
clt.clt_soc = zeros (2, cell_cnt);      % to store cluster vs average soc
for n = 1:cell_cnt

    if clt.clt_res_cell(n , 1) ~= 0         % noise detected
        if (clt.clt_res_cell(n, 2) == 0)
            clt.clt_noise_soc(1, s_column) = n;%clt.clt_res_cell(n, 1);
            clt.clt_noise_soc(2, s_column) = socs(1, clt.clt_res_cell(n, 1));
            s_column = s_column + 1;
        else    %cluster detected
            clt.clt_soc(1, c_column) = n;
            % find the corresponding soc of the index (n)
            found_index = find(clt.clt_res_soc_av(:, 2) == n);
            % check if the found_index is not empty
            if ~isempty(found_index)
                clt.clt_soc(2, c_column) = clt.clt_res_soc_av(found_index(1, 1) ,1);
            end
            c_column = c_column + 1;
        end
        
    end
end

clt.noise_max = [0; 0];
clt.noise_min = [0; 0];
clt.single_noise = [0; 0];

% if no single noise found
if all(clt.clt_noise_soc(2, :) == 0)
	clt.noise_status = e_noise_stat.noise_not_found;
    % minimum cluster as noise
    non_zero_indices = clt.clt_res_soc_av(:, 1) ~= 0;
    clt.noise_min(2, 1) = min(clt.clt_res_soc_av(non_zero_indices, 1));
    tmp = find(clt.clt_res_soc_av(:, 1) == clt.noise_min(2, 1));
    clt.noise_min(1, 1) = clt.clt_res_soc_av(tmp(1, 1), 2);

    % maximum cluster as noise
    non_zero_indices = clt.clt_res_soc_av(:, 1) ~= 0;
    clt.noise_max(2, 1) = max(clt.clt_res_soc_av(non_zero_indices, 1));
    tmp = find(clt.clt_res_soc_av(:, 1) == clt.noise_max(2, 1));
    clt.noise_max(1, 1) = clt.clt_res_soc_av(tmp(1, 1), 2);

% if just one noise found
elseif nnz(clt.clt_noise_soc(2, :)) == 1

	clt.noise_status = e_noise_stat.noise_single_found;

	single_noise = clt.clt_noise_soc(:, 1);
	search_indices = 1 : cell_cnt;
	if single_noise(2, 1) > clt.average

		% maximum single noise
		clt.noise_max = single_noise;

		% minimum cluster as noise
		non_zero_indices = clt.clt_res_soc_av(:, 1) ~= 0;
		clt.noise_min(2, 1) = min(clt.clt_res_soc_av(non_zero_indices, 1));
		tmp = find(clt.clt_res_soc_av(:, 1) == clt.noise_min(2, 1));
		clt.noise_min(1, 1) = clt.clt_res_soc_av(tmp(1, 1), 2);
		
	else

		% maximum cluster as noise
		non_zero_indices = clt.clt_res_soc_av(:, 1) ~= 0;
		clt.noise_max(2, 1) = max(clt.clt_res_soc_av(non_zero_indices, 1));
		tmp = find(clt.clt_res_soc_av(:, 1) == clt.noise_max(2, 1));
		clt.noise_max(1, 1) = clt.clt_res_soc_av(tmp(1, 1), 2);

		% minimum single noise
		clt.noise_min = single_noise;
		
	end

		% single_noise = clt.clt_noise_soc;
	% search_indices = 1 : cell_cnt;
	% search_indices(1, single_noise(1, 1)) = 0; % clear the noise indice to exit search scope
	% search_indices = find(search_indices > 0);
    
    % % indices sorting basis just to perform the operation
    % V = clt.clt_res_soc_av;
    % V(V(:,2)==0,2) = Inf;
    % clt.clt_res_soc_av = sortrows(V, 2,'ascend');
    % clt.clt_res_soc_av(clt.clt_res_soc_av(:,2)==Inf,2) = 0;
    
    % % if any greater noise cluster NOT found 
    % if max(clt.clt_res_soc_av(search_indices', 1)) < single_noise(2 ,1)
		
    %     % maximum single noise
    %     clt.noise_max = single_noise(:, 1);

    %     % minimum cluster as noise
    %     non_zero_indices = clt.clt_res_soc_av(:, 1) ~= 0;
    %     clt.noise_min(2, 1) = min(clt.clt_res_soc_av(non_zero_indices, 1));
    %     tmp = find(clt.clt_res_soc_av(:, 1) == clt.noise_min(2, 1));
    %     clt.noise_min(1, 1) = clt.clt_res_soc_av(tmp(1, 1), 2);
    % else
    %     % maximum cluster as noise
    %     a = max(clt.clt_res_soc_av(search_indices', :))';
    %     clt.noise_max(1, 1) = a(2, 1);
    %     clt.noise_max(2, 1) = a(1, 1);
        
    %     % minimum single noise
    %     clt.noise_min = single_noise(:, 1);
    % end

    % clear V a non_zero_indices;

    % % revese sorting after the operation
    % clt.clt_res_soc_av = sortrows(clt.clt_res_soc_av, 1, 'descend');

% if several noises available
else

	clt.noise_status = e_noise_stat.noise_found;

    % minimum niose
    non_zero_indices = clt.clt_noise_soc(2, :) ~= 0;
    clt.noise_min(2, 1) = min(clt.clt_noise_soc(2, non_zero_indices));
    tmp = find(clt.clt_noise_soc(2, :) == clt.noise_min(2, 1));
    clt.noise_min = clt.clt_noise_soc(:, tmp(1, 1));
    
    % maximum niose
    clt.noise_max(2, 1) = max(clt.clt_noise_soc(2, :));
    tmp = find(clt.clt_noise_soc(2, :) == clt.noise_max(2, 1));
    clt.noise_max = clt.clt_noise_soc(:, tmp(1, 1));

end

clt.clt_max_count = max(clt.clt_res_soc_av(:, 2));

end