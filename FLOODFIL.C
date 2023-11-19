#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

void floodfill(int x, int y, int oldcolor, int fillcolor) {
    if (getpixel(x, y) != fillcolor && getpixel(x, y) == oldcolor) {
        delay(1);

        putpixel(x, y, fillcolor);

        floodfill(x + 1, y, oldcolor, fillcolor);
        floodfill(x - 1, y, oldcolor, fillcolor);
        floodfill(x, y + 1, oldcolor, fillcolor);
        floodfill(x, y - 1, oldcolor, fillcolor);
        floodfill(x + 1, y + 1, oldcolor, fillcolor);
        floodfill(x + 1, y - 1, oldcolor, fillcolor);
        floodfill(x - 1, y - 1, oldcolor, fillcolor);
        floodfill(x - 1, y + 1, oldcolor, fillcolor);
    }
}

void main() {
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, RED);
    rectangle(40, 40, 100, 100); // Draw a square

    // Call the flood-fill function starting from a point inside the square
    floodfill(55, 55, getpixel(55, 55), RED);

    getch();
    closegraph();
}
