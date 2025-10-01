/**
 * String examples for slides
 * 
 * @author Albert Lionelle
 */
#include <stdio.h>
#include <string.h>

 int main() {
    char str[6] = "Aloha"; // auto adds \0
    printf("%s\n", str);
    printf("Length of \"Aloha\": %zu\n", strlen(str));  // Prints 5
    printf("Size of \"Aloha\": %zu\n", sizeof(str));    // Prints 6

    printf("%c%c!\n", str[3], str[4]);
    str[3] = 'H';
    str[4] = 'A';
    printf("%c%c!\n", str[3], str[4]);

    const char* str2 = "Hello"; // Points to string literal in read-only memory
    //str[0] = 'h';  // Compiler error - cannot modify through this pointer
    str2 = "Aloha";
    printf("%s\n", str2);
 
    const char* const str3 = "Hello";
    //str3 = "Aloha"; // compiler error not allowed
 }