/* 
Name : SAYYAD HUJEFA AYUB
Class : SE AIML 
RollNO :- 39
Problem Statement: Thread synchronization using counting semaphores. Application to demonstrate: producer-consumer 
problem with counting semaphores and mutex. 
*/
#include<stdio.h>
 #include<pthread.h>
 #include<semaphore.h>
 #include <unistd.h> 
#include <stdlib.h>
 int buffer[5], size = 5, index1 = 0, a;
 sem_t E, F;
 pthread_mutex_t S;
 pthread_t con[5], pro[5];
 int insert(int item)
 {
 if(index1 < size)
 {
 buffer[index1] = item;
 index1++;
 }
 else
 {
 }
 }
 int delete()
 {
 printf("\nBuffer Overflow");
 if(index1 > 0)
 {
 index1--;
 }
 else
 {
     printf("\nBuffer Underflow");
 }
 }
 void *producer()
 {
 sleep(2);
 sem_wait(&E);
 a = rand()/100000000;
 pthread_mutex_lock(&S);
 insert(a);
 pthread_mutex_unlock(&S);
 printf("\nProducer produces item : %d",a);
 sem_post(&F);
 }
 void *consumer()
 {
 sem_wait(&F);
 pthread_mutex_lock(&S);
 delete();
 pthread_mutex_unlock(&S);
 printf("\nConsumer consumes item : %d\n",a);
 sem_post(&E);
 }
 int main()
 {
 int i;
 sem_init(&E,1,size);
 sem_init(&F,1,0);
 pthread_mutex_init(&S,NULL);
 for(i=0; i<size; i++)
 {
 pthread_create(&pro[i], NULL, producer, NULL);
 pthread_create(&con[i], NULL, consumer, NULL);
}
 for(i=0; i<size; i++)
 {
 pthread_join(pro[i],NULL);
 pthread_join(con[i],NULL);
 }
 }

 /*
 error@DESKTOP-OFL03QL:~/OS code$ gcc producer.c -o abc
error@DESKTOP-OFL03QL:~/OS code$ ./abc

Producer produces item : 18
Producer produces item : 19
Producer produces item : 16
Producer produces item : 8
Producer produces item : 17
Buffer Overflow
Consumer consumes item : 19

Buffer Overflow
Consumer consumes item : 19

Buffer Overflow
Consumer consumes item : 19

Buffer Overflow
Consumer consumes item : 19

Buffer Overflow
Consumer consumes item : 19
 */