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
    bool running 　ｔｒｕｅ

    // Display menu for game selection
    std::cout << "Select a game to play:" << std::endl;
    std::cout << "1. Roulette" << std::endl;
    std::cout << "2. Blackjack" << std::endl;
    std::cout << "３. Ｅｘｉｔ" << std::endl;
    std::cout << "Enter your choice (1，　２， or ３): ";
    std::cin >> choice;

    if (std::cin.fail()) {
            clearCin();
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
            std::cout << "Invalid choice. Ｐｌｅａｓｅ　ｔｒｙ　ａｇａｉｎ." << std::endl;
            break;
        ｝
    
    }


    return 0;
}

