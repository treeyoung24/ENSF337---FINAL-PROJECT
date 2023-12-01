// Passenger.cpp

#include "Passenger.h"

// Default constructor


// Parameterized constructor
Passenger::Passenger(const std::string& firstName, const std::string& lastName,
                     const std::string& phoneNumber, int row, char column, int id)
    : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber),
      row(row), column(column), id(id) {
    // The member initializer list initializes the members with the given arguments.
}

// Getter method for firstName
std::string Passenger::getFirstName() const {
    return firstName;
}

// Setter method for firstName
void Passenger::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

// Getter method for lastName
std::string Passenger::getLastName() const {
    return lastName;
}

// Setter method for lastName
void Passenger::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

// Getter method for phoneNumber
std::string Passenger::getPhoneNumber() const {
    return phoneNumber;
}

// Setter method for phoneNumber
void Passenger::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

int Passenger::getRow() const {
    return row;
}

void Passenger::setRow(int rowM) {
    this->row = rowM;
}

char Passenger::getColumn() const {
    return column;
}

void Passenger::setColumn(char columnM) {
    this->column = columnM;
}

// Getter method for id
int Passenger::getId() const {
    return id;
}

// Setter method for id
void Passenger::setId(int id) {
    this->id = id;
}

// Add other member function implementations as needed
