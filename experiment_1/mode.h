#pragma once 
#include "ungrouped_data_parameters.h"


struct mode_information_holder* calculate_mode_array(float* sorted_data, int number_of_data_points);
void print_mode_information(struct mode_information_holder* first_holder);

// functions for printing the mode information 
void print_mode_information(struct mode_information_holder* first_holder){
    printf("All the mode values are: \n");
    printf("\tFrequency: %d\n", first_holder->frequency);
    struct mode_information_holder* mode_linked_list_traverser = first_holder;
    int mode_number = 1;
    while(mode_linked_list_traverser != NULL){
        printf("\tMode - %d: %f\n", mode_number, mode_linked_list_traverser->data_point);
        mode_linked_list_traverser = mode_linked_list_traverser->next_mode_information_holder;
        mode_number++;
    }
    printf("\tThe data is %d-modal\n", mode_number - 1);
    free(first_holder);
}



// function to calculate the mode_array... it returns an array of struct mode_information_holder
struct mode_information_holder* calculate_mode_linked_list(float* sorted_data, int number_of_data_points){
    struct mode_information_holder* first_holder = (struct mode_information_holder*)malloc(sizeof(struct mode_information_holder));

    first_holder->data_point = sorted_data[0];
    first_holder->frequency = 1;
    first_holder->next_mode_information_holder = NULL;

    int mode_traverser_i = 0, mode_traverser_j = 0;
    int current_max_frequency = 1;
    float current_data_point = sorted_data[0];
    while(mode_traverser_i < number_of_data_points){
        while(sorted_data[mode_traverser_i + mode_traverser_j] == current_data_point){
            mode_traverser_j++;
            if(mode_traverser_j > current_max_frequency){
                current_max_frequency = mode_traverser_j;
                }
            }
        if(current_max_frequency == first_holder->frequency && current_data_point != first_holder->data_point){
            struct mode_information_holder* new_holder = (struct mode_information_holder*)malloc(sizeof(struct mode_information_holder));

            new_holder->data_point = current_data_point;
            new_holder->frequency = current_max_frequency;
            new_holder->next_mode_information_holder = first_holder;
            first_holder = new_holder;
        }

        if(current_max_frequency > first_holder->frequency){
            free(first_holder);
            first_holder = (struct mode_information_holder*)malloc(sizeof(struct mode_information_holder));
            if(first_holder == NULL){
                printf("Memory allocation failed!... while calculating mode...\n");
                exit(1);
            }
            first_holder->data_point = current_data_point;
            first_holder->frequency = current_max_frequency;
            first_holder->next_mode_information_holder = NULL;
        }
        mode_traverser_i += mode_traverser_j;
        mode_traverser_j = 0;
        current_data_point = sorted_data[mode_traverser_i];
    }
    return first_holder;
}
