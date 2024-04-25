#include<graphics.h>
void boundaryFill(int x,int y,int fill_col,int boundary_col)
{
	if(getpixel(x,y)!=boundary_col && getpixel(x,y)!=fill_col)
	{
		putpixel(x,y,fill_col);
		boundaryFill(x+1,y,fill_col,boundary_col);
		boundaryFill(x-1,y,fill_col,boundary_col);
		boundaryFill(x,y+1,fill_col,boundary_col);
		boundaryFill(x,y-1,fill_col,boundary_col);
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	int x=250,y=200,radius=70;
	circle(x,y,radius);
	boundaryFill(x,y,6,15);
	delay(1000);
	getch();
	closegraph();
	return 0;
	
	
}
