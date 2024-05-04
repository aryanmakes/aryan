/* 
Name : 
Class : 
RollNO :- 
Problem Statement: Process control system calls: The demonstration of FORK, EXECVE and WAIT system calls
along with zombie and orphan states.

b. Implement the C program in which main program accepts an array. Main program uses the FORK system
call to create a new process called a child process. Parent process sorts an array and passes the sorted array
to child process through the command line arguments of EXECVE system call. The child process uses EXECVE
system call to load new program which display array in reverse order.
*/


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
		
void bass(int arr[10],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\n Ascending Order \n");
	for(i=0;i<n;i++)
		printf("\t%d",arr[i]);
	printf("\n\n\n");
}

void bdsc(int arr[10],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp=arr[j];  
				arr[j]=arr[j+1];  
				arr[j+1]=temp; 	
			}
		}
	}
	printf("\n Descending Sorting \n\n");
	for(i=0;i<n;i++)
		printf("\t%d",arr[i]);
	printf("\n\n\n");
	
}
void forkeg()
{
 	int arr[25],arr1[25],n,i;
 	printf("\nEnter the no of values in array");
 	scanf("%d",&n);
 	printf("\nEnter the array elements");
 	for(i=0;i<n;i++)
    		scanf("%d",&arr[i]);
 	int pid=fork();
  	if(pid==0)
   	{
      		sleep(10);
      		printf("\nchild process\n");
      		printf("child process id=%d\n",getpid());
      		bdsc(arr,n);
       		printf("\nElements Sorted Using Bubble Sort");
     		printf("\n");
       		for(i=0;i<n;i++)
    			printf("%d,",arr[i]);
    		printf("\n");
     		printf("\nparent process id=%d\n",getppid());
     		system("ps -x");
       }    
      else
       {
     		printf("\nparent process\n");
     		printf("\nparent process id=%d\n",getppid());
	 	bass(arr,n);	      
		printf("Elements Sorted Using Bubble Sort");
     		printf("\n");
      		for(i=0;i<n;i++)
    			printf("%d,",arr[i]);
    		printf("\n\n\n"); 
      } 
 }     
 int main()
 {
   	forkeg();
   	return 0;
 }  
/*OUTPUT:
samarth@samarth-OptiPlex-7010:~/OS Lab/Assignment 2$ gcc assign2b.c 
samarth@samarth-OptiPlex-7010:~/OS Lab/Assignment 2$ ./a.out

Enter the no of values in array5

Enter the array elements4 3 2 5 1

parent process

parent process id=35806

 Ascending Order 
	1	2	3	4	5


Elements Sorted Using Bubble Sort
1,2,3,4,5,

samarth@samarth-OptiPlex-7010:~/OS Lab/Assignment 2$ 
*/
