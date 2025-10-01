/**
 * Provides sample code for passing pointers to functions
 * 
 * @author Albert Lionelle
 */


 void setToSeven(int* number) {
    *number = 7;
 }

 int main() {
    int number = 42;
    setToSeven(&number);
 }

 