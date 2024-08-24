#ifndef OPTION_H
#define OPTION_H

#include <string>

class Option {
    public: 
        // use an enum to represent the option type
        enum OptionType { CALL, PUT };

        // Constructor
        Option(double strikePrice, double expiry, double volatility, double interestRate,
            double currentPrice, OptionType optionType);
        
        // Getters
        double getStrikePrice() const;
        double getExpiry() const;
        double getVolatility() const;
        double getInterestRate() const;
        double getCurrentPrice() const;
        OptionType getOptionType() const;

        // Setters
        void setStrikePrice(double strikePrice);
        void setExpiry(double expiry);
        void setVolatility(double volatility);
        void setInterestRate(double interestRate);
        void setCurrentPrice(double currentPrice);
        void setOptionType(OptionType optionType);

    // Private
    private:
        double strikePrice;
        double expiry;
        double volatility;
        double interestRate;
        double currentPrice;
        OptionType optionType;
};

#endif