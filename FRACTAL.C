#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>

void fractal(int x1, int y1, int x2, int y2, int m) {
    int xx, yy, x[5], y[5], offx = 50, offy = 300, lx, ly;
    lx = (x2 - x1) / 3;
    ly = (y2 - y1) / 3;
    x[0] = x1;
    y[0] = y1;
    x[4] = x2;
    y[4] = y2;
    x[1] = x[0] + lx;
    y[1] = y[0] + ly;
    x[3] = x[0] + 2 * lx;
    y[3] = y[0] + 2 * ly;
    xx = x[3] - x[1];
    yy = y[3] - y[1];
    x[2] = x[1] + xx * cos(60 * M_PI / 180) - yy * sin(60 * M_PI / 180); //60 degrees = 1.047 radians
    y[2] = y[1] + xx * sin(60 * M_PI / 180) + yy * cos(60 * M_PI / 180);
    if (m > 0) {
        fractal(x[0], y[0], x[1], y[1], m - 1);
        fractal(x[1], y[1], x[2], y[2], m - 1);
        fractal(x[2], y[2], x[3], y[3], m - 1);
        fractal(x[3], y[3], x[4], y[4], m - 1);
    } else {
        line(offx + x[0], offy - y[0], offx + x[1], offy - y[1]);
        line(offx + x[1], offy - y[1], offx + x[2], offy - y[2]);
        line(offx + x[2], offy - y[2], offx + x[3], offy - y[3]);
        line(offx + x[3], offy - y[3], offx + x[4], offy - y[4]);
    }
}

void main() {
    int gd = DETECT, gm, n;
    int x1, x2, y1, y2;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    x1 = 10, x2 = 550, y1 = 0, y2 = 0;
    printf("\nEnter the level of curve generation");
    scanf("%d", &n);
    fractal(x1, y1, x2, y2, n);
    getch();
    closegraph();
}
