#include "option.h"

// Constructor implementation
Option::Option(double strikePrice, double expiry, double volatility, 
               double interestRate, double currentPrice, OptionType optionType)
    : strikePrice(strikePrice), expiry(expiry), volatility(volatility), 
      interestRate(interestRate), currentPrice(currentPrice), optionType(optionType) {}

// Getter implementations
double Option::getStrikePrice() const {
    return strikePrice;
}

double Option::getExpiry() const {
    return expiry;
}

double Option::getVolatility() const {
    return volatility;
}

double Option::getInterestRate() const {
    return interestRate;
}

double Option::getCurrentPrice() const {
    return currentPrice;
}

Option::OptionType Option::getOptionType() const {
    return optionType;
}

// Setter implementations
void Option::setStrikePrice(double strikePrice) {
    this->strikePrice = strikePrice;
}

void Option::setExpiry(double expiration) {
    this->expiry = expiration;
}

void Option::setVolatility(double volatility) {
    this->volatility = volatility;
}

void Option::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}

void Option::setCurrentPrice(double currentPrice) {
    this->currentPrice = currentPrice;
}

void Option::setOptionType(OptionType optionType) {
    this->optionType = optionType;
}
