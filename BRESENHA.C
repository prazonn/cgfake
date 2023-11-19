#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
void drawLine(int x1, int y1,int x2, int y2)
{int dx, dy, p, x, y;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    p = 2 * dy - dx;
    x = x1;
    y = y1;

    while (x <= x2)  // Change this condition to ensure the loop stops after reaching x2
    {
	putpixel(x, y, 15);// Assuming color 15 for the line
        delay(10);

	if (p >= 0)
	{
	    p = p - 2 * dx;  // Corrected the sign here
	    y++;
        }
	else {
	    p = p + 2 * dy;
	    x++;
    }
}}

int main()
{
    int gd = DETECT, gm, x2, y2, x1, y1;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);

    drawLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
