/**
 * Starter code for Code Along on Longest Common Substring
 * using Dynamic Programming.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "DPUtils.h"

int _debug = 0;

enum { TABULATION = 2, NO_TABULATION = 1 };

char *longest_common_substring_no_tabulation(const char *str_one,
                                             const char *str_two) {

  return NULL;
}

char *longest_common_substring_with_tabulation(const char *str_one,
                                               const char *str_two) {
  return NULL;
}

int time_substring(char *(*func)(const char *, const char *),
                   const char *str_one, const char *str_two) {
  clock_t start = clock();
  char *result = func(str_one, str_two);
  clock_t end = clock();
  if (result) {
    printf("Longest common substring (length: %ld): %s\n", strlen(result),
           result);
  } else {
    printf("No common substring found.\n");
  }
  free(result); // Free the allocated memory for the substring
  return (int)(end - start);
}

int main(int argc, char const *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <string1> <string2>\n", argv[0]);
    return 1;
  }
  const char *str_one = argv[1];
  const char *str_two = argv[2];

  int type = NO_TABULATION | TABULATION; // Default to both methods
  if (argc > 3) {
    type = atoi(argv[3]);
    if (type < NO_TABULATION || type > TABULATION) {
      printf(
          "Error: Invalid type. Use %d for no tabulation, %d for tabulation, "
          "or %d for both.\n",
          NO_TABULATION, TABULATION, NO_TABULATION | TABULATION);
      return 1;
    }
  }

  if (argc > 4) {
    _debug = atoi(argv[3]);
  }

  if ((type & NO_TABULATION) == NO_TABULATION) {
    printf("Longest common substring without tabulation (m^2 * n)\n");
    int time_taken = time_substring(longest_common_substring_no_tabulation,
                                    str_one, str_two);
    printTimeTaken(time_taken);
  }
  if ((type & TABULATION) == TABULATION) {
    printf("Longest common substring with tabulation (m * n)\n");
    int time_taken_tabulation = time_substring(
        longest_common_substring_with_tabulation, str_one, str_two);
    printTimeTaken(time_taken_tabulation);
  }

  return 0;
}
