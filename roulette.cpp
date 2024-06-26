#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <thread> 
#include <chrono>  

using namespace std;

int balance = 1000;  // Initial virtual currency amount

// Function to check if the number is red, in a specific column, or in a specific row
bool checkAttributes(int number, string type, int attribute) {
    int reds[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    if (type == "red") {
        for (int red : reds) {
            if (number == red) return true;
        }
        return false;
    } else if (type == "column") {
        return (number % 3 == attribute % 3) && number != 0;
    } else if (type == "row") {
        return (number > (attribute - 1) * 3) && (number <= attribute * 3);
    }
    return false;
}

// Function to get valid integer input
int getValidIntInput(string prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input < 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cout << "Invalid input, please try again." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear extra input
            break;
        }
    }
    return input;
}

// Main function
int playRoulette() {
    srand(time(0)); // Initialize random number generator
    int wins = 0, losses = 0;

    while (true) {
        cout << "Welcome to the Roulette Game! Your balance is: $" << balance << endl;
        cout << "Bet types: number, red, black, even, odd, low, high, column, row." << endl;
        cout << "Enter bet type or 'exit' to quit: ";
        string betType;
        cin >> betType;
        if (betType == "exit") break;

        int result = rand() % 37; // Generate a random number between 0 and 36

        // Determine win or loss
        bool win = false;
        if (betType == "number") {
            int betNumber = getValidIntInput("Enter the number you want to bet on (0-36): ");
            win = (betNumber == result);
        } else if (betType == "red") {
            win = checkAttributes(result, "red", 0);
        } else if (betType == "black") {
            win = !checkAttributes(result, "red", 0) && result != 0;
        } else if (betType == "even") {
            win = (result % 2 == 0) && result != 0;
        } else if (betType == "odd") {
            win = (result % 2 != 0);
        } else if (betType == "low") {
            win = (result >= 1 && result <= 18);
        } else if (betType == "high") {
            win = (result >= 19 && result <= 36);
        } else if (betType == "column" || betType == "row") {
            int attribute = 0;
            string prompt = (betType == "column") ? "Enter the column (1-3): " : "Enter the row (1-12): ";
            attribute = getValidIntInput(prompt);

            if (betType == "column") {
                win = checkAttributes(result, "column", attribute);
            } else {
                win = checkAttributes(result, "row", attribute);
            }
        } else { 
            cout << "Error: type again" << endl;
            continue;
        }

        int betAmount = getValidIntInput("Enter your bet amount: $");
        if (betAmount > balance) {
            cout << "Insufficient balance. Your bet cannot exceed $" << balance << "." << endl;
            continue;
        }

        // Generate roulette result
        cout << "The roulette wheel is spinning..." << endl;
        for (int i = 0; i < 10; i++) { // Simple animation loop
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        cout << " The result is: " << result << endl;


        if (win) {
            cout << "Congratulations, you won!" << endl;
            balance += betAmount;
            wins++;
        } else {
            cout << "Sorry, you lost." << endl;
            balance -= betAmount;
            losses++;
        }

        cout << "Current balance: $" << balance << endl;
        cout << "Total wins: " << wins << " Total losses: " << losses << endl;

        if (balance <= 0) {
            cout << "You have run out of money. Game over!" << endl;
            break;
        }
    }

    return 0;
}
