#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int balance = 1000;  // Initial virtual currency amount

// Check whether it is red, in which column, and which row
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

// Get valid integer input
int getValidIntInput(string prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input < 0) {
            cin.clear(); // clear wrong sign
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore wrong input
            cout << "Invalid input, please try again." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear useless input
            break;
        }
    }
    return input;
}

// main
int main() {
    srand(time(0)); // Initialize the random number generator
    int wins = 0, losses = 0;

    while (true) {
        cout << "Welcome to the Roulette Game! Your balance is: $" << balance << endl;
        cout << "Bet types: number, red, black, even, odd, low, high, column, row." << endl;
        cout << "Enter bet type or 'exit' to quit: ";
        string betType;
        cin >> betType;
        if (betType == "exit") break;

        int betAmount = getValidIntInput("Enter your bet amount: $");
        if (betAmount > balance) {
            cout << "Insufficient balance. Your bet cannot exceed $" << balance << "." << endl;
            continue;
        }

        int betNumber = 0, attribute = 0;
        if (betType == "number") {
            betNumber = getValidIntInput("Enter the number you want to bet on (0-36): ");
        } else if (betType == "column" || betType == "row") {
            string prompt = (betType == "column") ? "Enter the column (1-3): " : "Enter the row (1-12): ";
            attribute = getValidIntInput(prompt);
        }

        // Generate roulette result
        int result = rand() % 37; // Generate a random number between 0 and 36
        cout << "The roulette wheel is spinning..." << endl;
        for (int i = 0; i < 10; i++) { // Simple "animation" loop
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        cout << " The result is: " << result << endl;

        // Determine win or loss
        bool win = false;
        if (betType == "number
