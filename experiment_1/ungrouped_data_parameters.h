// ANALYSIS OF GROUPED DATA

#pragma once

// struct containing all the mean values
struct mean {
    float arithmatic_mean;
    float geometric_mean;
    float harmonic_mean;
};

// struct containing all the dispersion values
struct dispersion {
    float range;
    float variance;
    float quartile_deviation;
    float standard_deviation;
    float coefficient_of_variation;
};

// struct containing all the shape values
struct moment {
    float first_moment;
    float second_moment;
    float third_moment;
    float fourth_moment;
};
struct shape {
    float skewness;
    float kurtosis;
    struct moment moment_information;
};

// struct containing all the position values
struct position{
    float percentile;
    float quartile;
    float decile;
};

// struct containing all the correlation values
struct correlation{
    float covariance;
    float correlation_coefficient;
};


// struct for mode
struct mode_information_holder{
    float data_point;
    int frequency;
    struct mode_information_holder* next_mode_information_holder;
};


// Struct containing all the statistical properties
struct statistical_properties{
    int n;                  // number of data points
    struct mean mean;              // mean values
    float median;           // median value
    float mode;             // mode value
    struct dispersion dispersion;  // dispersion values
    struct shape shape;            // shape values
    struct position position;      // position values
    struct correlation correlation;// correlation values
};
