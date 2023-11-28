// passenger.cpp

#include "Passenger.h"

// Default constructor definition
Passenger::Passenger() : Fname(""), Lname(""), phoneNum(""), prefseat(nullptr), ID(0) {}

// non default constructor definition
Passenger::Passenger(const string& fname, const string& lname, const string& phone, Seat* pseat, int id)
    : Fname(fname), Lname(lname), phoneNum(phone), prefseat(pseat), ID(id) {}
