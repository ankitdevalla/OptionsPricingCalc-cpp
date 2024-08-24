#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

// calculate CDF of standard normal distribution using complementary error function
double normalCDF(double x) {
    return 0.5 * std::erfc(-x * M_SQRT1_2);
}

// calculate d1 component -- applied to current stock price
double calculateD1(double S, double K, double T, double r, double sigma) {
    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

// calculate d2 component -- applied to strike price of the contract
double calculateD2(double d1, double sigma, double T) {
    return d1 - sigma * std::sqrt(T);
}

// calculate call option price using Black-Scholes formula
double blackScholesCall(double S, double K, double T, double r, double sigma) {
    double d1 = calculateD1(S, K, T, r, sigma);
    double d2 = calculateD2(d1, sigma, T);
    return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
}

// calculate put option price using Black-Scholes formula
double blackScholesPut(double S, double K, double T, double r, double sigma) {
    double d1 = calculateD1(S, K, T, r, sigma);
    double d2 = calculateD2(d1, sigma, T);
    return K * std::exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
}
