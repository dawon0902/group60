#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

struct Card {
    string face;  
    string suit;  
    int value;   
};

class Deck {
private:
    vector<Card> cards;  

public:
    Deck() {
        const string faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        const string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        const int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}; // Ace initially as 11

        // Initialize the deck with each suit containing 13 cards
        for (const auto &suit : suits) {
            for (int i = 0; i < 13; ++i) {
                Card card = {faces[i], suit, values[i]};
                cards.push_back(card);
            }
        }
    }

    void shuffle() {
        srand(time(0));  // Use current time as seed for random generator
        for (int i = 0; i < cards.size(); ++i) {
            int index = rand() % cards.size();
            swap(cards[i], cards[index]);  // Randomly swap card positions to shuffle the deck
        }
    }

    Card deal() {
        Card card = cards.back();  // Take the last card from the deck
        cards.pop_back();  // Remove this card from the deck
        return card;
    }
};

int getHandValue(const vector<Card>& hand) {
    int value = 0;
    int aces = 0;  

    // Calculate total point value of hand, counting Aces as 11 initially
    for (const auto& card : hand) {
        value += card.value;
        if (card.face == "Ace") {
            aces++;
        }
    }

    // If total value exceeds 21 and there are Aces counted as 11, reduce their value to 1
    while (value > 21 && aces > 0) {
        value -= 10; // Convert an Ace from 11 to 1
        aces--;
    }

    return value;
}

void showHand(const vector<Card>& hand, bool hideSecondCard = false) {
    for (int i = 0; i < hand.size(); ++i) {
        if (hideSecondCard && i == 1) {
            cout << "Hidden Card" << endl;  // Hide dealer's second card
        } else {
            cout << hand[i].face << " of " << hand[i].suit << endl;  // Show card face and suit
        }
    }
}

int getValidIntInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input <= 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid input, please enter a positive number." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return input;
        }
    }
}

int playBlackjack() {
    int balance = 1000; // Start with a balance of 1000
    char playAgain = 'y';

    while (playAgain == 'y') {
        Deck deck;
        deck.shuffle();

        vector<Card> playerHand;
        vector<Card> dealerHand;

        playerHand.push_back(deck.deal());
        playerHand.push_back(deck.deal());
        dealerHand.push_back(deck.deal());
        dealerHand.push_back(deck.deal());

        int bet = getValidIntInput("You have $" + to_string(balance) + ". How much would you like to bet? $");

        while (bet > balance) {
            cout << "You cannot bet more than your current balance. Please try again.\n";
            bet = getValidIntInput("You have $" + to_string(balance) + ". How much would you like to bet? $");
        }

        balance -= bet;  

        cout << "Dealer's Hand:" << endl;
        showHand(dealerHand, true);  // Show dealer's hand with the second card hidden
        cout << "\nYour Hand:" << endl;
        showHand(playerHand);  // Show player's hand

        char decision;
        do {
            cout << "Your hand value: " << getHandValue(playerHand) << endl;
            if (getHandValue(playerHand) > 21) {
                cout << "Bust! You lose." << endl;
                break;  // Player busts and loses the bet
            }

            cout << "Hit or Stand? (h/s): ";
            cin >> decision;
            if (decision == 'h') {
                playerHand.push_back(deck.deal());
                cout << "You drew: " << playerHand.back().face << " of " << playerHand.back().suit << endl;
            }
        } while (decision == 'h');  // Continue to hit until the player chooses to stand

        if (getHandValue(playerHand) <= 21) {
            cout << "\nDealer's turn." << endl;
            showHand(dealerHand);  // Show all dealer's cards

            while (getHandValue(dealerHand) < 17) {
                dealerHand.push_back(deck.deal());
                cout << "Dealer drew: " << dealerHand.back().face << " of " << dealerHand.back().suit << endl;
            }

            cout << "Dealer's hand value: " << getHandValue(dealerHand) << endl;
            if (getHandValue(dealerHand) > 21) {
                cout << "Dealer busts! You win." << endl;
                balance += bet * 2;  // Player wins and gets twice the bet amount
            } else if (getHandValue(dealerHand) > getHandValue(playerHand)) {
                cout << "Dealer wins." << endl;
            } else if (getHandValue(dealerHand) < getHandValue(playerHand)) {
                cout << "You win!" << endl;
                balance += bet * 2;  // Player wins and gets twice the bet amount
            } else {
                cout << "It's a tie!" << endl;
                balance += bet;  // Return the bet amount to the player
            }
        }

        cout << "Your current balance is $" << balance << endl;
        if (balance <= 0) {
            cout << "You've run out of money! Game over." << endl;
            break;  // End the game if the player runs out of money
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;  // Ask the player if they want to play another round
    }

    return 0;
}
