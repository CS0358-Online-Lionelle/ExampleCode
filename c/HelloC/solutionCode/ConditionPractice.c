/**
 * Solution for ConditionPractice Code Along
 * 
 * This program explores condition statements in C.
 * 
 * @author Albert Lionelle
 * @date 2025-04-03
 */

#include <stdio.h>
#include <stdlib.h>

void simpleConditionPractice(int lower, int upper) {
    // if statement
    if(lower < upper) {
        printf("Lower is less than upper\n");
    } else if(lower > upper) {
        printf("Lower is greater than upper\n");
    } else {
        printf("Lower is equal to upper\n");
    }

    // one line if
    if (lower < upper) printf("Lower is less than upper\n");
    else printf("Lower is not less than upper\n");
}

void complexConditionPractice(int lower, int upper) {
    // if with logical operators
    if(lower < upper && lower > 0) { // 0 < lower < upper <- not allowed!
        printf("Lower is less than upper and greater than 0\n");
    } else if(lower > upper || lower < 0) {
        printf("Lower is either greater than upper or less than 0\n");
    }else {
        printf("Lower if equal to upper and greater than or equal to 0\n");
    }

    // just using in values
    if(lower - upper) {
        printf("Lower is not equal to upper\n");
    }else {
        printf("Lower is equal to upper\n");
    }

}


int main() {
    int lower = 5;
    int upper = 10;

    printf("Simple Condition Practice with (%d, %d)\n", lower, upper);
    simpleConditionPractice(lower, upper);
    complexConditionPractice(lower, upper);

    lower = 10;
    upper = 10;

    printf("Simple Condition Practice with (%d, %d)\n", lower, upper);
    simpleConditionPractice(lower, upper);
    complexConditionPractice(lower, upper);


    printf("\n");
    return 0;
}
