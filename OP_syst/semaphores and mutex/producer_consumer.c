//
// Created by Raúl Armas Seriñá on 9/5/24.
//
#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 5
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int produced_count = 0;
int consumed_count = 0;
pthread_mutex_t readblock;
pthread_cond_t full;
pthread_cond_t empty;

void* producer(void* arg) {
    int item = 1;
    while (produced_count < MAX_ITEMS) {
        pthread_mutex_lock(&readblock);

        while (((in + 1) % BUFFER_SIZE) == out) {
            pthread_cond_wait(&empty, &readblock);
            // in+ 1 % BUFFER_SIZE is the next position in the buffer
            //4+ 1 % 5 = 0; 3+1 % 5 = 4; 2+1 % 5 = 3; 1+1 % 5 = 2; 0+1 % 5 = 1
            //we wait until  inputs + 1 is different from out
            // we wait not to overwrite the buffer
            // if the buffer is full, we wait until the consumer consumes an item
        }
        buffer[in] = item;
        printf("Produced: %d\n", item);
        item++;
        in = (in + 1) % BUFFER_SIZE;// we increment the input, the % BUFFER_SIZE is to avoid overwriting the buffer
        produced_count++;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&readblock);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    while (consumed_count < MAX_ITEMS) {
        pthread_mutex_lock(&readblock);
        while (in == out) {
            pthread_cond_wait(&full, &readblock);
            // we wait until the buffer is not empty
            // the first argument is the condition variable
            // the second argument is the readblock
            // the condition variable is used to synchronize threads
            // it is used to block a thread until a condition is met
            // when the signal is called, the thread is unblocked and can continue
        }

        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        consumed_count++;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&readblock);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    pthread_mutex_init(&readblock, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    pthread_create(&producerThread, NULL, producer, NULL);
    //pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    pthread_mutex_destroy(&readblock);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}