#pragma once
#include<math.h>

#include "mean.h"
#include "ungrouped_data_parameters.h"

float range_of_data(float* sorted_data, int number_of_data_points);
float variance(float* sorted_data, int number_of_data_points);
float standard_deviation(float* sorted_data, int number_of_data_points);
float coefficient_of_variation(float* sorted_data, int number_of_data_points);
float quartile_deviation(float* sorted_data, int number_of_data_points);


dispersion calculate_dispersion(float* sorted_data, int number_of_data_points){
    dispersion dispersion_values;
    dispersion_values.range = range_of_data(sorted_data, number_of_data_points);
    dispersion_values.variance = variance(sorted_data, number_of_data_points);
    dispersion_values.standard_deviation = sqrt(dispersion_values.variance);
    dispersion_values.coefficient_of_variation = dispersion_values.standard_deviation / arithmatic_mean(sorted_data, number_of_data_points);
    dispersion_values.quartile_deviation = quartile_deviation(sorted_data, number_of_data_points);
    return dispersion_values;
}

// function to calculate the range of the data
float range_of_data(float* sorted_data, int number_of_data_points){
    return sorted_data[number_of_data_points - 1] - sorted_data[0];
}

// function to calculate the variance of the data
float variance(float* sorted_data, int number_of_data_points){
    float sum = 0;
    float mean = arithmatic_mean(sorted_data, number_of_data_points);
    for(int i = 0; i < number_of_data_points; i++){
        sum += pow(sorted_data[i] - mean, 2);
    }
    return sum / number_of_data_points;
}

// function to calculate the standard deviation of the data
float standard_deviation(float* sorted_data, int number_of_data_points){
    return sqrt(variance(sorted_data, number_of_data_points));
}

// function to calculate the coefficient of variation of the data
float coefficient_of_variation(float* sorted_data, int number_of_data_points){
    return standard_deviation(sorted_data, number_of_data_points) / arithmatic_mean(sorted_data, number_of_data_points);
}

// function to calculate the quartile deviation of the data
float quartile_deviation(float* sorted_data, int number_of_data_points){
    return (sorted_data[(int)(number_of_data_points / 4)] + sorted_data[(int)(3 * number_of_data_points / 4)]) / 2;
}