/**
Code used in knowledge checks.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_str() {
    char str[] = {'A', 'l', 'o', 'h', 'a', '\0'}; 
    str[3] = '\0';
    return strlen(str);
}


int main() {
    printf("Length of str: %d\n", length_str());
    return 0;
}