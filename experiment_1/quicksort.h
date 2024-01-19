#pragma once

int partition(float* data_points, int left, int right);
void swap(float* n1, float* n2);




void quicksort(float* data_points, int left, int right){
    if (left < right){
        int j = partition(data_points, left, right);
        quicksort(data_points, left, j);
        quicksort(data_points, j + 1, right);
    }
}

int partition(float* data_points, int left, int right){
    float pivot = data_points[left];
    int i = left;
    int j = right;

    while(i < j){
        while(i < right && data_points[i] <= pivot){
            i++;
        }
        while(j > left && data_points[j] > pivot){
            j--;
        }
        if(i < j){
            swap(&data_points[i], &data_points[j]);
        }
    }
    swap(&data_points[left], &data_points[j]);
    return j;
}

void swap(float* n1, float* n2){
    float temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}