//
// Created by Raúl Armas Seriñá on 7/5/24.
//
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2
// Shared counter
int counter = 0;
// Semaphore declaration
sem_t semaphore;

// Function executed by the threads
void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    //dereferencing the pointer to the argument, which is an integer
    // a thread has several attributes, one of them is the id, which is an integer
    //another attribute is the state, which is a pointer to a void function
    // Perform some work
    for (int i = 0; i < 5; i++) {
        // Wait on semaphore
        sem_wait(&semaphore);
        // Critical section: Access shared counter
        if (thread_id == 0) {
            counter++; // Increment counter
            printf("Thread %d incremented counter: %d\n", thread_id, counter);
        } else {
            counter--; // Decrement counter
            printf("Thread %d decremented counter: %d\n", thread_id, counter);
        }
        // Signal semaphore
        sem_post(&semaphore);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1};
    // Initialize semaphore
    sem_init(&semaphore, 0, 1);
    // Initial value of 1, 0 is for shared between threads
    // sem_init(sem_t *sem, int pshared, unsigned int value);
    // sem_t *sem: Pointer to a semaphore
    // int pshared: 0 if the semaphore is shared between threads,
    // 1 if it is shared between processes
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        //pthread_t *thread: This is a pointer to a pthread_t variable where the ID of the newly created thread
        // will be stored. In your selected code, &threads[i] is passed as this argument.
        //const pthread_attr_t *attr: This is a pointer to a pthread_attr_t structure that specifies thread attributes.
        // If this parameter is NULL, then the thread is created with default attributes. In your selected code,
        // NULL is passed as this argument, meaning the thread is created with default attributes.
        //void *(*start_routine) (void *): This is a pointer to the function that the thread will execute once
        // it is created. This function must take a single void * argument and return a void *.
        // In your selected code, thread_function is passed as this argument.
        //void *arg: This is a pointer to the argument that will be passed to the start_routine function
        // when the thread is created. In your selected code, &thread_ids[i] is passed as this argument,
        // meaning the address of the i-th element of the thread_ids array is passed to the thread_function.
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}
