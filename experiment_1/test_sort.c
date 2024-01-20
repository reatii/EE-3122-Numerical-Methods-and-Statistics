#include<stdio.h>
#include<stdlib.h>
#include "quicksort.h"
#include "merge_sort.h"

int main(){
    float arr[] = {10.0, 3.0, 5.0, 9.0 , 1.0, 2.0, 4.0, 8.0, 7.0, 6.0};
    int n = sizeof(arr)/sizeof(arr[0]);
    // quicksort(arr, 0, n-1);
    // float* new_array = merge_sort(arr, 10);
    // for(int i = 0; i < n; i++){
    //     printf("%f ", new_array[i]);
    // }
    // float b[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // float c[] = {0.5, 1, 1.2, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5};
    // float* a = merge(b, c, 5, 11);
    // for(int i = 0; i < 16; i++){
    //     printf("%f ", a[i]);
    // }
    float* merge_sort_array = merge_sort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%f ", merge_sort_array[i]);
    }

    
}