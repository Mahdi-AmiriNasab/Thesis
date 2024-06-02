function [equalization_overlap] = calculate_overlap(cell_values)

    % Find local maxima (peaks) and minima (valleys)
    is_peak = islocalmax(cell_values);
    is_valley = islocalmin(cell_values);
    
    peak_indices = find(is_peak);
    valley_indices = find(is_valley);

    % Calculate local heights of peaks
    local_heights = zeros(size(peak_indices));
    for i = 1:length(peak_indices)
        left_valleys = valley_indices(valley_indices < peak_indices(i));
        right_valleys = valley_indices(valley_indices > peak_indices(i));
        if isempty(left_valleys)
            left_min = cell_values(1);
        else
            left_min = cell_values(left_valleys(end));
        end
        if isempty(right_valleys)
            right_min = cell_values(end);
        else
            right_min = cell_values(right_valleys(1));
        end
        local_heights(i) = cell_values(peak_indices(i)) - max(left_min, right_min);
    end

    % Calculate local depths of valleys
    local_depths = zeros(size(valley_indices));
    for i = 1:length(valley_indices)
        left_peaks = peak_indices(peak_indices < valley_indices(i));
        right_peaks = peak_indices(peak_indices > valley_indices(i));
        if isempty(left_peaks)
            left_max = cell_values(1);
        else
            left_max = cell_values(left_peaks(end));
        end
        if isempty(right_peaks)
            right_max = cell_values(end);
        else
            right_max = cell_values(right_peaks(1));
        end
        local_depths(i) = min(left_max, right_max) - cell_values(valley_indices(i));
    end

    % Calculate equalization overlap
    equalization_overlap = sum(local_heights) + sum(local_depths);
    
    % Plot cell_values with peaks and valleys highlighted
    global no_ovp_plot_flag;
    if no_ovp_plot_flag == 1
        
        f_ovp = figure;
        plot(cell_values)
        xlim([1 size(cell_values, 2)]);
        ylim([0 100]);
        ylabel('% SOC');
        xlabel('step');
        hold on
        plot(peak_indices, cell_values(peak_indices), 'ro')
        plot(valley_indices, cell_values(valley_indices), 'bo')
        hold off
        close(f_ovp);
        no_ovp_plot_flag = 0;

    end
end




