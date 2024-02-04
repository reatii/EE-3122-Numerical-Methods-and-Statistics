#pragma once

typedef float (*func_t)(float); // This is a function pointer type

struct bisection_method_result{
    float root;
    int iterations;
    float* errors;
};


float bisection_method(func_t func_, float interval_start, float interval_end, float tolerance, int max_iterations);

struct bisection_method_result bisection_method_with_error(func_t func_, float interval_start, float interval_end, float tolerance, int max_iterations, float true_root);


// Path: experiment_3/bisection_method_with_error.c
struct bisection_method_result bisection_method_with_error(func_t func_, float interval_start, float interval_end, float tolerance, int max_iterations, float true_root){
    if(func_(interval_start) * func_(interval_end) > 0){
        printf("No root in the given interval...\n"); // Error: No root in the given interval
    }

    float mid_value;
    int iteration = 0;
    struct bisection_method_result result;
    result.errors = (float*)calloc(max_iterations, sizeof(float));


    for(iteration = 0; iteration < max_iterations; iteration++){
        mid_value = (interval_start + interval_end) / 2;
        if(func_(mid_value) == 0 || (interval_end - interval_start) / 2 < tolerance){
            result.root = mid_value;
            result.iterations = iteration;
            return result;
        }
        if(func_(mid_value) * func_(interval_start) < 0){
            interval_end = mid_value;
        }else{
            interval_start = mid_value;
        }
        result.errors[iteration] = fabs(true_root - mid_value);
    }
    result.root = mid_value;
    result.iterations = iteration;
    return result;
}


// Path: experiment_3/bisection_method.c
float bisection_method(func_t func_, float interval_start, float interval_end, float tolerance, int max_iterations){
    if(func_(interval_start) * func_(interval_end) > 0){
        printf("No root in the given interval..."); // Error: No root in the given interval
    }

    float mid_value;
    int iteration = 0;
    for(iteration = 0; iteration < max_iterations; iteration++){
        mid_value = (interval_start + interval_end) / 2;
        if(func_(mid_value) == 0 || (interval_end - interval_start) / 2 < tolerance){
            return mid_value;
        }
        if(func_(mid_value) * func_(interval_start) < 0){
            interval_end = mid_value;
        }else{
            interval_start = mid_value;
        }
    }
    printf("Method failed to converge for the desired tolerance...\n"); // Error: Method failed to converge
    return mid_value;
}