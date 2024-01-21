#pragma once 
#include "ungrouped_data_parameters.h"

int* calculate_mode(float *sorted_array, int number_of_data_points){
    // mode array is an array of integers which stores the frequency of each data point... if an element of the array is zero, it means that the corresponding data point has already been counted
    int* mode_array = (int*)calloc(number_of_data_points, sizeof(int));
    float current_data_point = sorted_array[0];
    int i = 0, j = 0;
    while(i < number_of_data_points){
        while(i < number_of_data_points && sorted_array[i] == current_data_point){
            mode_array[j]++;
            i++;
        }
        current_data_point = sorted_array[i];
        j = i;                                                                             
    }
    return mode_array;
}