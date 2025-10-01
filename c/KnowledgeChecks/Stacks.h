/** 
 * Code for knowledge checks.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int do_something(int multiplier) {
    char * str = "Aloha!"; 
    int vals[5] = {13, 11, 9, 7, 5};
    int n1 = strlen(str);
    int diff = (n1 - vals[4]) + multiplier;
    return diff;
}
