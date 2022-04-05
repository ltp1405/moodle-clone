#pragma once

#include <ctime>

struct RegistrationSession {
    std::tm start{}, end{};
    RegistrationSession() {}
    RegistrationSession(std::tm start, std::tm end) {
        this->start = start;
        this->end = end;
    }
};