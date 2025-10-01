/**
 * Sample code used in slides for Dive into C module
 * in CS 5008.asm
 * 
 * @author Albert Lionelle
 */

#include <stdio.h>

int main() {
    int number = 42;
    int *ptr = &number;

    *ptr = 7; // number is now 7
}