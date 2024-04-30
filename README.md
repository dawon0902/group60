# group60

## Team members

Bi Zi Xuan

Chung Dawon

## Game 1: Blackjack
   
### Description and Rules

Blackjack is a popular card game where the goal is to have your cards total to a higher value than the dealer's cards without exceeding 21. Each player starts with two cards, and can choose to "hit" (take another card) or "stand" (end their turn). Face cards (Jack, Queen, King) are worth 10 points, Aces can be worth 1 or 11, and other cards are worth their face value.

### Implemented Features and Coding Requirements

1. Generation of random game sets or events: The deck is shuffled using a random number generator to ensure each game is unique.
2. Data structures for storing game status: The game uses vector<Card> to store the player's and dealer's hands, efficiently managing the dynamic card distribution.
3. Dynamic memory management: Vectors handle dynamic memory allocation internally, adjusting storage as cards are dealt.
4. File input/output: Not implemented in the provided snippet, but could be added to save game state or player statistics.
5. Program codes in multiple files: While the provided code is a single snippet, it can be modularized into separate files for better manageability (e.g., separating class definitions and main gameplay logic).

## Game 2: Roulette

### Description and Rules

Roulette is a casino game where players bet on which number or color a ball will land on a spinning wheel. Players can bet on individual numbers, red or black colors, even or odd numbers, high (19-36) or low (1-18) numbers, columns, or rows.

### Implemented Features and Coding Requirements

1. Generation of random game sets or events: Random numbers are generated to simulate the spinning of the roulette wheel.
2. Data structures for storing game status: The game uses simple variables to track the player's balance and bet details, suitable for the game's straightforward logic.
3. Dynamic memory management: Not explicitly required here as the game uses basic data types, but dynamic behavior could be introduced for more complex betting systems.
4. File input/output: Not implemented in the provided snippet, but could be added for features like saving game history or player balances.
5. Program codes in multiple files: As with Blackjack, while the provided code is a single snippet, separating functionality into different files could enhance maintainability.

### Non-standard C/C++ Libraries

<thread> and <chrono>: Used to create a simple delay to simulate the spinning of the roulette wheel, enhancing user experience by providing a visual delay.

