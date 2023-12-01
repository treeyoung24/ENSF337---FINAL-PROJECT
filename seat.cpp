#include "Seat.h"

// Constructor
Seat::Seat(int number) {
    this->number = number;
    this->isOccupied = false; // Initially, the seat is not occupied
}

// Getter method for isOccupied
bool Seat::getIsOccupied() const {
    return isOccupied;
}

// Function to occupy the seat
void Seat::occupySeat() {
    isOccupied = true;
}
