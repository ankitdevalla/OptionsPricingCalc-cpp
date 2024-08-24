#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

// Include necessary libraries
#include <cmath>

// Function declarations
double normalCDF(double x);
double calculateD1(double S, double K, double T, double r, double sigma);
double calculateD2(double d1, double sigma, double T);
double blackScholesCall(double S, double K, double T, double r, double sigma);
double blackScholesPut(double S, double K, double T, double r, double sigma);

#endif // BLACK_SCHOLES_H
