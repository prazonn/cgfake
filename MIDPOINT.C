#include <stdio.h>
#include <graphics.h>
 #include <conio.h>
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, 15);
    putpixel(xc - x, yc + y, 15);
    putpixel(xc + x, yc - y, 15);
    putpixel(xc - x, yc - y, 15);
    putpixel(xc + y, yc + x, 15);
    putpixel(xc - y, yc + x, 15);
    putpixel(xc + y, yc - x, 15);
    putpixel(xc - y, yc - x, 15);
}

void midPointCircle(int xc, int yc, int radius)
{
    int x = 0, y = radius;
    int p = 1 - radius;

    // Initial point on the axes
    drawCircle(xc, yc, x, y);

    // When radius is zero, only a single point will be printed at the center
    if (radius > 0)
    {
        // Initial Decision Parameter of the region 1
        while (x < y)
        {
            x++;

            // Mid-point is inside or on the perimeter of the circle
            if (p < 0)
                p = p + 2 * x + 1;

            // Mid-point is outside the perimeter of the circle
            else
            {
                y--;
                p = p + 2 * (x - y) + 1;
            }

            // All the perimeter points have already been printed
            drawCircle(xc, yc, x, y);
        }
    }
}

int main()
{
    int gd = DETECT, gm, xc, yc, radius;

    printf("Enter the center coordinates (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius: ");
    scanf("%d", &radius);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    midPointCircle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
