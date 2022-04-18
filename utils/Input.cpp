#include <iostream>
#include <regex>
#include <string>
#include <utility>

#include "Input.hpp"

InputError dateInput(Date &date) {
    string date_string;
    std::getline(std::cin, date_string);
    if (!std::regex_match(date_string, std::regex("[0-9]{2} [0-9]{2} [0-9]{4}")))
        return InputError::WrongFormat;
    string day_string, month_string, year_string;
    day_string = date_string.substr(0, 2);
    month_string = date_string.substr(3, 2);
    year_string = date_string.substr(6, 4);

    date.day = std::stod(day_string);
    date.month = std::stod(month_string);
    date.year = std::stod(year_string);

    if (!date.valid())
        return InputError::Invalid;

    return InputError::None;
}

bool validID(const std::string &id) {
    const char *regex_pattern = "[0-9]+";
    if (std::regex_match(id, std::regex(regex_pattern)))
        return true;
    return false;
}

InputError idInput(std::string &id) {
    std::getline(std::cin, id);
    if (!validID(id))
        return InputError::Invalid;
    return InputError::None; 
}

bool validName(const std::string &name) {
    const char *regex_pattern = "[A-Za-z ]+";
    if (std::regex_match(name, std::regex(regex_pattern)))
        return true;
    return false;
}

InputError nameInput(std::string &name) {
    std::getline(std::cin, name);
    if (!validName(name))
        return InputError::Invalid;
    return InputError::None;
}
