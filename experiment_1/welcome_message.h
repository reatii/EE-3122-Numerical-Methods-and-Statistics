#pragma once


// The following function prints the welcome message and returns the choice of the user
int print_welcome_message(){
    printf("\nWelcome to statistical analyst 0.1!\n\n");
    printf("Select what you want to do with the data: \n");
    printf("1. Print the sorted(ascending) data\n");
    printf("2. Print the number of data points\n");
    printf("3. Convert to grouped data and print Converted Data\n");
    printf("4. Print the mean of the data\n\t -> Arithmetic mean\n\t -> Geometric mean\n\t -> Harmonic mean\n\t -> Weighted mean (you may need to provide the weights)\n");
    printf("To exit the program enter 0\n");
    printf("Enter one of the numbers (1/2/3...) to continue: ");


    int choice;
    scanf("%d", &choice);
    return choice;
}