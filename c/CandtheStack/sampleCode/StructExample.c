/**
 * Examples using structs as part of the slides.
 * 
 * @author Albert Lionelle
 */


 struct point2D {
    int x;
    int y;
 }; // dont' forget

 typedef struct rgb {
    int r, g, b;
 } rgb;


 void printColor(rgb *color) {
    printf("Color (%d, %d, %d)\n", color->r, color->g, color->b);
 }

 void updateBlue(rgb color, int blue) {
    color.b = blue;
 }

 void updateGreen(rgb *color, int green) {
    color->g = green;
 }
 
 int main() {
    struct point2D bottomLeft, topLeft;
    
    bottomLeft.x = 0;
    bottomLeft.y = 0;

    topLeft.x = 0;
    topLeft.y = 10;

    rgb background;
    background.r = 0;
    background.g = 0;
    background.b = 0;

    updateBlue(background, 255);

    printColor(&background);
    return 0;
 }
 