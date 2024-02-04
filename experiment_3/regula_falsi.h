#pragma once

typedef float (*func_t)(float); // This is a function pointer type

struct regula_falsi_result{
    float root;
    int iterations;
    float* errors;
};

struct regula_falsi_result regula_falsi(func_t func_, float interval_start, float interval_end, float tolerance, int max_iterations, float true_root);

struct regula_falsi_result regula_falsi_with_error(func_t func_, float interval_start, float interval_end, float tolerance, int max_iterations, float true_root){
    if(func_(interval_start) * func_(interval_end) > 0){
        printf("No root in the given interval...\n"); // Error: No root in the given interval
    }
    struct regula_falsi_result result;
    result.errors = (float*)calloc(max_iterations, sizeof(float));

    float line_root = interval_end - (interval_start - interval_end) * func_(interval_end) / (func_(interval_start) - func_(interval_end));
    for(int i = 0; i < max_iterations; i++){
        line_root = interval_end - (interval_start - interval_end) * func_(interval_end) / (func_(interval_start) - func_(interval_end));
        if(func_(line_root) == 0 || (interval_end - interval_start) / 2 < tolerance){
            result.root = line_root;
            result.iterations = i;
            return result;
        }
        if(func_(line_root) * func_(interval_start) < 0){
            interval_end = line_root;
        }else{
            interval_start = line_root;
        }
        result.errors[i] = fabs(true_root - line_root);
    }
    printf("Regula falsi method failed to converge...\n");
    result.root = line_root;
    result.iterations = max_iterations;
    return result;
}