#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int x1, x2, x3, y1, y2, y3, nx1, nx2, nx3, ny1, ny2, ny3, c;
    int sx, sy, xt, yt, r;
    float t;

    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    printf("Program for basic Transformations\n");
    printf("Enter the coordinates of the triangle\n");
    scanf("%d%d%d%d%d%d", &x1, &x2, &x3, &y1, &y2, &y3);

    setcolor(10);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();

    printf("\n1.Translation\n2.Rotation\n3.Scaling\n");
    printf("Enter your Choice: ");
    scanf("%d", &c);

    switch (c) {
    case 1:
	printf("\nEnter the translation factor: ");
	scanf("%d%d", &xt, &yt);
	nx1 = x1 + xt;
	ny1 = y1 + yt;
	nx2 = x2 + xt;
	ny2 = y2 + yt;
	nx3 = x3 + xt;
	ny3 = y3 + yt;
	setcolor(15);
	line(nx1, ny1, nx2, ny2);
	line(nx2, ny2, nx3, ny3);
	line(nx3, ny3, nx1, ny1);

    case 2:
	printf("\nEnter the rotation angle: ");
	scanf("%d", &r);
	t = 3.14 * r / 180;
	nx1 = x1 * cos(t) - y1 * sin(t);
	ny1 = x1 * sin(t) + y1 * cos(t);
	nx2 = x2 * cos(t) - y2 * sin(t);
	ny2 = x2 * sin(t) + y2 * cos(t);
	nx3 = x3 * cos(t) - y3 * sin(t);
	ny3 = x3 * sin(t) + y3 * cos(t);
	setcolor(12);
	line(nx1, ny1, nx2, ny2);
	line(nx2, ny2, nx3, ny3);
	line(nx3, ny3, nx1, ny1);

    case 3:
	printf("\nEnter the Scaling Factor: ");
	scanf("%d%d", &sx, &sy);
	nx1 = x1 * sx;
	ny1 = y1 * sy;
	nx2 = x2 * sx;
	ny2 = y2 * sy;
	nx3 = x3 * sx;
	ny3 = y3 * sy;
	setcolor(14);
	line(nx1, ny1, nx2, ny2);
	line(nx2, ny2, nx3, ny3);
	line(nx3, ny3, nx1, ny1);
	getch();
    case 4:
    default:
	printf("Enter correct choice");
    }

    closegraph();
    getch();
}

