/**
 * Solution to Function Practice Code Along
 * 
 * This program demonstrates the use of functions in C.
 * 
 * @author Albert Lionelle
 * @date 2025-04-03
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h> 
 
 
 double add(double a, double b) {
     return a + b;
 }
 
 double subtract(double a, double b) {
     return a - b;
 }
 
 double multiply(double a, double b) {
     return a * b;
 }
 
 double divide(double a, double b) {
     if (b == 0) {
         printf("Error: Division by zero\n");
         return 0;    
     }
     return a / b;
 }
 
 double modulus(int64_t a, int64_t b) {
     if (b == 0) {
         printf("Error: Division by zero\n");
         return 0;    
     }
     return a % b; // remainder
 }
 
 
 int main() {
     long a = 100;
     short b = 6;
 
     printf("Addition: %.2f\n", add(a,b));
     printf("Subtraction: %.2f\n", subtract(a,b));
     printf("Multiplication: %.2f\n", multiply(a,b));
     printf("Division: %.2f\n", divide(a,b));
     printf("Modulus: %.0f\n", modulus(a, b));
 
     return 0;
 }
