/**
 * Solution code for Loop Practice Code Along
 * 
 * This program demonstrates the use of loops in C.
 * 
 * @author Albert Lionelle
 * @date 2025-04-03
 */

#include <stdio.h>
#include <stdlib.h>



void forLoopPractice(int start, int end) {
    //for loop
    for (int i = start; i < end; i++) {
        printf("For Loop %d\n", i);
    }

    // reverse loop
    for (int i = end - 1; i >= start; i--) {
        printf("For Loop Reverse %d\n", i);
    }

    for (int i = start; i < end; i += 2) {
        printf("For Loop with Step: %d\n", i);
    }
}

void whileLoopPractice(int start, int end) {
    // while loop
    int i = start;
    while(i < end) {
        printf("While Loop: %d\n", i);
        i++;
    }

    i = end - 1;
    while (i >= start) {
        printf("While Loop Reversed: %d\n", i);
        i--;
    }

    // now with a step
    i = start;
    while (i < end) {
        printf("While Loop with Step: %d\n", i);
        i += 2;
    }
}

void whileLoopMenu() {
    int choice = 0;
    while (choice != 3) {
        printf("1. For Loop\n");
        printf("2. While Loop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                forLoopPractice(0, 10);
                break;
            case 2:
                whileLoopPractice(0, 10);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    whileLoopMenu();
    return 0;
}