//seat.cpp


#include "seat.h"

// Default constructor
Seat::Seat() : rows(0), columns(0) {}

// Non default constructor
Seat::Seat(int r, char c) : rows(r), columns(c) {}

// Getter function definitions
int Seat::getRows() const {
    return rows;
}

char Seat::getColumns() const {
    return columns;
}

bool Seat::isOccupied() const{ 
    return occupied;
}

void Seat::setOccupied(bool value){ 
    occupied = value;
}
