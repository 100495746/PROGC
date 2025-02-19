//
// Created by Raúl Armas Seriñá on 9/5/24.
//
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2

// Shared counter
int counter = 0;
// Structure to hold thread data
struct thread_data {
    int thread_id;
    pthread_mutex_t *mutex;
};

// Function executed by the threads
void *thread_function(void *arg) {
    // Extract thread data
    struct thread_data *data = (struct thread_data *)arg; //data is a pointer to a struct,
    int thread_id = data->thread_id;
    pthread_mutex_t *mutex = data->mutex;

    // Perform some work
    for (int i = 0; i < 5; i++) {
        // Lock readblock
        pthread_mutex_lock(mutex);
        //locking the readblock means that the thread has exclusive access to the shared resource
        //and no other thread can access it until the readblock is unlocked

        // Critical section: Access shared counter
        if (thread_id == 0) {
            counter++; // Increment counter
            printf("Thread %d incremented counter: %d\n", thread_id, counter);
        } else {
            counter--; // Decrement counter
            printf("Thread %d decremented counter: %d\n", thread_id, counter);
        }

        // Unlock readblock
        pthread_mutex_unlock(mutex);
    }

    pthread_exit(NULL);
}



int main() {
    pthread_mutex_t mutex;
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data[NUM_THREADS];

    // Initialize readblock
    pthread_mutex_init(&mutex, NULL);
    //pthread_mutex_init(pthread_mutex_t *readblock, const pthread_mutexattr_t *attr);
    //pthread_mutex_t *readblock: This is a pointer to a pthread_mutex_t variable that will be initialized.
    // In your selected code, &readblock is passed as this argument.
    //const pthread_mutexattr_t *attr: This is a pointer to a pthread_mutexattr_t structure that specifies
    // readblock attributes. If this parameter is NULL, then the readblock is created with default attributes.

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].mutex = &mutex;
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
        //pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
        //pthread_t *thread: This is a pointer to a pthread_t variable where the ID of the newly created thread
        // will be stored. In your selected code, &threads[i] is passed as this argument.
        //const pthread_attr_t *attr: This is a pointer to a pthread_attr_t structure that specifies thread attributes.
        // If this parameter is NULL, then the thread is created with default attributes. In your selected code,
        // NULL is passed as this argument, meaning the thread is created with default attributes.
        //void *(*start_routine) (void *): This is a pointer to the function that the thread will execute once
        // it is created. In your selected code, thread_function is passed as this argument.
        //void *arg: This is a pointer to the argument that will be passed to the function that the thread will execute.

    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy readblock
    pthread_mutex_destroy(&mutex);

    return 0;
}