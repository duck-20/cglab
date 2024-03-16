#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,(char*)"");  
	
	int xa, xb, ya, yb, i;
	float dx, dy, p, x, y, xend;
	
	printf("Enter (xa, ya):");
	scanf("%d %d", &xa, &ya);
	
	printf("Enter (xb, yb):");
	scanf("%d %d", &xb, &yb);
	
	dx=xb-xa;
	dy=yb-ya;
	
	x=xa;
	y=ya;
	
	p=2*dy-dx;
	while(x<xb)
	{	
		if(p>=0)
		{
			putpixel(x,y,WHITE);
			y++;
			p=p+2*dy-2*dx;
		}
		else
		{
			putpixel(x,y,WHITE);
			p=p+2*dy;
		}
		x++;
	}
	
	while(x>xb)
	{
		if(p>=0)
		{
			putpixel(x,y,WHITE);
			y++;
			p=p+2*dy-2*dx;
		}
		else
		{
			putpixel(x,y,WHITE);
			p=p+2*dy;
		}
		x--;
	}
	getch();
	return 0;
}


