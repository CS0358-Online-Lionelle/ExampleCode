/**
 * Solution for Code Along Guessing Game Part 3
 *
 */

#include <stdbool.h> // for bool type
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for string manipulation
#include <time.h>   // for random number generation


#include "GuessingGame.h" // Include the header file for function declarations

int getRandomNumber(int min, int max) {
  // Generate a random number between min and max
  return (rand() % (max - min + 1)) + min;
}

GameState *initializeGameState(int maxAttempts, int playerType, int min,
                               int max) {
  GameState *gameState = (GameState *)malloc(sizeof(GameState));
  gameState->guesses = (int *)malloc(sizeof(int) * maxAttempts);
  gameState->attempts = 0;
  gameState->maxAttempts = maxAttempts;
  gameState->playerType = playerType;
  gameState->min = min;
  gameState->max = max;
  return gameState;
}

void freeGameState(GameState *gameState) {
  free(gameState->guesses);
  free(gameState);
}

int getInput() {
  char buffer[20];
  int input = 0;
  scanf("%s", buffer);
  input = atoi(buffer);
  return input;
}

int _requestInput(int min, int max) {
  printf("Enter your guess (%d-%d): ", min, max);
  return getInput();
}

int _getNextNumber(int result, GameState *gameState) {
  if (gameState->attempts < 1) {
    return (gameState->min + gameState->max) / 2;
  }
  int lastGuess = gameState->guesses[gameState->attempts - 1];
  if (result < 0) {
    gameState->min = lastGuess + 1;
    return (gameState->min + gameState->max) / 2;
  } else {
    gameState->max = lastGuess - 1;
    return (gameState->min + lastGuess) / 2;
  }
}
// a game that only gives X number of choices
// track the number of attempts
// i want to track the guesses
bool runGame(int randomNumber, GameState *gameState) {
  int guess = 0;
  int result = 0;
  while (gameState->attempts < gameState->maxAttempts) {
    if (gameState->playerType == COMPUTER) {
      guess = _getNextNumber(result, gameState);
    } else {
      guess = _requestInput(gameState->min, gameState->max);
    }
    gameState->guesses[gameState->attempts++] = guess;

    result = guess - randomNumber;
    if (result == 0) {
      return true;
    } else if (gameState->playerType == HUMAN) {
      feedback(result);
    }
  }
  return false;
}

void feedback(int state) {
  if (state < 0) {
    printf("Too low! Try again.\n");
  } else if (state > 0) {
    printf("Too high! Try again.\n");
  }
}

void giveFeedback(int randomNumber, bool found, GameState *gameState) {
  if (found) {
    printf("Congratulations! %s guessed the number %d in %d attempts.\n",
           gameState->playerType == HUMAN ? "You" : "The Computer",
           randomNumber, gameState->attempts);
  } else {
    printf("Game Over! The number was %d.\n", randomNumber);
  }
  printf("%s guesses were: ",
         gameState->playerType == HUMAN ? "Your" : "The computer's");
  for (int i = 0; i < gameState->attempts; i++) {
    printf("%d ", gameState->guesses[i]);
  }
  printf("\n\n");
}

void _printMenu() {
  printf("Play Game\n"); // play or exit
  printf("Exit\n");
  printf("Enter your choice (play | exit): ");
}

void start() {
  printf("Welcome to the Guessing Game!\n");
  char choice[20];

  while (strcasecmp(choice, "exit") != 0) {
    _printMenu();
    scanf("%s", choice);

    if (strcasecmp(choice, "play") == 0) {
      printf("Starting the game...\n");
      int randomNumber = getRandomNumber(DEFAULT_MIN, DEFAULT_MAX);
      GameState *human = initializeGameState(DEFAULT_MAX_ATTEMPTS, HUMAN,
                                             DEFAULT_MIN, DEFAULT_MAX);
      bool found = runGame(randomNumber, human);
      giveFeedback(randomNumber, found, human);

      GameState *computer = initializeGameState(DEFAULT_MAX_ATTEMPTS, COMPUTER,
                                                DEFAULT_MIN, DEFAULT_MAX);
      found = runGame(randomNumber, computer);
      giveFeedback(randomNumber, found, computer);

      if (computer->attempts < human->attempts) {
        printf("The computer won!\n");
      } else if (computer->attempts > human->attempts) {
        printf("You won!\n");
      } else {
        printf("It's a tie!\n");
      }

      freeGameState(human);
      freeGameState(computer);

    } else if (strcasecmp(choice, "exit") == 0) {
      printf("Exiting the game...\n");
    } else {
      printf("Invalid choice. Please try again.\n");
    }
  }
}