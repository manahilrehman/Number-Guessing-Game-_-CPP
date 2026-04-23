#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate random number
int generateNumber(int maxRange) {
    return rand() % maxRange + 1;
}

// Function to display difficulty menu
int chooseDifficulty() {
    int choice;
    cout << "Choose Difficulty Level:\n";
    cout << "1. Easy (1-50, 10 attempts)\n";
    cout << "2. Medium (1-100, 7 attempts)\n";
    cout << "3. Hard (1-200, 5 attempts)\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function to play game
void playGame() {
    int difficulty = chooseDifficulty();
    int maxRange, maxAttempts;

    // Set difficulty
    if (difficulty == 1) {
        maxRange = 50;
        maxAttempts = 10;
    } 
    else if (difficulty == 2) {
        maxRange = 100;
        maxAttempts = 7;
    } 
    else {
        maxRange = 200;
        maxAttempts = 5;
    }

    int number = generateNumber(maxRange);
    int guess, attempts = 0;
    int score = 100;

    cout << "\nGuess the number between 1 and " << maxRange << endl;

    while (attempts < maxAttempts) {
        cout << "Attempt " << attempts + 1 << "/" << maxAttempts << ": ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too High!\n";
        } 
        else if (guess < number) {
            cout << "Too Low!\n";
        } 
        else {
            cout << "?? Correct Guess!\n";
            cout << "Your Score: " << score << endl;
            return;
        }

        score -= 10;
    }

    cout << "\n? You lost! The number was: " << number << endl;
}

// Main function
int main() {
    srand(time(0));

    char playAgain;

    do {
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThank you for playing! ??\n";
    return 0;
}