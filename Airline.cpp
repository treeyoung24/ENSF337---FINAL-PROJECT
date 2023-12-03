// Airline.cpp

#include "Airline.h"
using namespace std;

// Constructor
Airline::Airline(const string& airlineName, const string& airlineCode)
    : airlineName(airlineName), airlineCode(airlineCode), flightNumber("") {
}

void Airline::setFlightNumber(const string& fn) {
    flightNumber = fn;
}

string Airline::getFlightNumber() const {
    return flightNumber;
}

string Airline::getAirlineName() const {
    return airlineName;
}

void Airline::setAirlineName(const string& airlineName) {
    this->airlineName = airlineName;
}

string Airline::getAirlineCode() const {
    return airlineCode;
}

void Airline::setAirlineCode(const string& airlineCode) {
    this->airlineCode = airlineCode;
}