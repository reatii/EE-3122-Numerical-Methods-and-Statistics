#pragma once

float* merge(float* array_1, float* array_2, int size_1, int size_2);


float* merge_sort(float* data_points, int number_of_data_points){
    if(number_of_data_points == 1){
        return data_points;
    }
    else {
        int mid = number_of_data_points / 2;
        float* left = merge_sort(data_points, mid);
        float* right = merge_sort(data_points + mid, number_of_data_points - mid);
        return merge(left, right, mid, number_of_data_points - mid);
    }
}


float* merge(float* array_1, float* array_2, int size_1, int size_2){
    float* merged_array = (float*)malloc((size_1 + size_2) * sizeof(float));
    int i = 0, j = 0, k = 0;
    while(i < size_1 && j < size_2){
        if(array_1[i] <= array_2[j]){
            merged_array[k] = array_1[i];
            k++; i++;
        }
        else {
            merged_array[k] = array_2[j];
            k++; j++;
        }
    }
    while(i < size_1){
        merged_array[k] = array_1[i];
        k++; i++;
    }
    while(j < size_2){
        merged_array[k] = array_2[j];
        k++; j++;
    }
    return merged_array;
}