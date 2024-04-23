//Write program to implement Cohen Sutherland Hodgman algorithm to clip any polygon. Provide thevertices of the polygon to be clipped and pattern of clipping interactively.
#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
typedef struct
{
float x;
float y;
}pt;
int n;
void drawpolygon(pt[],int);
void top(pt,pt[],pt[]);
void bottom(pt,pt[],pt[]);
void left(pt,pt[],pt[]);
void right(pt,pt[],pt[]);
int main()
{
int gd=DETECT,gm;
int i,j;
pt d,p1,p2,p[20],pi1,pi2,pp[20];
cout<<"\n Enter cordinates (left,top)";
cout<<"\n Enter X cordinates :";
cin>>p1.x;
cout<<"\n Enter Y cordinates :";
cin>>p1.y;
cout<<"\n Enter cordinates (right,bottom)";
cout<<"\n Enter X cordinates :";
cin >>p2.x;
cout<<"\n Enter Y cordinates :";
cin>>p2.y;
cout<<"Enter number of vertex=";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\n Enter cordinates of vertex :";
cout<<i+1;
cout<<"\n Enter X cordinates :";
cin>>p[i].x;
cout<<"\n Enter Y cordinates :";
cin>>p[i].y;
}
p[i].x=p[0].x;
p[i].y=p[0].y;
initgraph(&gd,&gm,NULL);
cleardevice();
drawpolygon(p,n);
rectangle(p1.x,p1.y,p2.x,p2.y);
getch();
left(p1,p,pp);
right(p2,p,pp);
top(p1,p,pp);
bottom(p2,p,pp);
cleardevice();
rectangle(p1.x,p1.y,p2.x,p2.y);
drawpolygon(p,n);
getch();
closegraph();
return(0);
}
void left(pt p1,pt p[20],pt pp[20])
{
int i,j=0;
for(i=0;i<n;i++)
{
if(p[i].x<p1.x && p[i+1].x>=p1.x)
{
if(p[i+1].x-p[i].x!=0)
{
pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
}
else
{
pp[j].y=p[i].y;
}
pp[j].x=p1.x;
j++;
pp[j].x=p[i+1].x;
pp[j].y=p[i+1].y;
j++;
}
if(p[i].x>p1.x && p[i+1].x>=p1.x)
{
pp[j].y=p[i+1].y;
pp[j].x=p[i+1].x;
j++;
}
if(p[i].x>p1.x && p[i+1].x<=p1.x)
{
if(p[i+1].x-p[i].x!=0)
{
pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
}
else
{
pp[j].y=p[i].y;
}
pp[j].x=p1.x;
j++;
}
}
for(i=0;i<j;i++)
{
p[i].x=pp[i].x;
p[i].y=pp[i].y;
}
p[i].x=pp[0].x;
p[i].y=pp[0].y;
n=j;
}
void right(pt p2,pt p[20],pt pp[20])
{
int i,j=0;
for(i=0;i<n;i++)
{
if(p[i].x>p2.x && p[i+1].x<=p2.x)
{
if(p[i+1].x-p[i].x!=0)
{
pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
}
else
{
pp[j].y=p[i].y;
}
pp[j].x=p2.x;
j++;
pp[j].x=p[i+1].x;
pp[j].y=p[i+1].y;
j++;
}
if(p[i].x<p2.x && p[i+1].x<=p2.x)
{
pp[j].y=p[i+1].y;
pp[j].x=p[i+1].x;
j++;
}
if(p[i].x<p2.x && p[i+1].x>=p2.x)
{
if(p[i+1].x-p[i].x!=0)
{
pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
}
else
{
pp[j].y=p[i].y;
}
pp[j].x=p2.x;
j++;
}
}
for(i=0;i<j;i++)
{
p[i].x=pp[i].x;
p[i].y=pp[i].y;
}
p[i].x=pp[0].x;
p[i].y=pp[0].y;
n=j;
}
void top(pt p1,pt p[20],pt pp[20])
{
int i,j=0;
for(i=0;i<n;i++)
{
if(p[i].y<p1.y && p[i+1].y>=p1.y)
{
if(p[i+1].y-p[i].y!=0)
{
pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
}
else
{
pp[j].x=p[i].x;
}
pp[j].y=p1.y;
j++;
pp[j].x=p[i+1].x;
pp[j].y=p[i+1].y;
j++;
}
if(p[i].y>p1.y && p[i+1].y>= p1.y)
{
pp[j].y=p[i+1].y;
pp[j].x=p[i+1].x;
j++;
}
if(p[i].y>p1.y && p[i+1].y<= p1.y)
{
if(p[i+1].y-p[i].y!=0)
{
pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
}
else
{
pp[j].x=p[i].x;
}
pp[j].y=p1.y;
j++;
}
}
for(i=0;i<j;i++)
{
p[i].x=pp[i].x;
p[i].y=pp[i].y;
}
p[i].x=pp[0].x;
p[i].y=pp[0].y;
n=j;
}
void bottom(pt p2,pt p[20],pt pp[20])
{
int i,j=0;
for(i=0;i<n;i++)
{
if(p[i].y>p2.y && p[i+1].y <= p2.y)
{
if(p[i+1].y-p[i].y!=0)
{
pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;
}
else
{
pp[j].x=p[i].x;
}
pp[j].y=p2.y;
j++;
pp[j].x=p[i+1].x;
pp[j].y=p[i+1].y;
j++;
}
if(p[i].y<p2.y && p[i+1].y <= p2.y)
{
pp[j].y=p[i+1].y;
pp[j].x=p[i+1].x;
j++;
}
if(p[i].y<p2.y && p[i+1].y >= p2.y)
{
if(p[i+1].y-p[i].y!=0)
{
pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;
}
else
{
pp[j].x=p[i].x;
}
pp[j].y=p2.y;
j++;
}
}
for(i=0;i<j;i++)
{
p[i].x=pp[i].x;
p[i].y=pp[i].y;
}
p[i].x=pp[00].x;
p[i].y=pp[00].y;
n=j;
}
void drawpolygon(pt x[20],int n)
{
int i;
for(i=0;i<n-1;i++)
{
line(x[i].x,x[i].y,x[i+1].x,x[i+1].y);
}
line(x[i].x,x[i].y,x[0].x,x[0].y);
}
