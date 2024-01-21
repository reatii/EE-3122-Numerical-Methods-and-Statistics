#pragma once

// print sorted data
void print_sorted_data(float* data_points, int number_of_data_points){
    printf("Sorted data: \n");
    printf("\t+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
    for(int i = 0; i < number_of_data_points; i=i+10){
        printf("\t|");
        for(int j = 0; j < 10; j++){
            printf("   %-12f|", data_points[i+j]);
        }
        printf("\n");
        printf("\t+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+\n");
    }
    printf("\n");
}


// The following function prints the grouped data
// grouped_data struct is defined in experiment_1/ungrouped_data_to_grouped_data.h
void print_grouped_data(grouped_data* grouped_data_struct){
    printf("----------------------------------------\n");
    printf("Minimum data value: %f\n", grouped_data_struct->minimum_data_value);
    printf("Maximum data value: %f\n", grouped_data_struct->maximum_data_value);
    printf("Range: %f\n", grouped_data_struct->range);
    printf("Class size: %f\n", grouped_data_struct->class_size);
    printf("Number of classes: %d\n", grouped_data_struct->number_of_classes);
    printf("Grouped Data Table: \n");
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


// The following function prints the mean values
void print_mean(mean mean_values){ // mean_values is the struct containing all the mean values
    printf("Mean values: \n");
    printf("\tArithmatic mean: %-12f\n", mean_values.arithmatic_mean);
    printf("\tGeometric mean : %-12f\n", mean_values.geometric_mean);
    printf("\tHarmonic mean  : %-12f\n", mean_values.harmonic_mean);
}

// print dispersion values
void print_dispersion(dispersion dispersion_values){
    printf("Dispersion values: \n");
    printf("\tRange                    : %-12f\n", dispersion_values.range);
    printf("\tVariance                 : %-12f\n", dispersion_values.variance);
    printf("\tStandard deviation       : %-12f\n", dispersion_values.standard_deviation);
    printf("\tCoefficient of variation : %-12f\n", dispersion_values.coefficient_of_variation);
    printf("\tQuartile deviation       : %-12f\n", dispersion_values.quartile_deviation);
}


// print shape values
void print_shape(shape shape_values){
    printf("Shape values about mean: \n");
    printf("\tSkewness      : %-12f\n", shape_values.skewness);
    printf("\tKurtosis      : %-12f\n", shape_values.kurtosis);
    printf("\tFirst moment  : %-12f\n", shape_values.moment_information.first_moment);
    printf("\tSecond moment : %-12f\n", shape_values.moment_information.second_moment);
    printf("\tThird moment  : %-12f\n", shape_values.moment_information.third_moment);
    printf("\tFourth moment : %-12f\n", shape_values.moment_information.fourth_moment);
}



// The following function prints a separator
void print_separator(){
    printf("==================================================================================================\n");
}