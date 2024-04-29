#include <iostream>
#include <cstdlib> // for system("pause")

// Function declarations for game functions
void playRoulette();
void playBlackjack();

int main() {
    int choice;

    // Display menu for game selection
    std::cout << "Select a game to play:" << std::endl;
    std::cout << "1. Roulette" << std::endl;
    std::cout << "2. Blackjack" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    // Based on the choice, call the corresponding function to play the game
    switch(choice) {
        case 1:
            playRoulette();
            break;
        case 2:
            playBlackjack();
            break;
        default:
            std::cout << "Invalid choice. Exiting program." << std::endl;
            break;
    }

    return 0;
}

// Function declarations for game functions
void playRoulette();
void playBlackjack();
