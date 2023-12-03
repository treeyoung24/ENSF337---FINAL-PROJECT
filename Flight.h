#ifndef FLIGHT_CLASS
#define FLIGHT_CLASS

#include "Airline.h"
#include "Passenger.h"
#include <vector>
#include "Seat.h"
using namespace std;


class Flight {


public:
   //Constructor
    Flight(const Airline& airline, int numRows = 24, int numColumns = 6);
    
    // Destructor
    ~Flight();


    //Member functions 
    bool isSeatOccupied(int row, char column) const;
    bool uniqueID(int id) const;
    void saveDataToFile(const string& filename) const;
    bool addPassenger(const string& firstName, const string& lastName, const string& phoneNumber, int row, char column, int id);
    void displayPassengerInfo() const;
    void loadPassengersFromFile(const string& filename); 
    void displaySeatMap() const;
    void removePassenger(int id);    

private:
    Airline airline;
    vector<Passenger> passengers;
    vector<vector<Seat>> seatMap;

};

#endif 