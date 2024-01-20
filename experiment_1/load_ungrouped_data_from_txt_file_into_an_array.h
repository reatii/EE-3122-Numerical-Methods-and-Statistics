// This file contains the function for reading a .txt file(ungrouped data) and returning an array containing the data points
#pragma once
#include "ungrouped_data_parameters.h"
#include <stdlib.h>

#define ALLOCATION_UNIT 100

// struct for storing the data points from a .txt file
typedef struct {
    int number_of_data_points;
    float* data_points;     // pointer to the array of data points
} text_file_data;

// struct for tracking the memory allocation for the data_points array
typedef struct {
    int number_of_allocations; // how many ALLOCATION_UNITs have been used for of the data from the .txt file into the data_points array so far
    int current_position;   // the current position in the recent ALLOCATION_UNIT
} memory_allocation_tracker;

// The following function reads a .txt file(ungrouped data) and returns an array containing the data points
text_file_data read_text_file(char* file_path){
    FILE* file_pointer = fopen(file_path, "r");
    if(file_pointer == NULL){
        printf("Error: File not found\n");
        exit(1);
    }

    // The following struct named "data_from_file" contains the data points and the number of data points from  the .txt file
    text_file_data data_from_file = {0,
                                    (float*)malloc(sizeof(float) * ALLOCATION_UNIT)};

    // The following struct named "tracker" tracks the memory allocation for the data_points array
    memory_allocation_tracker tracker = {1, 0};


    while(!feof(file_pointer)){
        if(tracker.current_position == ALLOCATION_UNIT){
            tracker.number_of_allocations++;
            tracker.current_position = 0;
            data_from_file.data_points = realloc(data_from_file.data_points, sizeof(float) * ALLOCATION_UNIT * tracker.number_of_allocations);
        }
        fscanf(file_pointer, "%f", &data_from_file.data_points[(tracker.number_of_allocations - 1) * ALLOCATION_UNIT + tracker.current_position]);
        tracker.current_position++;
    }
    data_from_file.number_of_data_points = (tracker.number_of_allocations - 1) * ALLOCATION_UNIT + tracker.current_position;
    fclose(file_pointer);

    // returning the struct containing the data points and the number of data points
    return data_from_file;
}