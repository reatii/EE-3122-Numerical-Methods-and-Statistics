#pragma once

float calculate_median(float* sorted_data, int number_of_data_points){
    if(number_of_data_points % 2 == 0){
        return (sorted_data[number_of_data_points / 2] + sorted_data[number_of_data_points / 2 - 1]) / 2;
    }
    else{
        return sorted_data[number_of_data_points / 2];
    }
}