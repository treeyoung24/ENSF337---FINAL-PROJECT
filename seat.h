// Seat.h

#ifndef SEAT_H
#define SEAT_H

class Seat {
    int number;
    bool isOccupied;

public:
    // Default constructor
    Seat() : number(0), isOccupied(false) {}

    // Parameterized constructor
    Seat(int number);

    bool getIsOccupied() const;
    void occupySeat();
};

#endif
