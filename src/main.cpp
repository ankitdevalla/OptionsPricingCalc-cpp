#include <iostream>
#include <iomanip>
#include "option.h"
#include "validate.h"
#include "black-scholes.h"

int main() {

    // Get option parameters from user inputs
    double strikePrice = getPositiveDouble("Enter strike price: ");
    double expiry = getPositiveDouble("Enter expiration in years: ");
    double volatility = getPositiveDouble("Enter volatility (as a decimal, 0.2 for 20%): ");
    double interestRate = getPositiveDouble("Enter interest rate (as a decimal, 0.05 for 5%): ");
    double currentPrice = getPositiveDouble("Enter current price of the underlying asset: ");
    // Option::OptionType optionType = getOptionType();

    // Create an Option object
    Option option(strikePrice, expiry, volatility, interestRate, currentPrice, Option::OptionType::CALL);
    double callPrice = blackScholesCall(option.getCurrentPrice(), option.getStrikePrice(), option.getExpiry(),
                                        option.getInterestRate(), option.getVolatility());
    double putPrice = blackScholesPut(option.getCurrentPrice(), option.getStrikePrice(), option.getExpiry(), 
                                      option.getInterestRate(), option.getVolatility());

    // Display the option parameters
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Call Option Price: $" << callPrice << std::endl;
    std::cout << "Put Option Price: $" << putPrice << std::endl;

    return 0;
}
