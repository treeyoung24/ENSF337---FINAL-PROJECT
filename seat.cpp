// Seat.cpp

#include "Seat.h"

// Constructor definition
Seat::Seat(int num) : num(num), occupied(false) {
}

// Getter method for occupied
bool Seat::isOccupied() const {
    return occupied;
}

void Seat::vacantSeat() {
    occupied = false;
}

// Function to set the seat to occupied
void Seat::setOccupied() {
    occupied = true;
}

void Seat::removeSeat() {
    occupied = false;
}