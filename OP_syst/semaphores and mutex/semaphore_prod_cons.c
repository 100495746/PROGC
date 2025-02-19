//
// Created by Raúl Armas Seriñá on 9/5/24.
//
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define MAX_BUFFER 1024 /* buffer size*/
#define DATA_SIZE 100000 /* number of data items to produce */

sem_t elements; /* elements in buffer*/
sem_t holes; /* holes in buffer*/
//sem_t holes: semaphore to control the number of holes in the buffer
//sem_t elements: semaphore to control the number of elements in the buffer
//sem_t basically is a pointer to a semaphore




int buffer[MAX_BUFFER]; /* common buffer*/

void *producer(void *arg) { /* Producer code*/
    int pos = 0; /* position in buffer*/
    int data; /* data to be produced */
    int i;
    for(i=0; i < DATA_SIZE; i++ ) {
        data = i; /* produce data*/
        sem_wait(&holes); /* Reduce holes by 1*/
        buffer[pos] = i;
        pos = (pos + 1) % MAX_BUFFER;
        sem_post(&elements); /* one element more*/
    }
    return NULL;
}

void *consumer(void *arg) { /* Consumer code */
    int pos = 0;
    int data;
    int i;
    for(i=0; i < DATA_SIZE; i++ ) {
        sem_wait(&elements); /* one element less*/
        data= buffer[pos];
        pos = (pos + 1) % MAX_BUFFER;
        sem_post(&holes); /* one hole more*/
        printf("Consumed: %d\n", data); /* consume data */
    }
    return NULL;
}

int main(void)
{
    pthread_t th1, th2; /* threads identifiers*/
    /* Initialize semaphores*/
    sem_init(&elements, 0, 0);
    sem_init(&holes, 0, MAX_BUFFER);

    /* create threads*/
    pthread_create(&th1, NULL, producer, NULL);
    pthread_create(&th2, NULL, consumer, NULL);
    /* wait for termination*/
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    exit(0);
}