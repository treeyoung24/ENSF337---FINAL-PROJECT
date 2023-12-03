#include "Flight.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <limits>

// Constructor definition
Flight::Flight(const Airline& airline,int numRows, int numColumns) : airline(airline) {
    // Initialize the seat map with 24 rows and 6 columns by default
    seatMap.resize(numRows, std::vector<Seat>(numColumns, Seat()));
}

// Destructor Definition
Flight::~Flight(){}


void Flight::loadPassengersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    passengers.clear(); 

    std::string line;
    while (getline(file, line)) {
        if (line.size() >= 69) { // Ensure the line has enough characters for parsing
            std::string firstName = line.substr(0, 20);
            std::string lastName = line.substr(20, 20);
            std::string phoneNumber = line.substr(40, 20);
            std::string seatStr = line.substr(60, 4); // Contains seat info like " 6A"
            int id = std::stoi(line.substr(64, 5));

            // Remove any leading spaces in the seat string
            seatStr.erase(0, seatStr.find_first_not_of(' '));

            // Find the first non-digit character which indicates the start of the seat letter
            size_t firstNonDigit = seatStr.find_first_not_of("0123456789");
            int row = 0;
            char column = ' ';
            if (firstNonDigit != std::string::npos) {
                // Extract row number and column letter
                row = std::stoi(seatStr.substr(0, firstNonDigit));
                column = seatStr[firstNonDigit];
            } else {
                std::cerr << "Error: Seat information in wrong format for ID " << id << std::endl;
                continue; // Skip this passenger and continue with the next one
            }

            // Create passenger and add to list
            passengers.emplace_back(firstName, lastName, phoneNumber, row, column, id);
        }
    }

    // After loading all passengers, update the seatMap to reflect occupied seats
    for (const Passenger& passenger : passengers) {
        int passengerRow = passenger.getRows() - 1; // Adjust for zero-based indexing
        int seatIndex = passenger.getColumns() - 'A'; // Convert column letter to index
        if (passengerRow >= 0 && passengerRow < seatMap.size() &&
            seatIndex >= 0 && seatIndex < seatMap[passengerRow].size()) {
            seatMap[passengerRow][seatIndex].setOccupied(); // Mark the seat as occupied
        }
    }

    file.close(); // Close the file after updating the seatMap
}

// Display the seat map
void Flight::displaySeatMap() const {
    // Print header for seat columns
    std::cout << "     A   B   C   D   E   F" << std::endl;
    std::cout << "   " << std::string(25, '-') << std::endl; // Header separator

    for (int row = 0; row < seatMap.size(); ++row) {
        std::cout << std::setw(2) << row + 1 << " |"; // Print row number
        for (const Seat& seat : seatMap[row]) {
            std::cout << (seat.isOccupied() ? " X |" : "   |"); // Print X or space for occupied/empty seat
        }
        std::cout << std::endl;
        std::cout << "   " << std::string(25, '-') << std::endl; // Separator after each row
    }
}


void Flight::displayPassengerInfo() const {

        std::cout << std::left
              << std::setw(20) << "First Name"
              << std::setw(20) << "Last Name"
              << std::setw(20) << "Phone"
              << std::setw(5) << "Row"
              << std::setw(5) << "Seat"
              << std::setw(5) << "ID"
              << std::endl;
    
    // Print a line separator under the header
    std::cout << std::string(75, '-') << std::endl;

    // Passenger data
    for (const Passenger& p : passengers) {
        std::cout << std::left
                  << std::setw(20) << p.getFname()
                  << std::setw(20) << p.getLname()
                  << std::setw(20) << p.getPnum()
                  << std::setw(5) << p.getRows()
                  << std::setw(5) << p.getColumns()
                  << std::setw(5) << p.getID()
                  << std::endl;
        
        // Print a line separator after each passenger's information
        std::cout << std::string(75, '-') << std::endl;
    }
}

bool Flight::uniqueID(int id) const {
    return std::none_of(passengers.begin(), passengers.end(), [id](const Passenger& p) {
        return p.getID() == id;
    });
}

bool Flight::isSeatOccupied(int row, char column) const {
    int rowIndex = row - 1; // Adjust for zero-based indexing
    int columnIndex = toupper(column) - 'A'; // Convert to uppercase and index
    if (rowIndex >= 0 && rowIndex < seatMap.size() &&
        columnIndex >= 0 && columnIndex < seatMap[rowIndex].size()) {
        return seatMap[rowIndex][columnIndex].isOccupied();
    }
    return false; // Return false for invalid row/column inputs
}




// Add a new passenger
bool Flight::addPassenger(const std::string& firstName, const std::string& lastName, 
                          const std::string& phoneNumber, int row, char column, int id) {
    // Adjust for zero-based indexing
    int passengerRow = row - 1;
    int seatIndex = toupper(column) - 'A'; // Ensure uppercase for seat column

    if (!uniqueID(id)) {
        std::cerr << "Error: Passenger ID " << id << " already exists." << std::endl;
        return false; // ID exists, so do not add the passenger
    }

    // Validate the seat position
    if (passengerRow < 0 || passengerRow >= seatMap.size() ||
        seatIndex < 0 || seatIndex >= seatMap[passengerRow].size()) {
        std::cerr << "Error: Invalid row or column." << std::endl;
        return false; // Invalid row or column, so do not add the passenger
    }

    // Check if the seat is already occupied
    if (seatMap[passengerRow][seatIndex].isOccupied()) {
        std::cerr << "Error: Seat " << row << column << " is already occupied." << std::endl;
        return false; // Seat is occupied, so do not add the passenger
    }

    // Seat is available, so occupy it and add the passenger
    seatMap[passengerRow][seatIndex].setOccupied();
    passengers.emplace_back(firstName, lastName, phoneNumber, row, column, id);
    std::cout << "Passenger added successfully to seat " << row << column << "." << std::endl;
    return true; // Successfully added the passenger
}




void Flight::removePassenger(int id) {
    auto it = std::find_if(passengers.begin(), passengers.end(), [id](const Passenger& p) {
        return p.getID() == id;
    });

    if (it != passengers.end()) {
        // Update the seatMap
        int row = it->getRows() - 1;
        int column = it->getColumns() - 'A';
        if (row >= 0 && row < seatMap.size() && column >= 0 && column < seatMap[row].size()) {
            seatMap[row][column].removeSeat();
        }

        passengers.erase(it);
        std::cout << "Passenger with ID " << id << " removed successfully." << std::endl;
    } else {
        std::cout << "Passenger with ID " << id << " not found." << std::endl;
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
        file << std::left << std::setw(20) << p.getFname()
             << std::setw(20) << p.getLname()
             << std::setw(20) << p.getPnum()
             << std::setw(4) << (std::to_string(p.getRows()) + p.getColumns())
             << std::setw(5) << p.getID()
             << std::endl;
    }

    file.close();
}

