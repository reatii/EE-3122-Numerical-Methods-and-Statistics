#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ungrouped_data_parameters.h"
#include "load_ungrouped_data_from_txt_file_into_an_array.h"
#include "mean.h"
#include "quicksort.h"

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: %s <path to text file>\n", argv[0]);
        exit(1);
    }
    text_file_data data = read_text_file(argv[1]);
    printf("number of data points: %d\n", data.number_of_data_points);

    mean mean_values = calculate_mean(data.data_points, data.number_of_data_points);

    print_mean(mean_values);

    quicksort(data.data_points, 0, data.number_of_data_points - 1);
    for(int i = 0; i < data.number_of_data_points; i++){
        printf("%f ", data.data_points[i]);
    }

    // free(data.data_points);
}