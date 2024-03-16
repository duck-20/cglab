#include<conio.h>
#include<stdio.h>
#include<graphics.h>
	int main()
	{
		int gm,gd=DETECT,ax,x1=100;
		int x2=100,x3=200,y1=100;
		int y2=200,y3=100;
		
		initgraph(&gd,&gm,(char*)"");
		
		line(getmaxx()/2,0,getmaxx()/2,getmaxy()/2);
		line(0,getmaxy()/2,getmaxx()/2,getmaxy()/2);
		
		printf("Before Reflection \n 2nd Quadrant");
		
		setcolor(14);
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);

		
		printf("\n After Reflection");
		setcolor(4);
		line(getmaxx()-x1,getmaxy()-y1,getmaxx()-x2,getmaxy()-y2);
		line(getmaxx()-x2,getmaxy()-y2,getmaxx()-x3,getmaxy()-y3);
		line(getmaxx()-x3,getmaxy()-y3,getmaxx()-x1,getmaxy()-y1);
		
		setcolor(3);
		line(getmaxx()-x1,y1,getmaxx()-x2,y2);
		line(getmaxx()-x2,y2,getmaxx()-x3,y3);
		line(getmaxx()-x3,y3,getmaxx()-x1,y1);
		
		setcolor(2);
		line(x1,getmaxy()-y1,x2,getmaxy()-y2);
		line(x2,getmaxy()-y2,x3,getmaxy()-y3);
		line(x3,getmaxy()-y3,x1,getmaxy()-y1);
		
		getch();
	}
