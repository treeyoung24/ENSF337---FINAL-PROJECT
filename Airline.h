// Airline.h

#ifndef AIRLINE_CLASS
#define AIRLINE_CLASS

#include <string>

class Airline {
private:
    std::string airlineName;
    std::string airlineCode;
    std::string flightNumber;

public:
    // Constructor
    Airline(const std::string& airlineName, const std::string& airlineCode);

    // Getter and Setter methods for member variables
    std::string getFlightNumber() const;
    void setFlightNumber(const std::string& flightNumber);

    std::string getAirlineName() const;
    void setAirlineName(const std::string& airlineName);

    std::string getAirlineCode() const;
    void setAirlineCode(const std::string& airlineCode);

    
};

#endif 