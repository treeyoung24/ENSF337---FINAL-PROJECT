#include "Airline.h"

// Constructor
Airline::Airline(const std::string& name, const std::string& code)
    : name(name), code(code), flightNumber("") { // Initialize flightNumber here if necessary
}

// Ensure this method is defined once
void Airline::setFlightNumber(const std::string& fn) {
    flightNumber = fn;
}

std::string Airline::getFlightNumber() const {
    return flightNumber;
}

std::string Airline::getName() const {
    return name;
}

void Airline::setName(const std::string& name) {
    this->name = name;
}

std::string Airline::getCode() const {
    return code;
}

void Airline::setCode(const std::string& code) {
    this->code = code;
}

// Implement other member functions as needed
