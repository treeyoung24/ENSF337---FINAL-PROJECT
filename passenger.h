// Passenger.h

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    std::string Fname;
    std::string Lname;
    std::string Pnum;
    int rows;
    char columns;
    int ID;

public:
    // Passenger constructor 
    Passenger(const std::string& Fname, const std::string& Lname,
              const std::string& Pnum, int rows, char columns, int ID);

    // Getter and Setter for member functions
    std::string getFname() const;
    void setFname(const std::string& Fname);

    std::string getLname() const;
    void setLname(const std::string& Lname);

    std::string getPnum() const;
    void setPnum(const std::string& Pnum);

    int getRows() const;
    void setRows(int rows);

    char getColumns() const;
    void setColumns(char columns);

    int getID() const;
    void setID(int ID);
};

#endif