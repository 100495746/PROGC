#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    printf("Thread ID: %lu\n", (unsigned long)pthread_self());
    printf("1\n");
    return NULL;
}

int main() {
    // Call fork from one of the threads
    if (fork() == 0) {
        printf("Child process with only the calling thread\n");
        pthread_t thread;
        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL);
        exit(0);
    } else {
        printf("Parent process with only the calling thread\n");
    }

    return 0;
}
