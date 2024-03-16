#include<stdio.h>
#include<graphics.h>

int drawcircle(int x0, int y0, int rd)
{
    int x = rd;
    int y = 0;
    int Po = 0;
 
    while (x >= y)
    {
putpixel(x0 + x, y0 + y, 7);
putpixel(x0 + y, y0 + x, 7);
putpixel(x0 - y, y0 + x, 7);
putpixel(x0 - x, y0 + y, 7);
putpixel(x0 - x, y0 - y, 7);
putpixel(x0 - y, y0 - x, 7);
putpixel(x0 + y, y0 - x, 7);
putpixel(x0 + x, y0 - y, 7);
 
if (Po <= 0)
{
    y = y+ 1;
    Po = Po+ 2*y + 1;
}
 
if (Po > 0)
{
    x = x- 1;
    Po = Po -2*x + 1;
}
    }
}
 
int main()
{
  int  Po, x, y, r;
printf("\nEnter radius of circle: ");
scanf("%d", &r);

printf("\nEnter co-ordinates of center as ");
printf("\nX = ");
scanf("%d",&x);
printf("\nY = ");
scanf("%d",&y);
int gd = DETECT, gm = DETECT;
   initgraph(&gd,&gm,(char*)"");
drawcircle(x, y, r);
getch();
closegraph();
return 0;
}

