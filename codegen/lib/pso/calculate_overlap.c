#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Helper function to find local maxima
void find_local_max(const double data[], int size, bool is_peak[]) {
    for (int i = 1; i < size - 1; ++i) {
        if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
            is_peak[i] = true;
        } else {
            is_peak[i] = false;
        }
    }
    is_peak[0] = false;
    is_peak[size - 1] = false;
}

// Helper function to find local minima
void find_local_min(const double data[], int size, bool is_valley[]) {
    for (int i = 1; i < size - 1; ++i) {
        if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
            is_valley[i] = true;
        } else {
            is_valley[i] = false;
        }
    }
    is_valley[0] = false;
    is_valley[size - 1] = false;
}

// Function to calculate overlap
double calculate_overlap(const double cell_values[], int size) {
    bool is_peak[100] = {false};
    bool is_valley[100] = {false};
    int peak_indices[100] = {0};
    int valley_indices[100] = {0};
    double local_heights[100] = {0.0};
    double local_depths[100] = {0.0};
    int peak_count = 0;
    int valley_count = 0;

    find_local_max(cell_values, size, is_peak);
    find_local_min(cell_values, size, is_valley);

    for (int i = 0; i < size; ++i) {
        if (is_peak[i]) {
            peak_indices[peak_count++] = i;
        }
        if (is_valley[i]) {
            valley_indices[valley_count++] = i;
        }
    }

    for (int i = 0; i < peak_count; ++i) {
        int peak_idx = peak_indices[i];
        double left_min = cell_values[0];
        double right_min = cell_values[size - 1];

        for (int j = 0; j < valley_count; ++j) {
            if (valley_indices[j] < peak_idx) {
                left_min = fmin(left_min, cell_values[valley_indices[j]]);
            } else if (valley_indices[j] > peak_idx) {
                right_min = fmin(right_min, cell_values[valley_indices[j]]);
                break;
            }
        }
        local_heights[i] = cell_values[peak_idx] - fmax(left_min, right_min);
    }

    for (int i = 0; i < valley_count; ++i) {
        int valley_idx = valley_indices[i];
        double left_max = cell_values[0];
        double right_max = cell_values[size - 1];

        for (int j = 0; j < peak_count; ++j) {
            if (peak_indices[j] < valley_idx) {
                left_max = fmax(left_max, cell_values[peak_indices[j]]);
            } else if (peak_indices[j] > valley_idx) {
                right_max = fmax(right_max, cell_values[peak_indices[j]]);
                break;
            }
        }
        local_depths[i] = fmin(left_max, right_max) - cell_values[valley_idx];
    }

    double equalization_overlap = 0.0;
    for (int i = 0; i < peak_count; ++i) {
        equalization_overlap += local_heights[i];
    }
    for (int i = 0; i < valley_count; ++i) {
        equalization_overlap += local_depths[i];
    }

    return equalization_overlap;
}

