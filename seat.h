//seat.h

#ifndef SEAT_CLASS
#define SEAT_CLASS

class Seat {
public:
    Seat(); //default ctor
    Seat(int r, char c); // non-default ctor
    ~Seat();

    int getRows() const; //getter function for row
    char getColumns() const;//get function for column
    bool isOccupied() const; // Boolean to see if seat is taken or not
    void setOccupied(bool value); // A function to set the seat occupation status

private:
    int rows; // track the row of seat
    char columns; // track the column of seat
    bool occupied; // variable to check seat occupancy
};

#endif
