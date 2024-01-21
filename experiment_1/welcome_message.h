#pragma once
#include "printing_functions.h"


// The following function prints the welcome message and returns the choice of the user
int print_welcome_message(){
    printf("\nWelcome to statistical analyst 0.1!\n\n");
    printf("\tSelect what you want to do with the data: \n");
    printf("\t----------------------------------------\n");

    printf("\t\t1. Print the sorted(ascending) data\n");
    printf("\t\t2. Print the number of data points\n");
    printf("\t\t3. Convert to grouped data and print Converted Data\n");
    printf("\t\t4. Print the mean (Arithmetic, Geometric, Harmonic) of the data\n");
    printf("\t\t5. Calculate and print the weighted mean (you may need to provide the weights)\n");
    printf("\t\t6. Calculate and print the dispersion measures (Range, Variance, Standard\n\t\t\tDeviation, Coefficient of Variation, Quartile Deviation)\n");
    printf("\t\t7. Calculate and print the  median\n");
    printf("\t\t8. Calculate and print the mode\n");
    printf("\t\t9. Calculate and print the shape measures (moment about mean, skewness, kurtosis)\n");
    printf("\t\t10. Calculate and print the moments about a point\n");

    printf("\t----------------------------------------\n");
    printf("\tTo exit the program enter 0\n\n");

    print_separator();
    printf("Enter one of the numbers (0/1/2/3...) to continue: ");
    int user_choice;
    scanf("%d", &user_choice);
    return user_choice;
}