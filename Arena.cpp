// Arena.cpp
#include "Arena.h"
#include <iostream>
#include<cmath>

Arena::Arena() {
    // Initialize your characters here
    player = new Predator(0, 0); // Assuming Predator is a subclass of Character
    prey = new Prey(5, 5); // Assuming Prey is a subclass of Character
    predator = new Predator(10, 10); // Assuming Predator is a subclass of Character

    maxSteps = 100; // or whatever maximum steps you want
    currentStep = 0;
}

Arena::~Arena() {
    // Don't forget to delete your characters to avoid memory leaks
    delete player;
    delete prey;
    delete predator;
}

void Arena::startGame() {
    while (!isGameOver()) {
        std::string direction = direction;
        moveCharacters(direction);
        currentStep++;
    }
}

void Arena::moveCharacters(const std::string& Direction) {
    player->Move(Direction);
    prey->Move(Direction);
    predator->Move(Direction);
}

bool Arena::isGameOver() {
        if (currentStep >= maxSteps) {
            return true;
        }

        // Calculate the distance between the predator and the prey
        int dx = predator->x - prey->x;
        int dy = predator->y - prey->y;
        double distance = sqrt(dx * dx + dy * dy);

        // Check if the predator has caught the prey
        if (distance < 1) {
            return true;
        }

        return false;
    }