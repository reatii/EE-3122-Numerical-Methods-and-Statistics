#pragma once
#include<math.h>

#include "ungrouped_data_parameters.h"
#include "dispersion_measures.h"
#include "mean.h"

float moment_about_a_point(float* sorted_data, int number_of_data_points);
float moment_about_mean(float* sorted_data, int number_of_data_points, int order_of_moment);


// function to calclulate the shape values
shape calculate_shape(float* sorted_data, int number_of_data_points){
    shape shape_values;
    shape_values.moment_information.first_moment = moment_about_mean(sorted_data, number_of_data_points, 1);
    shape_values.moment_information.second_moment = moment_about_mean(sorted_data, number_of_data_points, 2);
    shape_values.moment_information.third_moment = moment_about_mean(sorted_data, number_of_data_points, 3);
    shape_values.moment_information.fourth_moment = moment_about_mean(sorted_data, number_of_data_points, 4);
    shape_values.skewness = shape_values.moment_information.third_moment / pow(shape_values.moment_information.second_moment, 1.5);
    shape_values.kurtosis = shape_values.moment_information.fourth_moment / pow(shape_values.moment_information.second_moment, 2);
    return shape_values;
}


// function to calculate the nth moment about a point of the data
float moment_about_a_point(float* sorted_data, int number_of_data_points){
    printf("Do you want to calculate the moment about a point or about the mean (y/n)?\n");
    char moment_choice;
    printf("Enter your choice: ");
    scanf(" %c", &moment_choice);
    printf("\n");
    float point;
    if (moment_choice == 'y'){
        point = arithmatic_mean(sorted_data, number_of_data_points);
    }
    else{
        printf("Enter the point about which you want to calculate the moment: ");
        scanf("%f", &point);
    }
    printf("\nEnter the order of the moment: ");
    int order_of_moment;
    scanf("%d", &order_of_moment);
    printf("\n");
    
    float sum = 0;
    for(int i = 0; i < number_of_data_points; i++){
        sum += pow(sorted_data[i] - point, order_of_moment);
    }
    return sum / number_of_data_points;
}

// function to calculate the nth moment about the mean of the data
float moment_about_mean(float* sorted_data, int number_of_data_points, int order_of_moment){
    float mean_value = arithmatic_mean(sorted_data, number_of_data_points);
    float sum = 0;
    for(int i = 0; i < number_of_data_points; i++){
        sum += pow(sorted_data[i] - mean_value, order_of_moment);
    }
    return sum / number_of_data_points;
}
