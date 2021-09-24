// Copyright (c) 2020 Sydney Kuhn All rights reserved
//
// Created by: Sydney Kuhn
// Created on: Sep 2020
// This program is a random number guessing game

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function is the game
    std::string numberGuessedAsString;
    int numberGuessed;
    int someRandomNumber;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0, 9]
    someRandomNumber = idist(rgen);

    // input
    std::cout << "Guess a number between 0-9: ";
    std::cin >> numberGuessedAsString;

    // process & output
    try {
        numberGuessed = std::stoi(numberGuessedAsString);
        if (numberGuessed == someRandomNumber) {
            std::cout << "You guessed correctly!" << std::endl;
        } else {
            std::cout << "You guessed wrong!" << std::endl;
            std::cout << "\nThe correct answer was" " "
            << someRandomNumber << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "Invalid number guessed, please try again.";
    }
    std::cout << "\nDone." << std::endl;
}
