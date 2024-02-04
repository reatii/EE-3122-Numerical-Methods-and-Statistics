#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "bisection_method.h"
#include "regula_falsi.h"
#include "newtons_method.h"

typedef float (*func_t)(float); // This is a function pointer type
#define MAX_ITERATIONS 100


FILE* plot_with_gnuplot(float* errors, int iterations, char* temp_filename);
FILE* plot_all();



float f(float x){
    return x*exp(x) - 1;
}

float derivative_f(float x){
    return exp(x) + x*exp(x);
}



int main(){
    float true_root = bisection_method(f, 0, 1, 0.00001, 100000);

    struct bisection_method_result result = bisection_method_with_error(f, 0, 1, 0.0001, MAX_ITERATIONS, true_root);
    struct regula_falsi_result result2 = regula_falsi_with_error(f, 0, 1, 0.0001, MAX_ITERATIONS, true_root);
    struct newtons_method_result result3 = newtons_method(f, derivative_f, 0, 0.001, MAX_ITERATIONS, true_root);


    printf("True Root: %f\n", true_root);
    printf("Bisection Method:\n\tRoot: %f\n\tIterations: %d\n", result.root, result.iterations);
    printf("Regula Falsi Method:\n\tRoot: %f\n\tIterations: %d\n", result2.root, result2.iterations);
    printf("Newton's Method:\n\tRoot: %f\n\tIterations: %d\n\tTolerance Reached: %d\n", result3.root, result3.iterations, result3.tolerance_reached);

    FILE* plot1 = plot_with_gnuplot(result.errors, result.iterations, "Bisection Method");
    FILE* plot2 = plot_with_gnuplot(result2.errors, result2.iterations, "Regula Falsi Method");
    FILE* plot3 = plot_with_gnuplot(result3.errors, result3.iterations, "Newtons Method");
    FILE* plot4 = plot_all();

    printf("Click ctrl + d to quit... \n");
    getchar();
    pclose(plot1);
    pclose(plot2);
    pclose(plot3);
    pclose(plot4);
}





FILE* plot_with_gnuplot(float* errors, int iterations, char* temp_filename){

    FILE* gnuplot = popen("gnuplot", "w");
    if(!gnuplot){
        perror("popen");
        exit(EXIT_FAILURE);
    }

    FILE* temp = fopen(temp_filename, "w");
    if(!temp){
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < iterations; i++){
        fprintf(temp, "%d %f\n", i, errors[i]);
    }
    fclose(temp);
    fprintf(gnuplot, "set title 'Error vs Iteration'\n");
    fprintf(gnuplot, "set xlabel 'Iteration'\n");
    fprintf(gnuplot, "set ylabel 'Error'\n");
    fprintf(gnuplot, "plot '%s' with lines\n", temp_filename);
    fflush(gnuplot);

    // keep the plot window open
    // fprintf(stdout, "Click ctrl + d to quit... \n");
    // getchar();
    fflush(gnuplot);
    return gnuplot;
}

FILE* plot_all(){
    FILE* gnuplot = popen("gnuplot", "w");
    if(!gnuplot){
        perror("popen");
        exit(EXIT_FAILURE);
    }
    fprintf(gnuplot, "plot 'Bisection Method' with lines, 'Regula Falsi Method' with lines, 'Newtons Method' with lines\n");
    fprintf(gnuplot, "set title 'Comparison'\n");
    fprintf(gnuplot, "set xlabel 'Iteration'\n");
    fprintf(gnuplot, "set ylabel 'Error'\n");
    fprintf(gnuplot, "set xrange [0:20]\n");
    fprintf(gnuplot, "set yrange [0:0.4]\n");
    fflush(gnuplot);
    return gnuplot;
}