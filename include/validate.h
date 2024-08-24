#ifndef VALIDATE_H
#define VALIDATE_H

#include <string>
#include "option.h"

double getPositiveDouble(const std::string& prompt);
int getPositiveInteger(const std::string& prompt);
Option::OptionType getOptionType();

#endif // VALIDATE_H