/* 
Name : WAGH ARYAN ANIL
Class : SE AIML 
RollNO :- 53
Problem Statement:  Implement the C program for Page Replacement Algorithms: FCFS, LRU, and Optimal for 
frame size as minimum three.
*/
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
 /*
 error@DESKTOP-OFL03QL:~/OS code$ gcc FIFO.c -o abc
error@DESKTOP-OFL03QL:~/OS code$ ./abc

 ENTER THE NUMBER OF PAGES:
10

 ENTER THE PAGE NUMBER :
2
5
3
1
2
5
1
2
3
1

 ENTER THE NUMBER OF FRAMES :4
ref string       page frames
2               2       -1      -1      -1
5               2       5       -1      -1
3               2       5       3       -1
1               2       5       3       1
2
5
1
2
3
1
Page Fault Is 4
 */