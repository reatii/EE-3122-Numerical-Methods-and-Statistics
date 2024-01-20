#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ungrouped_data_parameters.h"

#define GEOMETRIC_MEAN_OFFSET 100000 // This offset is used to avoid the problem of fractional numbers when calculating the geometric mean


float arithmatic_mean(float* data_points, int number_of_data_points);
float geometric_mean(float* data_points, int number_of_data_points);
float harmonic_mean(float* data_points, int number_of_data_points);
float weighted_mean(float* data_points, int number_of_data_points);
void print_mean(mean mean_values);

// Calculate and return the struct containing all the mean values
mean calculate_mean(float* data_points, int number_of_data_points){
    mean mean_values;
    mean_values.arithmatic_mean = arithmatic_mean(data_points, number_of_data_points);
    mean_values.geometric_mean = geometric_mean(data_points, number_of_data_points);
    mean_values.harmonic_mean = harmonic_mean(data_points, number_of_data_points);
    mean_values.weighted_mean = weighted_mean(data_points, number_of_data_points);
    return mean_values;
}

// The following function calculates the arithmatic mean of the data points
float arithmatic_mean(float* data_points, int number_of_data_points){
    float sum = 0;
    for(int i = 0; i < number_of_data_points; i++){
        sum += data_points[i];
    }
    return sum / number_of_data_points;
}

// The following function calculates the geometric mean of the data points
float geometric_mean(float* data_points, int number_of_data_points){
    float sum = 0;
    int number_of_negative_data_points = 0;
    for(int i = 0; i < number_of_data_points; i++){
        if(data_points[i] == 0.00000){
            printf("Geometric mean is zero... beacause at least one of the data points is zero\n");
            return 0;
        }
        if(data_points[i] < 0){
            number_of_negative_data_points++;
        }
        sum += log(GEOMETRIC_MEAN_OFFSET * fabs(data_points[i]));
    }
    if(number_of_negative_data_points % 2 == 0){
        return exp(sum / number_of_data_points) / GEOMETRIC_MEAN_OFFSET;
    }
    else{
        return -exp(sum / number_of_data_points - log(GEOMETRIC_MEAN_OFFSET));
    }
}

// The following function calculates the harmonic mean of the data points
float harmonic_mean(float* data_points, int number_of_data_points){
    float sum = 0;
    for(int i = 0; i < number_of_data_points; i++){
        if(data_points[i] == 0){
            printf("Error!... Harmonic mean is not defined... beacause at least one of the data points is zero\n");
            return INFINITY;
        }
        sum += 1 / data_points[i];
    }
    return number_of_data_points / sum;
}

// The following function calculates the weighted mean of the data points
float weighted_mean(float* data_points, int number_of_data_points){
    printf("By default, the weights are assumed to be equal (meaning arithmatic mean = geometric mean)\n");
    char choice;
    printf("Do you want to change the weights? (y/n): ");
    scanf("%c", &choice);
    if(choice == 'y'){
        char weight_file_path[200];
        printf("\nEnter the path of the file containing the weights: ");
        scanf("%s", weight_file_path);
        FILE* weight_file_pointer = fopen(weight_file_path, "r");
        if(weight_file_pointer == NULL){
            printf("Error: File not found\n");
            exit(1);
        }

        int weight_counter = 0;
        float weighted_sum = 0;
        float sum_of_weights = 0;
        float weight;
        while(!feof(weight_file_pointer)){
            fscanf(weight_file_pointer, "%f", &weight);
            sum_of_weights += weight;
            weighted_sum += weight * data_points[weight_counter];
            weight_counter++;
        }
        fclose(weight_file_pointer);
        if (weight_counter-1 != number_of_data_points){
            printf("Number of weights: %d\n", weight_counter-1);
            printf("Error: Number of weights is less than the number of data points\n");
            exit(1);
        }
        return weighted_sum / (number_of_data_points * sum_of_weights);
    }
    if(choice == 'n'){
        return arithmatic_mean(data_points, number_of_data_points);
    }
}

// The following function prints the mean values
void print_mean(mean mean_values){ // mean_values is the struct containing all the mean values
    printf("Arithmatic mean: %f\n", mean_values.arithmatic_mean);
    printf("Geometric mean: %f\n", mean_values.geometric_mean);
    printf("Harmonic mean: %f\n", mean_values.harmonic_mean);
    printf("Weighted mean: %f\n", mean_values.weighted_mean);
}