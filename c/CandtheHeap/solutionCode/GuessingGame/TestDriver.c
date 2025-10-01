/**
 * Sample file for Guessing Game Code Along Part 3
 *
 * This file contains various tests.
 *
 * @author Albert Lionelle
 * @date 2024-04-10
 */

#include "GuessingGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testMallocAndFree() {
  GameState *one = initializeGameState(10, 0, 0, 100);
  GameState *two = initializeGameState(10, 1, 0, 100);

  freeGameState(one);
  freeGameState(two);
}

void testGetInput() {
  printf("Enter a value: ");
  int myValue = getInput();
  printf("Testing my value by entering 10, the results is %d\n\n", myValue);
}

void testFeedback() {
  int state = 50 - 48;
  feedback(state);
  state = 23 - 48;
  feedback(state);
}

void testGiveFeedback() {
  GameState *human = initializeGameState(10, HUMAN, 0, 100);
  human->attempts = 1;
  human->guesses[0] = 30;

  GameState *computer = initializeGameState(10, COMPUTER, 0, 100);
  computer->attempts = 2;
  computer->guesses[0] = 15;
  computer->guesses[1] = 3;

  giveFeedback(30, true, human);
  giveFeedback(99, false, computer);

  freeGameState(human);
  freeGameState(computer);
}

int main() {
  srand(0); // Seed the random number generator with a fixed value for
            // reproducibility
  int randomNumber = getRandomNumber(DEFAULT_MIN, DEFAULT_MAX);
  printf("Random number generated: %d\n", randomNumber);

  // testGetInput();
  // testMallocAndFree();
  // testFeedback();
  testGiveFeedback();
  return 0;
}
