#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random fraction between 0 and 1
double generateRandomFraction() {
    return (double)rand() / RAND_MAX;
}

// Function to generate a random integer
int generateRandomInteger() {
    return rand();
}

int main() {
    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Open the file for random fractions
    FILE *fractionsFile = fopen("random_1000_fractions.txt", "w");
    if (fractionsFile == NULL) {
        perror("Error opening file for random fractions");
        return 1;
    }

    // Open the file for random integers
    FILE *integersFile = fopen("random_1000_integers.txt", "w");
    if (integersFile == NULL) {
        perror("Error opening file for random integers");
        fclose(fractionsFile); // Close the previous file if an error occurs
        return 1;
    }

    // Generate and write 1000 random fractions and integers
    for (int i = 0; i < 1000; ++i) {
        double randomFraction = generateRandomFraction();
        int randomInteger = generateRandomInteger();

        // Write the random fraction to the fractions file
        fprintf(fractionsFile, "%lf\n", randomFraction);

        // Write the random integer to the integers file
        fprintf(integersFile, "%d\n", randomInteger);
    }

    // Close the files
    fclose(fractionsFile);
    fclose(integersFile);

    printf("Files 'random_1000_fractions.txt' and 'random_1000_integers.txt' created successfully.\n");

    return 0;
}
