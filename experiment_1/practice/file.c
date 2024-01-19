#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    FILE* fptr;

    fptr = fopen("/home/user/projects/EE-3122-Numerical-Methods-and-Statistics/experiment_1/practice/program.txt", "w");

    if(fptr==NULL){
        printf("Error");
        exit(1);
    }

    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    fclose(fptr);

    return 0;
}