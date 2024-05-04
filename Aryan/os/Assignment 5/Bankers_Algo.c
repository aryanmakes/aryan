#include <stdio.h>

int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;

printf("Enter the no of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
	completed[i] = 0;

printf("\n\nEnter the no of resources : ");
scanf("%d", &r);

printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ", i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &Max[i][j]);
}

printf("\n\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ",i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &alloc[i][j]);	
}

printf("\n\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
		scanf("%d", &avail[i]);	


	for(i = 0; i < p; i++)
		for(j = 0; j < r; j++)
			need[i][j] = Max[i][j] - alloc[i][j];
		
do
{
	printf("\n Max matrix:\tAllocation matrix:\n");
	for(i = 0; i < p; i++)
	{
		for( j = 0; j < r; j++)
			printf("%d  ", Max[i][j]);
		printf("\t\t");
		for( j = 0; j < r; j++)
			printf("%d  ", alloc[i][j]);
		printf("\n");
	}

	process = -1;

	for(i = 0; i < p; i++)
	{
		if(completed[i] == 0)//if not completed
		{
			process = i ;
			for(j = 0; j < r; j++)
			{
				if(avail[j] < need[i][j])
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\nProcess %d runs to completion!", process + 1);
		safeSequence[count] = process + 1;
		count++;
		for(j = 0; j < r; j++)
		{
			avail[j] += alloc[process][j];
			alloc[process][j] = 0;
			Max[process][j] = 0;
			completed[process] = 1;
		}
	}
}while(count != p && process != -1);

if(count == p)
{
	printf("\nThe system is in a safe state!!\n");
	printf("Safe Sequence : < ");
	for( i = 0; i < p; i++)
			printf("%d  ", safeSequence[i]);
	printf(">\n");
}
else
	printf("\nThe system is in an unsafe state!!");
}
/*OUTPUT:
samarth@samarth-OptiPlex-7010:~$ gcc Bankers_Algo.c 
samarth@samarth-OptiPlex-7010:~$ ./a.out
Enter the no of processes : 3


Enter the no of resources : 3


Enter the Max Matrix for each process : 
For process 1 : 3 6 8

For process 2 : 4 3 3

For process 3 : 3 4 4


Enter the allocation for each process : 
For process 1 : 2 2 3

For process 2 : 2 0 3

For process 3 : 1 2 4


Enter the Available Resources : 2 3 0

 Max matrix:	Allocation matrix:
3  6  8  		2  2  3  
4  3  3  		2  0  3  
3  4  4  		1  2  4  

Process 2 runs to completion!
 Max matrix:	Allocation matrix:
3  6  8  		2  2  3  
0  0  0  		0  0  0  
3  4  4  		1  2  4  

Process 3 runs to completion!
 Max matrix:	Allocation matrix:
3  6  8  		2  2  3  
0  0  0  		0  0  0  
0  0  0  		0  0  0  

Process 1 runs to completion!
The system is in a safe state!!
Safe Sequence : < 2  3  1  >
samarth@samarth-OptiPlex-7010:~$ 
*/
