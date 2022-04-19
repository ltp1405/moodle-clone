#include <string>
#include "Date.h"

enum InputError {
    Invalid,
    WrongFormat,
    None,
};

InputError dateInput(Date &date, std::string format);
InputError idInput(std::string &id);
InputError nameInput(std::string &name);
