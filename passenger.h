// Passenger.h

#ifndef PASSENGER_CLASS
#define PASSENGER_CLASS

#include <iostream>
#include <string>
#include "Seat.h" 
using namespace std;

class Passenger {
private:
    string Fname;
    string Lname;
    string phoneNum;
    Seat* prefseat; // Pointer to seat
    int ID;

public:
    // Default constructor
    Passenger();

    // Parameterized constructor
    Passenger(const string& fname, const string& lname, const string& phone, Seat* pseat, int ID);
};

#endif
