function visualization(soc ,cluster)
	
cell_count = length(soc);


%% vizualization

    vis = [];
    
    for i = 1:size(cluster.clt_res_cell ,1)
        nonZeroIndices = find(cluster.clt_res_cell(i,:));
        vis = [vis; repmat(i, length(nonZeroIndices), 1)];
    end
    
    clustering_v= vis + 2;  % Adjust cluster indices for visualization
    
    num_clusters = length(unique(clustering_v));  % Get the number of unique elements in clustering_v
    my_colormap = hsv(num_clusters);  % Generate a colormap with num_clusters colors
    unique_clusters = unique(clustering_v);
    color_map = containers.Map('KeyType', 'double', 'ValueType', 'any');
    for i = 1:num_clusters
        color_map(unique_clusters(i)) = my_colormap(i, :);
    end
    color_v = zeros(length(clustering_v), 3);  % Initialize color_v
    for i = 1:length(clustering_v)
        color_v(i, :) = color_map(clustering_v(i));
    end
    
    scatter(1:length(soc'), soc', 100, clustering_v', 'filled');
    yline(cluster.average, '-', 'cluster.average');
    
    xlim([1 cell_count]); ylim([0 100]);

end