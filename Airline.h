// Airline.h

#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class Airline {
private:
    std::string name;
    std::string code;
    std::string flightNumber;
    // Add any other member variables relevant to the airline class

public:
    // Constructor
    Airline(const std::string& name, const std::string& code);
    // Getter and Setter methods for member variables
    std::string getFlightNumber() const;
    void setFlightNumber(const std::string& flightNumber);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getCode() const;
    void setCode(const std::string& code);

    // Add other member functions as needed
};

#endif // AIRLINE_H
