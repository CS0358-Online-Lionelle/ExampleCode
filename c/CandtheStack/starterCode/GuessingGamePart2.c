/** 
 * Initial starter code for Guessing Game Part 2.
 * 
 * This code is based off code generated for the Code Along
 * Guessing Game example. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random number generation


int getRandomNumber(int min, int max) {
    // Generate a random number between min and max
    return (rand() % (max - min + 1)) + min;
}

int getInput() {
    int input = 0;
    scanf("%d", &input); // not safe, fix in future!
    return input; 
}

int runGame(int randomNumber) {
    int guess = 0;
    int attempts = 0;

    while (guess != randomNumber) {
        printf("Enter your guess (1-100): ");
        guess = getInput();
        attempts++;

        if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", randomNumber, attempts);
        }
    }

    return attempts;
}

void start() {
    printf("Welcome to the Guessing Game!\n");
    int choice = 0;

    while(choice != 2) {
        printf("1. Play Game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        choice = getInput();

        if (choice == 1) {
            // Call the game function here
            int randomNumber = getRandomNumber(1, 100);
            printf("Starting the game...\n");
            runGame(randomNumber);
        } else if (choice == 2) {
            printf("Exiting the game...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

}

int main() {
    srand(time(NULL)); // Seed the random number generator
    start(); // Start the game menu
    return 0;
}