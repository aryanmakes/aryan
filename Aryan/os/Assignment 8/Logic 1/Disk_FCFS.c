/*  FCFS Disk Scheduling Implementation  */

#include <stdio.h>
#include <stdlib.h>

int main(){
  int queue[100], q_size, head, seek =0, diff;
  float avg;

  printf("%s\n", "***FCFS Disk Scheduling Algorithm***");

  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);

  printf("%s\n", "Enter queue elements");
  for(int i=1; i<=q_size; i++){
    scanf("%d",&queue[i]);
  }

  printf("%s\n","Enter initial head position");
  scanf("%d", &head);

  queue[0]=head;

  for(int j=0; j<=q_size-1; j++){
    diff = abs(queue[j]-queue[j+1]);
    seek += diff;
    printf("Move from %d to %d with Seek %d\n",queue[j],queue[j+1],diff);
  }

  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);

  return 0;
}
/*OUTPUT:
samarth@samarth-OptiPlex-7010:~$ gcc Disk_FCFS.c 
samarth@samarth-OptiPlex-7010:~$ ./a.out
***FCFS Disk Scheduling Algorithm***
Enter the size of the queue
7
Enter queue elements
82 170 43 140 24 16 190
Enter initial head position
50
Move from 50 to 82 with Seek 32
Move from 82 to 170 with Seek 88
Move from 170 to 43 with Seek 127
Move from 43 to 140 with Seek 97
Move from 140 to 24 with Seek 116
Move from 24 to 16 with Seek 8
Move from 16 to 190 with Seek 174

Total seek time is 642	
Average seek time is 91.714287	samarth@samarth-OptiPlex-7010:~$ 
*/
