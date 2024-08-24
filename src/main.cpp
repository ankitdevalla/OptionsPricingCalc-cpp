#include <iostream>
#include "option.h"
#include "validate.h"

int main() {

    // Get option parameters from user inputs
    double strikePrice = getPositiveDouble("Enter strike price: ");
    double expiry = getPositiveDouble("Enter expiration in years: ");
    double volatility = getPositiveDouble("Enter volatility (as a decimal, 0.2 for 20%): ");
    double interestRate = getPositiveDouble("Enter interest rate (as a decimal, 0.05 for 5%): ");
    double currentPrice = getPositiveDouble("Enter current price of the underlying asset: ");
    Option::OptionType optionType = getOptionType();

    // Create an Option object
    Option option(strikePrice, expiry, volatility, interestRate, currentPrice, optionType);

    // Display the option parameters
    std::cout << "\nOption parameters:" << std::endl;
    std::cout << "Strike price: " << option.getStrikePrice() << std::endl;
    std::cout << "Expiration: " << option.getExpiry() << " years" << std::endl;
    std::cout << "Volatility: " << option.getVolatility() << std::endl;
    std::cout << "Interest rate: " << option.getInterestRate() << std::endl;
    std::cout << "Current price: " << option.getCurrentPrice() << std::endl;
    std::cout << "Option type: " << (option.getOptionType() == Option::CALL ? "Call" : "Put") << std::endl;

    return 0;
}
