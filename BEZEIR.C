#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h> // Include math.h for pow function

void bezier(int x[4], int y[4])
{
    int gd = DETECT, gm, i;
    double t;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];  
        double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];

        putpixel((int)xt, (int)yt, WHITE); // Convert double to int for putpixel
    }

    for (i = 0; i < 4; i++)
        putpixel(x[i], y[i], YELLOW);

    getch();
    closegraph();
}

int main()
{
    int x[] = {100, 200, 300, 400};
    int y[] = {300, 100, 300, 400};

    bezier(x, y);

    return 0;
}
