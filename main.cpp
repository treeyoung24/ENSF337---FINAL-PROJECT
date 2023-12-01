// main.cpp

#include "Main.h"

void MainMenu::displayMenu() {
    std::cout << "Please select one of the following options:" << std::endl;
    std::cout << "1. Display Flight Seat Map." << std::endl;
    std::cout << "2. Display Passengers Information." << std::endl;
    std::cout << "3. Add a New Passenger." << std::endl;
    std::cout << "4. Remove an Existing Passenger." << std::endl;
    std::cout << "5. Save data." << std::endl;
    std::cout << "6. Quit." << std::endl;
    std::cout << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
}

void MainMenu::executeOption(int choice, Flight& flight) {
    int id;
    std::string firstName, lastName, phoneNumber;
    int row;
    char seatLetter;
    std::string saveFilename;

    switch (choice) {
        case 1:
            // Implement option 1: Display Flight Seat Map
            flight.displaySeatMap();
            break;
        case 2:
            flight.displayPassengerInfo();
            break;
        case 3:

            // Prompt the user to enter passenger information
            std::cout << "Please enter the passenger id: ";
            std::cin >> id;

            // Prompt the user to enter other passenger information
            std::cout << "Please enter the passenger first name: ";
            std::cin >> firstName;

            std::cout << "Please enter the passenger last name: ";
            std::cin >> lastName;

            std::cout << "Please enter the passenger phone number: ";
            std::cin >> phoneNumber;

            std::cout << "Enter the passenger's desired row: ";
            std::cin >> row;

            std::cout << "Enter the passenger's desired seat (e.g., A, B, C): ";
            std::cin >> seatLetter;

            // Call the addPassenger function with the provided information
            flight.addPassenger(firstName, lastName, phoneNumber, row, seatLetter, id);
            std::cout << "Passenger added successfully!" << std::endl;
            break;

        case 4:
            int removeId;
            std::cout << "Please enter the passenger ID to remove: ";
            std::cin >> removeId;
            flight.removePassenger(removeId);
            break;

        case 5:
        
            std::cout << "Enter the filename to save data: ";
            std::cin >> saveFilename;
            flight.saveDataToFile(saveFilename);
            break;

        case 6:
            std::cout << "Program terminated." << std::endl;
            return;  // Use return to exit the executeOption function.

        default:
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
    }
}


int main() {
    Airline airline("Sample Airline", "SA");
    Flight flight(airline);  // Create a Flight object

    // Load passengers from a file
    flight.loadPassengersFromFile("flight_info.txt"); // Replace with your data file

    MainMenu menu;
    int choice;

    while (true) {
    std::cout << "Flight Management Program" << std::endl;
    menu.displayMenu();

    std::cin >> choice;
    if (choice == 6) {
        break;  // Break out of the loop to terminate the program.
    }
    menu.executeOption(choice, flight);
}

return 0;  // Now the program will return 0 after breaking out of the loop.

}
