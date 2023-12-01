// Flight.h

#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airline.h"
#include "Passenger.h"
#include <vector>
#include "Seat.h"

class Flight {
private:
    Airline airline;
    std::vector<Passenger> passengers;
    std::vector<std::vector<Seat>> seatMap;

public:
    // Constructor
    void saveDataToFile(const std::string& filename) const;
    void addPassenger(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, int row, char column, int id);
    static void parseAssignedSeat(const std::string& assignedSeat, int& row, int& seatNumber);
    Flight(const Airline& airline);
    void displayPassengerInfo() const;
    void loadPassengersFromFile(const std::string& filename); // Load passenger data from file
    void displaySeatMap() const; // Display the seat map
    void removePassenger(int passengerId);
    
};

#endif // FLIGHT_H
