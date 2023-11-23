//seat.h

#ifndef SEAT_CLASS
#define SEAT_CLASS


class Seat{

    public:

    Seat(): rows(0), columns(0){}

    Seat(int r, char c): rows(r), columns(c){}

    int getRows()const {return rows;}

    char getColumns()const {return columns;}



    private:
        int rows;
        char columns;




}





#endif

