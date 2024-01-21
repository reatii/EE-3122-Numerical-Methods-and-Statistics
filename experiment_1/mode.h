#pragma once 
#include "ungrouped_data_parameters.h"

float calculate_mode(float* sorted_data, int number_of_data_points){
    int* frequency_array = (int*)calloc(number_of_data_points, sizeof(int));
    int frequency = 0;
    int max_frequency = 0;
    int mode = 0;
    for(int i = 0; i < number_of_data_points; i++){
        frequency_array[i] = 1;
        for(int j = i + 1; j < number_of_data_points; j++){
            if(sorted_data[i] == sorted_data[j]){
                frequency_array[i]++;
            }
        }
    }
    for(int i = 0; i < number_of_data_points; i++){
        if(frequency_array[i] > max_frequency){
            max_frequency = frequency_array[i];
            mode = sorted_data[i];
        }
    }
    return mode;
}