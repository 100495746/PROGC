//
// Created by Raúl Armas Seriñá on 17/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

// Function executed by each thread
void *thread_function(void *thread_id) {
    long tid = (long)thread_id;
    // Cast the pointer to a long, a threads id is a long
    printf("Hello from thread %ld\n", tid);

    pthread_exit(NULL);
    // The pthread_exit() function is used to terminate a thread.With NULL, the function
    // returns a pointer to the exit status of the thread. This is similar to the exit()
}

int main() {
    //array of threads, the number of threads is defined by the constant NUM_THREADS
    //the pthread_t type is used to declare a thread, (type thread)
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        //pthread_create() function is used to create a new thread. The first argument is a pointer to the thread
        //to be created, the second argument is used to specify the attributes of the new thread,
        // the third argument is a pointer to the function that will be executed by the new thread,
        //and the last argument is a pointer to the argument that will be passed to the function.
        //The function returns 0 if the thread is created successfully, otherwise it returns an error code.
        //(void *)t is the argument that will be passed to the function, it is casted to a void pointer
        //t will be the thread id
        rc = pthread_create(&threads[t], NULL, thread_function, (void *)t);
        if (rc) {
            fprintf(stderr, "Error: Unable to create thread, %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        //pthread_join() function is used to wait for a thread to terminate.
        // The first argument is a pointer to the thread (the id), and the second argument is a pointer to the
        // location where the exit status of the thread will be stored.
        pthread_join(threads[t], NULL);
    }

    printf("All threads have completed\n");
    pthread_exit(NULL);
}
