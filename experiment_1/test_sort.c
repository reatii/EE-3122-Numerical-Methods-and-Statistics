#include<stdio.h>
#include<stdlib.h>
#include "quicksort.h"

int main(){
    float arr[] = {10.0, 3.0, 5.0, 9.0 , 1.0, 2.0, 4.0, 8.0, 7.0, 6.0};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%f ", arr[i]);
    }

    
}