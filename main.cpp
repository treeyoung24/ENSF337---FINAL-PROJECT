// main.cpp
#include <limits>
#include "Main.h"
#include <algorithm>

using namespace std;

void mainMenu::Options(int choice, Flight& flight) {
    int ID;
    string fName, lName, pNum;
    int ROWS;
    char COLUMNS;

    switch (choice) {
        case 1:
            //Option 1: Display Flight Seat Map
            flight.displaySeatMap();
            pressEnter();
            break;
        case 2:
            //Option 2: Display Passengers Information
            flight.displayPassengerInfo();
            pressEnter();
            break;
        case 3: {
            //Option 3: Add a New Passenger
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            // Validate and get passenger ID
            bool IDVALID = false;
            while (!IDVALID) {
                cout << "Please enter the passenger ID (5 digits): ";
                if (!(cin >> ID) || to_string(ID).length() != 5) {
                    cout << "Invalid ID. Please enter a 5-digit passenger ID:\n ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else if (!flight.uniqueID(ID)) {
                    cout << "Error: Passenger ID " << ID << " already exists. Please enter a different ID:\n ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    IDVALID = true;
                }
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Get and validate passenger first name
            cout << "Please enter the passenger first name: ";
            while (true) {
                getline(cin, fName);
                if (all_of(fName.begin(), fName.end(), [](char c) { return isalpha(c) || isspace(c); })) {
                    break;
                } else {
                    cout << "Invalid first name. Please enter a valid name: ";
                }
            }

            // Get and validate passenger last name
            cout << "Please enter the passenger last name: ";
            while (true) {
                getline(cin, lName);
                if (all_of(lName.begin(), lName.end(), [](char c) { return isalpha(c) || isspace(c); })) {
                    break;
                } else {
                    cout << "Invalid last name. Please enter a valid name: ";
                }
            }

            // Get and validate phone number
            cout << "Please enter the passenger phone number (format: xxx-xxx-xxxx): ";
            while (true) {
                getline(cin, pNum);
                if (pNum.length() == 12 && 
                    pNum[3] == '-' && pNum[7] == '-' &&
                    all_of(pNum.begin(), pNum.begin() + 3, ::isdigit) &&
                    all_of(pNum.begin() + 4, pNum.begin() + 7, ::isdigit) &&
                    all_of(pNum.begin() + 8, pNum.end(), ::isdigit)) {
                    break;
                } else {
                    cout << "Invalid phone number. Please enter in the format xxx-xxx-xxxx: ";
                }
            }

            // Validate rows and seat
            bool openSeat = false;
            while (!openSeat) {
                cout << "Enter the passenger's desired ROWS: ";
                if (!(cin >> ROWS) || ROWS <= 0) {
                    cout << "Invalid ROWS. Please enter a valid ROWS number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cout << "Enter the passenger's desired seat (e.g., A, B, C, ... F): ";
                cin >> COLUMNS;
                COLUMNS = toupper(COLUMNS); // Convert to uppercase 

                if (!isalpha(COLUMNS) || COLUMNS < 'A' || COLUMNS > 'F') {
                    cout << "Invalid seat. Please enter a valid seat (e.g., A, B, C, ... F).\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (flight.isSeatOccupied(ROWS, COLUMNS)) {
                    cout << "Error: Seat " << ROWS << COLUMNS << " is already occupied. Please choose a different seat.\n";
                } else {
                    openSeat = true;
                }
            }

            // Add passenger
            flight.addPassenger(fName, lName, pNum, ROWS, COLUMNS, ID);
            pressEnter();
            break;
        }


        case 4:
            //Option 4: Remove an Existing Passenger
            int removeID;
            cout << "Please enter the passenger ID to remove: ";
            while(!(cin >> removeID)) {
                cout << "Invalid input. Please enter a numeric passenger ID: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore lines 
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flight.removePassenger(removeID);
            pressEnter();
            break;


        case 5:{
                //Option 5: Save data
                char response;
                bool validResponse = false;

                while (!validResponse) {
                    // Ask the user if they want to save the data
                    cout << "Do you want to save the data in the “flight_info.txt”? Please answer <Y or N>: ";
                    cin >> response;

                    // Validate the response
                    if (toupper(response) == 'Y') {
                        flight.saveDataToFile("flight_info.txt");
                        cout << "All the data in the passenger list was saved into the flight_info.txt." << endl;

                        // Ignore the current line in the input buffer only if it's not empty
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        // Wait for user to press Enter
                        cout << "Press Enter to continue...";
                        cin.get();

                        validResponse = true; 
                    } else if (toupper(response) == 'N') {
                        cout << "Save operation was canceled." << endl;
                        validResponse = true; 
                    } else {
                        cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
                    }
                }
                break;
            }

        default:
            cout << "Invalid choice. Please select a valid option." << endl;
    }
}


int main() {
    Airline airline("Westjet1145", "WJ1145");
    Flight flight(airline);  
    display_header();
    pressEnter();

    // Load passengers from file
    flight.loadPassengersFromFile("flight_info.txt"); 

    mainMenu menu;
    int choice;

    while (true) {
    cout << " " << endl;
    cout << "Flight Management Program" << endl;
    cout << " " << endl;
    menu.displayMenu();

    cin >> choice;
    if (choice == 6) {
        cout << "Program terminated." << endl;
        break; 
    }
    menu.Options(choice, flight);
}

return 0; 

}

void display_header() {
    cout << "Version: 1.0\n";
    cout << "Term Project - Flight Management Program in C++\n";
    cout << "Produced by: Himel Paul, Tri Dung Phan\n";
}

void pressEnter() {
    cout << "\n<<< Press Enter to Continue >>>";
    if (cin.rdbuf()->in_avail() > 0) {
        // Ignore the current line in the input buffer only if it's not empty
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.get(); // Wait for user to press Enter
}

// Displaying all the optinons

void mainMenu::displayMenu() {
    cout << "Please select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map." << endl;
    cout << "2. Display Passengers Information." << endl;
    cout << "3. Add a New Passenger." << endl;
    cout << "4. Remove an Existing Passenger." << endl;
    cout << "5. Save data." << endl;
    cout << "6. Quit." << endl;
    cout << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
}

