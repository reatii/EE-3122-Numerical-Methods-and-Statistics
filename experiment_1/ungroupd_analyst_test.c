#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// my header files
#include "ungrouped_data_parameters.h"
#include "load_ungrouped_data_from_txt_file_into_an_array.h"
#include "mean.h"
#include "merge_sort.h"
#include "ungrouped_data_to_grouped_data.h"

int main(int argc, char** argv){
    // check if the user has provided the path to the text file as a command line argument... if not then ask
    // the user to provide the path to the text file...
    char file_path[256];
    if(argc < 2){
        printf("Usage: %s <path to the text file containing the data>\n", argv[0]);
        printf("Enter the path to the text file containing the data: ");
        fgets(file_path, 256, stdin);

        // remove the trailing newline character from the file_path string
        file_path[strcspn(file_path, "\n")] = 0;
    }
    else {
        strncpy(file_path, argv[1], 256);
    }

    text_file_data data = read_text_file(file_path);

    printf("number of data points: %d\n", data.number_of_data_points);

    // mean mean_values = calculate_mean(data.data_points, data.number_of_data_points);

    // print_mean(mean_values);
    
    float* sorted_data_points = merge_sort(data.data_points, data.number_of_data_points);
    // for(int i = 0; i < data.number_of_data_points; i++){
    //     printf("%f \t", sorted_data_points[i]);
    //     if(i%10==0){
    //         printf("\n");
    //     }
    // }
    printf("\n");

    grouped_data* grouped_data_points = ungrouped_to_grouped(sorted_data_points, data.number_of_data_points);
    print_grouped_data(grouped_data_points);
    free(data.data_points);
}