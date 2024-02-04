#include<stdio.h>
#include<stdlib.h>

int main(){
    const char* filename = "input.txt";

    FILE* gnuplot = popen("gnuplot", "w");
    if(!gnuplot){
        perror("popen");
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplot, "plot \"%s\" t 'price' w lp\n", filename);
    fflush(gnuplot);
    fprintf(stdout, "Click ctrl + d to quit... \n");
    getchar();

    pclose(gnuplot);
    exit(EXIT_SUCCESS);
}