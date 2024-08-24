#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

#include <vector>

double getDeltaT(double T, int N);
double getUpFactor(double sigma, double deltaT);
double getDownFactor(double upFactor);
std::vector<double> calculateOptionValuesAtMaturity(double S, double K, double u, double d, int N, bool isCall);
double stepBackwardThroughTree(const std::vector<double>& optionPricesAtMaturity, double p, 
                    double r, double deltaT, double S, double K, double u, double d, int N, 
                    bool isCall, bool isAmerican);



#endif // BINOMIAL_TREE_H