// main.h

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include "Airline.h"
#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"

class MainMenu {
public:
    void displayMenu();
    void executeOption(int choice, Flight& flight);
};

#endif // MAIN_H
