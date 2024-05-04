// SJF Non-Preemptive
#include<stdio.h>
 
void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos]) //BT
                pos=j;
        }
 
        temp=bt[i];   //3 2 a=20 b=10  //a=10 b=20
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j]; 	//wt[i]=wt[i]+bt[j] //0  1   3   6
 
        total+=wt[i];   	//total=total+wt[i] // 1+3+6 = 10
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time //wt=tat-BT
        total+=tat[i];		//1+3+6+10
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
/*
samarth@samarth-OptiPlex-7010:~$ gcc SJF_NON.c 
samarth@samarth-OptiPlex-7010:~$ ./a.out
Enter number of process:4

Enter Burst Time:
p1:3
p2:2
p3:1
p4:4

Process	    Burst Time    	Waiting Time	Turnaround Time
p3		  1		    0			1
p2		  2		    1			3
p1		  3		    3			6
p4		  4		    6			10

Average Waiting Time=2.500000
Average Turnaround Time=5.000000
samarth@samarth-OptiPlex-7010:~$ 
*/
