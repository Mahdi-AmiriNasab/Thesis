% Extract the timeseries data
soc_ts = out.SOC;
current_ts = out.current;
voltage_ts = out.voltage;

% Font and line settings
font_name = 'Helvetica';
font_size = 22;
line_width = 2.5;
tick_font_size = 18;

% Define a set of line styles and markers
lineStyles = {'-', '--', ':', '-.', '-', '--', ':', '-.', '-'};
markers = {'o', '+', '*', '.', 'x', 's', 'd', '^', 'v'};
colors = lines(9); % Generate distinct colors for each line
current_legend_labels = {'I1', 'I2', 'I3', 'I4', 'I5', 'I6', 'I7', 'I8', 'I9'};
voltage_legend_labels = {'V1', 'V2', 'V3', 'V4', 'V5', 'V6', 'V7', 'V8', 'V9'};

% Marker plotting interval
markerInterval = 2500; % Plot markers at every 2500th data point

% Modify the time axis (e.g., scale it)
time_scale_factor = 2; % Adjust this factor to stretch or compress the time axis
new_time = soc_ts.Time * time_scale_factor; % Stretching the time axis by a factor of 2

% Plot SOC with modified time axis
figure;
hold on;
for i = 1:9
    plot(new_time, squeeze(soc_ts.Data(1,i,:)), 'LineWidth', line_width, ...
        'LineStyle', lineStyles{i}, 'Marker', markers{i}, 'Color', colors(i,:), ...
        'MarkerIndices', 1:markerInterval:length(new_time));
end
legend({'SOC 1', 'SOC 2', 'SOC 3', 'SOC 4', 'SOC 5', 'SOC 6', 'SOC 7', 'SOC 8', 'SOC 9'}, 'FontName', font_name, 'FontSize', font_size);
xlabel('Time (S)', 'FontName', font_name, 'FontSize', font_size);
ylabel('%SOC', 'FontName', font_name, 'FontSize', font_size);
title('SOC Over Modified Time Axis', 'FontName', font_name, 'FontSize', font_size);
ax = gca;
ax.FontName = font_name;
ax.FontSize = tick_font_size;
hold off;

% Plot Current with modified time axis
figure;
plot(new_time, squeeze(current_ts.Data), 'LineWidth', line_width);
legend(current_legend_labels, 'FontName', font_name, 'FontSize', font_size);
xlabel('Time (S)', 'FontName', font_name, 'FontSize', font_size);
ylabel('Current', 'FontName', font_name, 'FontSize', font_size);
title('Current Over Modified Time Axis', 'FontName', font_name, 'FontSize', font_size);
ax = gca;
ax.FontName = font_name;
ax.FontSize = tick_font_size;

% Plot Voltage with modified time axis
figure;
plot(new_time, squeeze(voltage_ts.Data), 'LineWidth', line_width);
legend(voltage_legend_labels, 'FontName', font_name, 'FontSize', font_size);
xlabel('Time (S)', 'FontName', font_name, 'FontSize', font_size);
ylabel('Voltage', 'FontName', font_name, 'FontSize', font_size);
title('Voltage Over Modified Time Axis', 'FontName', font_name, 'FontSize', font_size);
ax = gca;
ax.FontName = font_name;
ax.FontSize = tick_font_size;
