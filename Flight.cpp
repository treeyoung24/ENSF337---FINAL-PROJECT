#include "Flight.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <algorithm>

// Constructor
Flight::Flight(const Airline& airline) : airline(airline) {
    // Initialize seatMap based on your project's requirements
    // Example: 24 rows and 6 seats per row
    seatMap.resize(24, std::vector<Seat>(6, Seat()));
}

// Load passenger data from file
void Flight::loadPassengersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    passengers.clear(); // Clear existing passengers

    std::string line;
    while (getline(file, line)) {
        if (line.size() >= 69) { // Ensure the line has enough characters for parsing
            // Assuming fixed-width fields in the file
            std::string firstName = line.substr(0, 20);
            std::string lastName = line.substr(20, 20);
            std::string phoneNumber = line.substr(40, 20);
            std::string seatStr = line.substr(60, 4).erase(0, line.substr(60, 4).find_first_not_of(' ')); // Extract the seat info like " 6A"
            
            int id = std::stoi(line.substr(64, 5));

            // Remove any leading spaces in the seat string
            size_t firstNonSpace = seatStr.find_first_not_of(' ');
            int row;
            char column;
            if (firstNonSpace != std::string::npos) {
                // Extract row number
                row = std::stoi(seatStr.substr(firstNonSpace, seatStr.size() - firstNonSpace - 1));
                // Extract column letter
                column = seatStr.back();
            } else {
                // Handle error if seat string is not in expected format
                std::cerr << "Error: Seat information in wrong format." << std::endl;
                continue; // Skip this passenger and continue with the next one
            }

            // Create passenger and add to list
            Passenger passenger(firstName, lastName, phoneNumber, row, column, id);
            passengers.push_back(passenger);
        }
    }

    file.close();
}

// Display the seat map
void Flight::displaySeatMap() const {
    for (int row = 0; row < seatMap.size(); ++row) {
        std::cout << row + 1 << " "; // Row number
        for (const Seat& seat : seatMap[row]) {
            std::cout << (seat.getIsOccupied() ? "X " : "O ");
        }
        std::cout << std::endl;
    }
}

// Display passenger information
void Flight::displayPassengerInfo() const {
    std::cout << std::left
              << std::setw(20) << "First Name"
              << std::setw(20) << "Last Name"
              << std::setw(20) << "Phone"
              << std::setw(5) << "Row"
              << std::setw(5) << "Seat"
              << std::setw(5) << "ID" << std::endl;

    for (const Passenger& p : passengers) {
        std::cout << std::left
                  << std::setw(20) << p.getFirstName()
                  << std::setw(20) << p.getLastName()
                  << std::setw(20) << p.getPhoneNumber()
                  << std::setw(5) << p.getRow()
                  << std::setw(5) << p.getColumn()
                  << std::setw(5) << p.getId()
                  << std::endl;
    }
}

// Add a new passenger
void Flight::addPassenger(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, int row, char column, int id) {
    Passenger newPassenger(firstName, lastName, phoneNumber, row, column, id);
    passengers.push_back(newPassenger);
}

// Remove a passenger
void Flight::removePassenger(int id) {
    auto it = std::remove_if(passengers.begin(), passengers.end(), [id](const Passenger& p) {
        return p.getId() == id;
    });

    if (it != passengers.end()) {
        passengers.erase(it, passengers.end());
        std::cout << "Passenger removed successfully." << std::endl;
    } else {
        std::cout << "Passenger not found." << std::endl;
    }
}

// Save data to file
void Flight::saveDataToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    for (const Passenger& p : passengers) {
        file << p.getFirstName() << " "
             << p.getLastName() << " "
             << p.getPhoneNumber() << " "
             << p.getRow() << p.getColumn() << " "
             << p.getId() << std::endl;
    }

    file.close();
}
