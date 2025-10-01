/** 
 * Solution to Type Practice Code Along
 * 
 * This program demonstrates the use of various data types in C.
 * 
 * @author Albert Lionelle
 * @date 2025-04-02
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool type
#include <stdint.h> // for uint64_t type

void sizeExample() {
    // sizeof(type or variable)
    //char myLetter = 'H';
    printf("Size of char:  %zu bytes\n", sizeof(char));
    printf("Size of int:  %zu bytes\n", sizeof(int));
    printf("Size of short:  %zu bytes\n", sizeof(short));
    printf("Size of long:  %zu bytes\n", sizeof(long));
    // floating point numbers also called decimals
    printf("Size of float:  %zu bytes\n", sizeof(float));
    printf("Size of double:  %zu bytes\n", sizeof(double));
    printf("Size of long double:  %zu bytes\n", sizeof(long double));

    // now some special types
    //bool x = true;
    printf("Size of bool: %zu bytes\n", sizeof(bool));
    printf("Size of uint64_t:  %zu bytes\n", sizeof(uint64_t));

}

int main() {
    sizeExample();
    return 0;
}