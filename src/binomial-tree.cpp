#include "binomial-tree.h"
#include <cmath>
#include <algorithm>

// Calculate deltaT, the time step
double getDeltaT(double T, int N) {
    return T / N;
}

// Calculate the up factor (by what factor the stock price goes up each step)
double getUpFactor(double sigma, double deltaT) {
    return std::exp(sigma * std::sqrt(deltaT));
}

// Calculate the down factor (by what factor the stock price goes down each step)
double getDownFactor(double upFactor) {
    return 1 / upFactor;
}

// Calculate the option values at maturity
std::vector<double> calculateOptionValuesAtMaturity(double S, double K, double u, double d, int N, bool isCall) {
    std::vector<double> optionPrices(N + 1);

    for (int i = 0; i <= N; i++) {
        double stockPriceAtMaturity = S * std::pow(u, N - i) * std::pow(d, i);
        if (isCall) {
            optionPrices[i] = std::max(stockPriceAtMaturity - K, 0.0); // Call option
        } 
        else {
            optionPrices[i] = std::max(K - stockPriceAtMaturity, 0.0); // Put option
        }
    }

    return optionPrices;
}

// Step backward through the tree to calculate the option price at time 0
double stepBackwardThroughTree(const std::vector<double>& optionPricesAtMaturity, double p, 
                    double r, double deltaT, double S, double K, double u, double d, int N, 
                    bool isCall, bool isAmerican) {

    std::vector<double> optionPrices = optionPricesAtMaturity;
    for (int j = N - 1; j >= 0; j--) {
        for (int i = 0; i <= j; i++) {
            optionPrices[i] = (p * optionPrices[i] + (1 - p) * optionPrices[i + 1]) * std::exp(-r * deltaT);
            // Check for early exercise (American options only)
            if (isAmerican) {
                double stockPrice = S * std::pow(u, j - i) * std::pow(d, i);
                if (isCall) {
                    optionPrices[i] = std::max(optionPrices[i], stockPrice - K);
                } 
                else {
                    optionPrices[i] = std::max(optionPrices[i], K - stockPrice);
                }
            }
        }
    }

    return optionPrices[0];
}