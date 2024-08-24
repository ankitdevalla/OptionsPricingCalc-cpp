#include <iostream>
#include <limits>
#include "validate.h"

double getPositiveDouble(const std::string& prompt) {
    double val;
    while (true) {
        std::cout << prompt;
        std::cin >> val;

        // Check for invalid input
        if (std::cin.fail() || val <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore bad input
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra input
            return val;
        }
    }
}

int getPositiveInteger(const std::string& prompt) {
    int val;
    while (true) {
        std::cout << prompt;
        std::cin >> val;

        // Check for invalid input
        if (std::cin.fail() || val <= 0 || val != static_cast<int>(val)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore bad input
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra input
            return val;
        }
    }
}

Option::OptionType getOptionType() {
    int choice;
    while (true) {
        std::cout << "Enter option type -- 1 for Call, 2 for Put: ";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore bad input
            std::cout << "Invalid input. Please enter 1 for Call or 2 for Put." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra input
            return (choice == 1) ? Option::CALL : Option::PUT;
        }
    }
}