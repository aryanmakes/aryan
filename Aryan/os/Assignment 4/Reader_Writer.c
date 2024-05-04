//Reader Writer Problem
#include<pthread.h>
#include<semaphore.h>
#include <stdlib.h>
#include<stdio.h>

pthread_mutex_t wlock, rlock;
int data = 0, rcount = 0;

void *write(void *arg)
{
	int waiting;

	waiting = rand()%3;
	printf("\nWriter is trying to enter critical section");
	pthread_mutex_lock(&wlock);
	data++;
	printf("\nWriter has entered critical section");
	sleep(waiting);
	pthread_mutex_unlock(&wlock);
	printf("\nWriter has left critical section");
	sleep(5);
}
void *read(void *arg)
{
	int waiting;

	waiting = rand()%3;
	printf("\nReader is trying to enter critical section");
	pthread_mutex_lock(&rlock);
	rcount++;

	if(rcount == 1)
	pthread_mutex_lock(&wlock);

	pthread_mutex_unlock(&rlock);
	printf("\nReader %d has entered the critical section",rcount);
	printf("\nReader is reading data :%d",data);
	sleep(waiting);
	pthread_mutex_lock(&rlock);
	rcount--;
	if(rcount == 0)
	pthread_mutex_unlock(&wlock);

	pthread_mutex_unlock(&rlock);
	printf("\nReader has left critical section");
}

void main()
{
	int i;

	pthread_mutex_init(&wlock,NULL);
	pthread_mutex_init(&rlock,NULL);

	pthread_t reader[5], writer[5];

	for(i=0; i<3; i++)
	{
		pthread_create(&reader[i],NULL,read,NULL);
		pthread_create(&writer[i],NULL,write,NULL);
	}
	for(i=0; i<3; i++)
	{
		pthread_join(reader[i],NULL);
		pthread_join(writer[i],NULL);
	}

}
/*
samarth@samarth-OptiPlex-7010:~$ gcc Reader_Writer.c 
samarth@samarth-OptiPlex-7010:~$ ./a.out

Reader is trying to enter critical section
Reader 1 has entered the critical section
Reader is reading data :0
Writer is trying to enter critical section
Reader is trying to enter critical section
Reader 2 has entered the critical section
Reader is reading data :0
Writer is trying to enter critical section
Reader is trying to enter critical section
Reader 3 has entered the critical section
Reader is reading data :0
Reader has left critical section
Writer is trying to enter critical section
Reader has left critical section
Reader has left critical section
Writer has entered critical section
Writer has left critical section
Writer has entered critical section
Writer has left critical section
Writer has entered critical section
Writer has left critical section 
*/
