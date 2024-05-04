/*  SSTF Disk Scheduling Algorithm  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
  int queue[100], queue2[100], q_size, head, seek=0, temp;
  float avg;
  printf("%s\n", "-----SSTF Disk Scheduling Algorithm-----");
  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);

  printf("%s\n", "Enter queue elements");
  for(int i=0; i<q_size; i++){
    scanf("%d",&queue[i]);
  }
  
  printf("%s\n","Enter initial head position");
  scanf("%d", &head);

  //get distance from head of elems in queue
  for(int i=0; i<q_size; i++){
    queue2[i] = abs(head-queue[i]);
  }
  //swap elems based on their distance from each other
  for(int i=0; i<q_size; i++){
      for(int j=i+1; j<q_size;j++){

        if(queue2[i]>queue2[j]){
            temp = queue2[i];
            queue2[i]=queue[j];
            queue2[j]=temp;

            temp=queue[i];
            queue[i]=queue[j];
            queue[j]=temp;
        }
    }

  }

  for(int i=1; i<q_size; i++){
    seek = seek+abs(head-queue[i]);
    head = queue[i];
  }

  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);
  return 0;
}
/*OUTPUT:
samarth@samarth-OptiPlex-7010:~$ gcc Disk_SSTF.c 
samarth@samarth-OptiPlex-7010:~$ ./a.out
-----SSTF Disk Scheduling Algorithm-----
Enter the size of the queue
7
Enter queue elements
82 170 43 140 24 16 190
Enter initial head position
50

Total seek time is 288	
Average seek time is 41.142857
*/
