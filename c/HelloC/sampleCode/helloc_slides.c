/* 
 
 Printing Aloha, World in C.
 This is also a multi-line comment.
*/

#include <stdio.h>
#include <stdlib.h>


void inputExample() {
    int x = 0;
    printf("Enter a number: ");
    scanf("%d", &x); // &x is the address of x
    printf("Aloha, World! %d is the answer...\n", x);
}

void forExample() {
    for (int i = 0; i < 5; i++) {
        printf("Aloha, World!\n");
    }

    for (int i = 5; i > 0; i--) {
        printf("Aloha, World!\n");
        if (i == 2) {
            break; // exit the loop
        }
    }

    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            continue; // skip the rest of the loop
        }
        printf("Aloha, World!\n");
    }


}

void whileExample() {
    int i = 0; // declare and initialize i
    while (i < 5) {
        printf("Aloha, World!\n");
        i++; // similar as i = i + 1
        // i += 1; is also good here
    }

    while(i) { // this works since 0 is false
        printf("Aloha, World!\n");
        i--; // similar as i = i - 1
        // i -= 1; is also good here
    } 
}

void conditionExample() {
    int x = 0;
    if (x == 0) {
        printf("Aloha, World!\n");
    } else {
        printf("Ciao, World!\n");
    }

    x = 2;
    int y = 0;
    if (x > 1 && y < 2) {
        printf("Aloha, World!\n");
    } else if (x > 1 || y < 2) {
        printf("Ciao, World!\n");
    } else {
        printf("Hola, World!\n");
    }
}

int myAddition(int a, int b) {
    int tmp = a + b;
    return tmp; 
}

void printHelloWorld() {
    printf("Aloha, World!\n");
}

int main() {
    int x = 40 + 2;     // This is a single comment
    printf("Aloha, World! %d is the answer...\n", x);
    int y = myAddition(x, 10);
    return 0;
}