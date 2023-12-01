// Passenger.h

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    int row;
    char column;
    int id;

public:
    // Constructor
    Passenger(const std::string& firstName, const std::string& lastName,
              const std::string& phoneNumber, int row, char column, int id);

    // Getter and Setter methods for member variables
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);
    std::string getLastName() const;
    void setLastName(const std::string& lastName);
    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string& phoneNumber);
    int getRow() const; // Updated to match the definition
    void setRow(int row); // Updated to match the definition
    char getColumn() const; // Updated to match the definition
    void setColumn(char column); // Updated to match the definition
    int getId() const;
    void setId(int id);

    // Add other member functions as needed
};

#endif // PASSENGER_H
