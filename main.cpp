#include <iostream>
#include <limits>

// Function declarations for game functions
void playRoulette();
void playBlackjack();

void clearcin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int choice;
    bool running = true;

    while (running) {  // Added a while loop to allow multiple selections
        // Display menu for game selection
        std::cout << "Select a game to play:" << std::endl;
        std::cout << "1. Roulette" << std::endl;
        std::cout << "2. Blackjack" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            clearcin();
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        // Based on the choice, call the corresponding function to play the game
        switch(choice) {
            case 1:
                playRoulette();
                break;
            case 2:
                playBlackjack();
                break;
            case 3:
                running = false;
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
