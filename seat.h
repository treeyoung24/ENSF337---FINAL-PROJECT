// Seat.h

#ifndef SEAT_CLASS
#define SEAT_CLASS

class Seat {
public:
    // Default constructor
    Seat() : num(0), occupied(false) {}

    // Non default constructor
    Seat(int num);

    void vacantSeat();
    void removeSeat();
    bool isOccupied() const;
    void setOccupied();

private:
    int num;
    bool occupied;
};

#endif