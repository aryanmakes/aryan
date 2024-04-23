/* 
Name : SAYYAD HUJEFA AYUB
Class : SE AIML 
RollNO :- 39
Problem Statement: Thread synchronization and mutual exclusion using mutex. Application to demonstrate: Reader-Writer 
problem with reader priority. 
*/
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t wlock, rlock;
int data = 0, rcount = 0;

void *writer(void *arg) {
    int waiting;
    waiting = rand() % 3;
    printf("\nWriter is trying to enter critical section");
    pthread_mutex_lock(&wlock);
    data++;
    printf("\nWriter has entered critical section");
    sleep(waiting);
    pthread_mutex_unlock(&wlock);
    printf("\nWriter has left critical section");
    sleep(5);
    return NULL;
}

void *reader(void *arg) {
    int waiting;
    waiting = rand() % 3;
    printf("\nReader is trying to enter critical section");
    pthread_mutex_lock(&rlock);
    rcount++;
    if (rcount == 1)
        pthread_mutex_lock(&wlock);
    pthread_mutex_unlock(&rlock);
    printf("\nReader %d has entered the critical section", rcount);
    printf("\nReader is reading data :%d", data);
    sleep(waiting);
    pthread_mutex_lock(&rlock);
    rcount--;
    if (rcount == 0)
        pthread_mutex_unlock(&wlock);
    pthread_mutex_unlock(&rlock);
    printf("\nReader has left critical section");
    return NULL;
}

int main() {
    int i;
    pthread_mutex_init(&wlock, NULL);
    pthread_mutex_init(&rlock, NULL);
    pthread_t reader_threads[5], writer_threads[5];

    for (i = 0; i < 3; i++) {
        pthread_create(&reader_threads[i], NULL, reader, NULL);
        pthread_create(&writer_threads[i], NULL, writer, NULL);
    }

    for (i = 0; i < 3; i++) {
        pthread_join(reader_threads[i], NULL);
        pthread_join(writer_threads[i], NULL);
    }

    return 0;
}

/*
error@DESKTOP-OFL03QL:~/OS code$ gcc reader.c -o abc
error@DESKTOP-OFL03QL:~/OS code$ ./abc

Reader is trying to enter critical section
Reader 1 has entered the critical section
Reader is reading data :0
Writer is trying to enter critical section
Writer is trying to enter critical section
Reader is trying to enter critical section
Reader 2 has entered the critical section
Reader is reading data :0
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