#pragma once
#include<math.h>

typedef struct{
    float minimum_data_value;
    float maximum_data_value;
    float range;
    float class_size;
    int number_of_classes;
    int* class_array;
    int number_of_data_points;
} grouped_data;



// The following function converts the ungrouped data to grouped data and returns the pointer to
// the struct containing the grouped data... the position in the array represents the class number
// and the value at that position represents the frequency of that class
// therefore, the size of the array is equal to the number of classes
// And lower class limit of the n'th class is given by: position_in_the_array * class_size
// And the upper class limit of the n'th class is given by: (position_in_the_array + 1) * class_size - 1

// The function also assumes that the lower class limit is inclusive and the upper class limit is exclusive

grouped_data* ungrouped_to_grouped(float* sorted_data, int number_of_data_points){
    grouped_data* grouped_data_struct = (grouped_data*)malloc(sizeof(grouped_data));
    grouped_data_struct->minimum_data_value = sorted_data[0];
    grouped_data_struct->maximum_data_value = sorted_data[number_of_data_points - 1];
    grouped_data_struct->number_of_data_points = number_of_data_points;
    grouped_data_struct->range = grouped_data_struct->maximum_data_value - grouped_data_struct->minimum_data_value;

    // The following code asks the user to enter the class size or the number of classes
    printf("Enter one of the following(1 or 2): \n\t 1. Class size \n\t or \n\t 2. Number of classes\n\t Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 1){
        printf("Enter the class size: ");
        scanf("%f", &grouped_data_struct->class_size);
        grouped_data_struct->number_of_classes = ceil(grouped_data_struct->range / grouped_data_struct->class_size);
    }
    if(choice == 2){
        printf("Enter the number of classes: ");
        scanf("%d", &grouped_data_struct->number_of_classes);
        grouped_data_struct->class_size = grouped_data_struct->range / grouped_data_struct->number_of_classes;
    }

    grouped_data_struct->class_array = (int*)calloc(grouped_data_struct->number_of_classes, sizeof(int));

    int class_number = 0;
    int data_point_number = 0;
    int frequency = 0;
    while(data_point_number < number_of_data_points){
        float lower_class_limit = sorted_data[0] + class_number * grouped_data_struct->class_size;
        float upper_class_limit = lower_class_limit + grouped_data_struct->class_size;
        while(sorted_data[data_point_number]>=lower_class_limit && sorted_data[data_point_number]<upper_class_limit){
            frequency++;
            data_point_number++;
        }
        grouped_data_struct->class_array[class_number] = frequency;
        frequency = 0;
        class_number++;
    }
    return grouped_data_struct;
}

// The following function prints the grouped data
void print_grouped_data(grouped_data* grouped_data_struct){
    printf("Minimum data value: %f\n", grouped_data_struct->minimum_data_value);
    printf("Maximum data value: %f\n", grouped_data_struct->maximum_data_value);
    printf("Range: %f\n", grouped_data_struct->range);
    printf("Class size: %f\n", grouped_data_struct->class_size);
    printf("Number of classes: %d\n", grouped_data_struct->number_of_classes);
    printf("Class array: \n");
        printf("+--------------+-------------+-------------+-------------+\n");
        printf("| Class number | lower limit | upper limit | frequency   |\n");
        printf("|--------------+-------------+-------------+-------------|\n");
    for(int i = 0; i < grouped_data_struct->number_of_classes; i++){
        printf("|     %-9d|", i+1);
        printf("   %-10f|", grouped_data_struct->minimum_data_value + i * grouped_data_struct->class_size);
        printf("   %-10f|", grouped_data_struct->minimum_data_value + (i+1) * grouped_data_struct->class_size);
        printf("   %-10d|\n", grouped_data_struct->class_array[i]);
        printf("+--------------+-------------+-------------+-------------+\n");
    }
        printf("|     TOTAL    |      ~      |      ~      |   %-10d|\n", grouped_data_struct->number_of_data_points);
        printf("+--------------+-------------+-------------+-------------+\n");
}