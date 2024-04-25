#include<graphics.h>
#define MAX_WIDTH 800
#define MAX_HEIGHT 500
int main(){
	initwindow(MAX_WIDTH,MAX_HEIGHT,"MY code");
	int total =1;
	while(!kbhit()){
		int radius=10+(rand()%100);
		int left=1+(rand()%MAX_WIDTH);
		int top=1+(rand()%MAX_HEIGHT);
		int color=1+(rand()%16);
		int fs=1+(rand()%10);
		setfillstyle(fs,color);
		setcolor(color);
		circle(left,top,color);
		floodfill(left,top,color);
		delay(200);
		if(total>30){
			cleardevice();
			total=1;
		}
		total++;
	}
	getch();
	closegraph();
	return 0;
}
