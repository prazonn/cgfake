#include<stdio.h>
 #include<stdlib.h>
 #include<conio.h>
 #include<graphics.h>
 #include<dos.h>
 void boundaryfill(int x, int y, int boundary, int fill)
 {
 if((getpixel(x,y) != boundary) && (getpixel(x,y) != fill))
 {
 setcolor(fill);
 putpixel(x,y,fill);
 delay(5);
 boundaryfill(x+1,y,fill,boundary);
 boundaryfill(x-1,y,fill,boundary);
 boundaryfill(x,y+1,fill,boundary);
 boundaryfill(x,y-1,fill,boundary);
 }
 }
 void main()
 {
 int gd= DETECT,gm;
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 setcolor(10);
 rectangle(250,200,310,260);
 boundaryfill(280,250,12,10);
 getch();
 closegraph();
 }
