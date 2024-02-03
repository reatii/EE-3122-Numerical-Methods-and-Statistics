#pragma once

// struct for containing rows of matrix data
struct matrix_data_row {
    float* data;
    struct matrix_data_row* next_matrix_row;
};

// struct for containing the matrix data
struct matrix_data {
    int number_of_rows;
    int number_of_columns;
    struct matrix_data_row* matrix_data_row;
};

// function to read the matrix data from a file
struct matrix_data* read_matrix_data(FILE* matrix_data_file){
    struct matrix_data* matrix_data = (matrix_data*)malloc(sizeof(struct matrix_data));
    if(matrix_data != NULL){
        *matrix_data = (struct matrix_data){0, 0, NULL}; // initializing the matrix_data struct with 0 values
    }
    else {
        printf("Memory allocation failed!... while reading the matrix data ...\n");
    }

    char* line = NULL;
    size_t len
}