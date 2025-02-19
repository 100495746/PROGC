//
// Created by Raúl Armas Seriñá on 19/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

void* routine(){
    printf("test from threads\n");
    sleep(3); //sleep 3 sec
    printf("Ending thread\n");
    //the threads are executed at the same time
}

int main(int argc, char *argv[]){
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0){
        printf("Error creating thread\n");
        return 1;
    }
    //pointer to the thread, attributes (set by default when null),
    // function to be executed as pointer, arguments to the function/
    if (pthread_create(&t2, NULL, &routine, NULL) != 0){
        printf("Error creating thread\n");
        return 1;

    }
    //we create another one
    if(pthread_join(t1,NULL) !=0){
        printf("Error joining thread\n");
        return 2;
    };
    if(pthread_join(t2,NULL) !=0){
        printf("Error joining thread\n");
        return 2;
    }

    // the first argument is what thread we want to wait for, and the second,
    //is the pointer where we store the return value of the thread (NULL if we don't care)
    //we want to wait until the thread finishes
    return 0;
}