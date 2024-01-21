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
#include "welcome_message.h"
#include "printing_functions.h"
#include "dispersion_measures.h"
#include "median.h"
#include "mode.h"
#include "shape_measures.h"


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


    // Reaading the data from the text file into a struct of type text_file_data(defined in load_ungrouped_data_from_txt_file_into_an_array.h)
    // read_text_file() is defined in load_ungrouped_data_from_txt_file_into_an_array.h
    text_file_data data = read_text_file(file_path);
    float* sorted_data_points = merge_sort(data.data_points, data.number_of_data_points);

    // printing the welcome message which is defined in welcome_message.h
    int choice = print_welcome_message();
    print_separator();

    // variables
    grouped_data* grouped_data_points = NULL;
    mean mean_values = calculate_mean(data.data_points, data.number_of_data_points);
    dispersion dispersion_values = calculate_dispersion(sorted_data_points, data.number_of_data_points);
    shape shape_values = calculate_shape(sorted_data_points, data.number_of_data_points);
    float median_value = calculate_median(sorted_data_points, data.number_of_data_points);
    float weighted_mean_value = INFINITY;

    // Interacting with the user based on the choice made by the user
    while(choice != 0){
        switch(choice){
            case 1:
                print_sorted_data(sorted_data_points, data.number_of_data_points); // defined in printing_functions.h
                break;
            
            case 2:
                printf("Number of data points: %d\n", data.number_of_data_points);
                break;

            case 3:
                if(grouped_data_points != NULL){
                    free(grouped_data_points);
                    grouped_data_points = ungrouped_to_grouped(sorted_data_points, data.number_of_data_points); // defined in ungrouped_data_to_grouped_data.h
                }
                else{
                    grouped_data_points = ungrouped_to_grouped(sorted_data_points, data.number_of_data_points);
                }
                print_grouped_data(grouped_data_points);
                break;

            case 4:
                print_mean(mean_values); // defined in printing_functions.h
                break;

            case 5:
                if(weighted_mean_value == INFINITY){
                    weighted_mean_value = weighted_mean(data.data_points, data.number_of_data_points); // defined in mean.h
                }
                printf("Weighted mean: %f\n", weighted_mean_value);
                break;
            
            case 6:
                print_dispersion(dispersion_values); // defined in printing_functions.h
                break;

            case 7:
                printf("Median: %f\n", median_value);
                break;

            case 8:
                printf("Mode: %f\n", calculate_mode(sorted_data_points, data.number_of_data_points));
                break;
            
            case 9:
                print_shape(shape_values); // defined in printing_functions.h
                break;
        }
        print_separator();
        choice = print_welcome_message();
    }

    if (choice == 0){
        printf("\nThank you for using this program!\n");
    }
}