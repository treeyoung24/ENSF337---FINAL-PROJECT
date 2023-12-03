// main.h

#ifndef MAIN
#define MAIN

#include <iostream>
#include <vector>
#include "Airline.h"
#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"

void display_header();
void pressEnter();
class mainMenu {
public:
    void displayMenu();
    void Options(int choice, Flight& flight);
};

#endif 