#include <iostream>
#include <iomanip>
#include <string>
#include "option.h"
#include "validate.h"
#include "black-scholes.h"
#include "binomial-tree.h"

int main() {

    // Get option parameters from user inputs
    double strikePrice = getPositiveDouble("Enter strike price: ");
    double expiry = getPositiveDouble("Enter expiration in years: ");
    double volatility = getPositiveDouble("Enter volatility (as a decimal, 0.2 for 20%): ");
    double interestRate = getPositiveDouble("Enter interest rate (as a decimal, 0.05 for 5%): ");
    double currentPrice = getPositiveDouble("Enter current price of the underlying asset: ");
    // Option::OptionType optionType = getOptionType();

    // Get pricing method from user input
    std::string method;
    std::cout << "Enter pricing method type (black-scholes or binomial): ";
    std::cin >> method;
    for (auto &c : method) c = std::tolower(c);

    if (method == "black-scholes") {
        // Create an Option object -- black-scholes
        Option option(strikePrice, expiry, volatility, interestRate, currentPrice, Option::OptionType::CALL);
        double callPrice = blackScholesCall(option.getCurrentPrice(), option.getStrikePrice(), option.getExpiry(),
                                            option.getInterestRate(), option.getVolatility());
        double putPrice = blackScholesPut(option.getCurrentPrice(), option.getStrikePrice(), option.getExpiry(), 
                                        option.getInterestRate(), option.getVolatility());

        // Display the option prices -- black-scholes
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Call Option Price: $" << callPrice << std::endl;
        std::cout << "Put Option Price: $" << putPrice << std::endl;
    } 
    else {
        // Calculate parameters for the binomial model
        int N = getPositiveInteger("Enter number of steps for binomial tree: ");
        double deltaT = getDeltaT(expiry, N);
        double u = getUpFactor(volatility, deltaT);
        double d = getDownFactor(u);
        double p = (std::exp(interestRate * deltaT) - d) / (u - d);

        // Calculate option prices at maturity
        std::vector<double> optionPricesAtMaturity = calculateOptionValuesAtMaturity(currentPrice, strikePrice, u, d, N, Option::OptionType::CALL);

        // Calculate the option price at time 0
        double optionPrice = stepBackwardThroughTree(optionPricesAtMaturity, p, interestRate, deltaT, currentPrice, strikePrice, u, d, N, Option::OptionType::CALL, false);

        // Display the option price
        std::cout << "Option Price: $" << optionPrice << std::endl;
    }

    return 0;
}
