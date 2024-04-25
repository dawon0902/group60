#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <thread> 
#include <chrono>  

using namespace std;

int balance = 1000;  // Initial virtual currency amount

// Function to check if the number is red, in a specific column, or in a specific row
bool checkattributes(int number, string type, int attribute) {
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
int getvalidintinput(string prompt) {
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
int main() {
    srand(time(0)); // Initialize random number generator
    int wins = 0, losses = 0;

    while (true) {
        cout << "Welcome to the Roulette Game! Your balance is: $" << balance << endl;
        cout << "Bet types: number, red, black, even, odd, low, high, column, row." << endl;
        cout << "Enter bet type or 'exit' to quit: ";
        string bettype;
        cin >> bettype;
        if (bettype == "exit") break;

        int betamount = getvalidintinput("Enter your bet amount: $");
        if (betamount > balance) {
            cout << "Insufficient balance. Your bet cannot exceed $" << balance << "." << endl;
            continue;
        }

        int betnumber = 0, attribute = 0;
        if (bettype == "number") {
            betnumber = getvalidintinput("Enter the number you want to bet on (0-36): ");
        } else if (bettype == "column" || bettype == "row") {
            string prompt = (bettype == "column") ? "Enter the column (1-3): " : "Enter the row (1-12): ";
            attribute = getvalidintinput(prompt);
        }

        // Generate roulette result
        int result = rand() % 37; // Generate a random number between 0 and 36
        cout << "The roulette wheel is spinning..." << endl;
        for (int i = 0; i < 10; i++) { // Simple animation loop
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        cout << " The result is: " << result << endl;

        // Determine win or loss
        bool win = false;
        if (bettype == "number") {
            win = (betnumber == result);
        } else if (bettype == "red") {
            win = checkattributes(result, "red", 0);
        } else if (bettype == "black") {
            win = !checkattributes(result, "red", 0) && result != 0;
        } else if (bettype == "even") {
            win = (result % 2 == 0) && result != 0;
        } else if (bettype == "odd") {
            win = (result % 2 != 0);
        } else if (bettype == "low") {
            win = (result >= 1 && result <= 18);
        } else if (bettype == "high") {
            win = (result >= 19 && result <= 36);
        } else if (bettype == "column") {
            win = checkattributes(result, "column", attribute);
        } else if (bettype == "row") {
            win = checkattributes(result, "row", attribute);
        }

        if (win) {
            cout << "Congratulations, you won!" << endl;
            balance += betamount;
            wins++;
        } else {
            cout << "Sorry, you lost." << endl;
            balance -= betamount;
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
