
#include<stdio.h>
int main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0;
printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);
printf("\n ENTER THE PAGE NUMBER :\n");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("\n ENTER THE NUMBER OF FRAMES :");
scanf("%d",&no);
for(i=0;i<no;i++)
frame[i]= -1;
j=0;
printf("ref string\t page frames\n");
for(i=1;i<=n;i++)
{
printf("%d\t\t",a[i]);
avail=0;
for(k=0;k<no;k++)
if(frame[k]==a[i])
avail=1;
if (avail==0)
{
frame[j]=a[i];
j=(j+1)%no;
count++;
for(k=0;k<no;k++)
printf("%d\t",frame[k]);
}
printf("\n");
}
printf("Page Fault Is %d\n",count);
return 0;
}
/* Output:
shu@shu-HP-Pavilion-Notebook:~/Documents$ gcc FIFO.c
shu@shu-HP-Pavilion-Notebook:~/Documents$ ./a.out
ENTER THE NUMBER OF PAGES:
10
ENTER THE PAGE NUMBER :
4 7 6 1 7 6 1 2 7 2
ENTER THE NUMBER OF FRAMES :3
ref string page frames
4 4 -1 -1
7 4 7 -1
6 4 7 6
1 1 7 6
7
6
1
2 1 2 6
7 1 2 7
2
Page Fault Is 6
*/
