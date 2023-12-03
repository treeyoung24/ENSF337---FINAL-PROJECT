// Passenger.cpp

#include "Passenger.h"

// Parameterized constructor
Passenger::Passenger(const std::string& Fname, const std::string& Lname,
                     const std::string& Pnum, int rows, char columns, int ID)
    : Fname(Fname), Lname(Lname), Pnum(Pnum),
      rows(rows), columns(columns), ID(ID) {
}

// Getter method definitions
std::string Passenger::getFname() const {
    return Fname;
}

void Passenger::setFname(const std::string& Fname) {
    this->Fname = Fname;
}

std::string Passenger::getLname() const {
    return Lname;
}

void Passenger::setLname(const std::string& Lname) {
    this->Lname = Lname;
}

std::string Passenger::getPnum() const {
    return Pnum;
}

void Passenger::setPnum(const std::string& Pnum) {
    this->Pnum = Pnum;
}

int Passenger::getRows() const {
    return rows;
}

void Passenger::setRows(int rows) {
    this->rows = rows;
}

char Passenger::getColumns() const {
    return columns;
}

void Passenger::setColumns(char columns) {
    this->columns = columns;
}

int Passenger::getID() const {
    return ID;
}

void Passenger::setID(int ID) {
    this->ID = ID;
}