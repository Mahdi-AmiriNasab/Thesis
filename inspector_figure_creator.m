% Extract the timeseries data
soc_ts = out.SOC;
current_ts = out.current;
voltage_ts = out.voltage;

% Font and line settings
font_name = 'Helvetica';
font_size = 22;
line_width = 2.5;
tick_font_size = 18;

% Define legend labels
soc_legend_labels = {'SOC 1', 'SOC 2', 'SOC 3', 'SOC 4', 'SOC 5', 'SOC 6', 'SOC 7', 'SOC 8', 'SOC 9'};
current_legend_labels = {'I1', 'I2', 'I3', 'I4', 'I5', 'I6', 'I7', 'I8', 'I9'};
voltage_legend_labels = {'V1', 'V2', 'V3', 'V4', 'V5', 'V6', 'V7', 'V8', 'V9'};

% Plot SOC
figure;
plot(soc_ts.Time, squeeze(soc_ts.Data), 'LineWidth', line_width);
legend(soc_legend_labels, 'FontName', font_name, 'FontSize', font_size);
xlabel('Time (S)', 'FontName', font_name, 'FontSize', font_size);
ylabel('%SOC', 'FontName', font_name, 'FontSize', font_size);
title('SOC Over Time', 'FontName', font_name, 'FontSize', font_size);
ax = gca;
ax.FontName = font_name;
ax.FontSize = tick_font_size;

% Plot Current
figure;
plot(current_ts.Time, squeeze(current_ts.Data), 'LineWidth', line_width);
legend(current_legend_labels, 'FontName', font_name, 'FontSize', font_size);
xlabel('Time (S)', 'FontName', font_name, 'FontSize', font_size);
ylabel('Current', 'FontName', font_name, 'FontSize', font_size);
title('Current Over Time', 'FontName', font_name, 'FontSize', font_size);
ax = gca;
ax.FontName = font_name;
ax.FontSize = tick_font_size;

% Plot Voltage
figure;
plot(voltage_ts.Time, squeeze(voltage_ts.Data), 'LineWidth', line_width);
legend(voltage_legend_labels, 'FontName', font_name, 'FontSize', font_size);
xlabel('Time (S)', 'FontName', font_name, 'FontSize', font_size);
ylabel('Voltage', 'FontName', font_name, 'FontSize', font_size);
title('Voltage Over Time', 'FontName', font_name, 'FontSize', font_size);
ax = gca;
ax.FontName = font_name;
ax.FontSize = tick_font_size;
