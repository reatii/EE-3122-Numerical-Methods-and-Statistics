#pragma once


typedef float (*func_t)(float); // This is a function pointer type

struct newtons_method_result{
    float root;
    int iterations;
    int tolerance_reached;
    float* errors;
};

struct newtons_method_result newtons_method(func_t func_, func_t derivative_, float initial_guess, float tolerance, int max_iterations, float true_root);

struct newtons_method_result newtons_method(func_t func_, func_t derivative_, float initial_guess, float tolerance, int max_iterations, float true_root){
    struct newtons_method_result result;
    result.errors = (float*)calloc(max_iterations, sizeof(float));
    result.tolerance_reached = 0;

    float x = initial_guess;
    for(int i = 0; i < max_iterations; i++){
        x = x - func_(x) / derivative_(x);
        if(fabs(x - initial_guess) < tolerance && result.tolerance_reached == 0){
            result.tolerance_reached = 1;
        }
        if(func_(x) == 0){
            result.root = x;
            result.iterations = i;
            return result;
        }
        result.errors[i] = fabs(true_root - x);
    }
    if(result.tolerance_reached == 0){
        printf("Newton's method failed to converge...\n");
    }
    result.root = x;
    result.iterations = max_iterations;
    return result;
}