// Number guessing game



#include<iostream>
#include <cstdlib>
#include <ctime>   

using namespace std;

int main()
{
    // Seed the random number generator

    srand(static_cast<unsigned int>(time(0)));

    // Generates a random number between 1 and 100

    int randomNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    cout << "I have selected a number between 1 and 100." << endl;

    // Loop until the player guesses right

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You've guessed the number " << randomNumber << " in " << attempts << " attempts." << endl;
        }
    } while (guess != randomNumber);


	return 0;
}
