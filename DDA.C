#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void drawLine(int x1,int y1,int x2,int y2){
int i, x, y, steps;
int dx = (float)(x2 - x1) / 2;
int dy = (float)(y2 - y1) / 2;

if(dx>=dy){
steps = dx;
}
else{
steps = dy;
}

dx = dx / steps;
dy = dy / steps;

x = x1;
y = y1;

for(i = 0; i <= steps; i++){
putpixel(x,y,RED);
delay(5);
x += dx;
y += dy;
}
}
void main(){

int gd = DETECT, gm;
int x1,y1,x2,y2;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
printf("enter coordinates of 1st point\n");
scanf("%d %d",&x1,&y1);
printf("enter coordinates of 2nd point\n");
scanf("%d %d",&x2,&y2);

drawLine(x1,y1,x2,y2);

getch();
closegraph();
}
