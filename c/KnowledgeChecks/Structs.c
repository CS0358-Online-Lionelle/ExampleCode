#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
  } Point;

  Point * new_point(int x, int y) {
    Point pt = {x, y};
    return &pt;
  }

  int main() {
     Point* point = new_point(10, 10);
     printf("x: %d, y: %d", point->x, point->y);
     return 0;
  }

