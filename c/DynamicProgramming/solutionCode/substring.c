/**
 * Solution Code for Substring Problem Code Along
 *
 * @author Albert Lionelle
 * @date 2025-01-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "DPUtils.h"

int _debug = 0;

enum { TABULATION = 2, NO_TABULATION = 1 };

char *get_substring(int max_len, int end_index, const char *str_one) {
  if (max_len <= 0 || end_index <= 0) {
    return NULL; // No common substring found
  }
  char *result = (char *)malloc((max_len + 1) * sizeof(char));
  if (!result) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  strncpy(result, str_one + end_index - max_len, max_len);
  result[max_len] = '\0';
  return result;
}

char *longest_common_substring_no_tabulation(const char *str_one,
                                             const char *str_two) {

  int len1 = strlen(str_one);
  int len2 = strlen(str_two);
  int max_len = 0;
  int end_index = 0;

  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      int k = 0;
      while (i + k < len1 && j + k < len2 && str_one[i + k] == str_two[j + k]) {
        k++;
      }
      if (k > max_len) {
        max_len = k;
        end_index = i + k;
      }
    }
  }

  return get_substring(max_len, end_index, str_one);
}

char *longest_common_substring_with_tabulation(const char *str_one,
                                               const char *str_two) {
  int len1 = strlen(str_one);
  int len2 = strlen(str_two);
  int max_len = 0;
  int end_index = 0;

  // Create a 2D array for storing lengths of longest common suffixes
  int dp[len1 + 1][len2 + 1]; // Initialize to 0
  memset(dp, 0, sizeof(dp));  // Set all elements to 0

  // Fill the dp array and find the maximum length
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str_one[i - 1] == str_two[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > max_len) {
          max_len = dp[i][j];
          end_index = i;
        }
      }
    }
  }

  if (_debug)
    printMatrix((int *)dp, len2 + 1, len1 + 1); // Print the dp array

  return get_substring(max_len, end_index, str_one);
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
    printf("Longest common substring without tabulation (m^2 * n^2)\n");
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
