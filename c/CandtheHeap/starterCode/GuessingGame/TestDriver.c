/**
 * Test Driver For GuessingGame Part 3 Code Along
 */

#include "GuessingGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(0); // Seed the random number generator with a fixed value for
            // reproducibility
  int randomNumber = getRandomNumber(DEFAULT_MIN, DEFAULT_MAX);
  printf("Random number generated: %d\n", randomNumber);
  return 0;
}
