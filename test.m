clear;
close all;

% Given SOC data
data = [39, 39, 20, 72, 81, 92, 51, 11, 60]';

% Compute pairwise distances
distances = pdist2(data, data);

% Define k value
k = 3; % Example k value

% Extract k-th nearest neighbor distances for each point
sorted_distances = sort(distances, 2); % Sort distances for each point
k_distances = sorted_distances(:, k + 1); % Extract k-th nearest neighbor distances

% Sort the k-th nearest neighbor distances
sorted_k_distances = sort(k_distances);

% Plot the k-distance graph
figure;
plot(sorted_k_distances, 'b-', 'LineWidth', 2);
title('k-Distance Graph');
xlabel('Points sorted by distance');
ylabel(['Distance to ', num2str(k), '-th Nearest Neighbor']);

% Find the "elbow" point
differences = diff(sorted_k_distances);
[~, idx] = max(differences);
elbow_point = sorted_k_distances(idx);

% Display the chosen epsilon value
fprintf('Chosen epsilon (ε) value: %.2f\n', elbow_point);

% Optionally, plot the differences to visualize the elbow detection
figure;
plot(differences, 'r-', 'LineWidth', 2);
title('Differences in Sorted k-Distances');
xlabel('Index');
ylabel('Difference in k-Distances');

% Mark the elbow point on the k-distance graph
hold on;
plot(idx, elbow_point, 'ro');
legend('k-Distances', 'Elbow Point');
hold off;
