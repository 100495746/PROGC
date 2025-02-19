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

int primes[10] = {2,3,5,7,11,13,17,19,23,29};
// each thread should print one unique prime from te array

void* routine(void* arg){
    int index = *(int *)arg;
    printf("%d ", primes[index]);
    free(arg); // we deallocate the memory we allocated in the main routine
    // once we are done with the argument (so as not to break the memory)
}

int main(int argc, char* argv[]){
    pthread_t threads[10];
    for (int i = 0; i < 10; i++){
        int* a = malloc(sizeof(int)); // we allocate memory for the argument,
        //but we have to deallocate it somewhere in the routine
        *a = i;//
        if (pthread_create(&threads[i], NULL, &routine, a) != 0){
            // we pass the address of i, so the thread can access it (argument)
            perror("Error creating thread\n");
        }
    }
    for (int i = 0; i < 10; i++){
        if(pthread_join(threads[i],NULL) !=0){
            perror("Error joining thread\n");
        }
    }
    return 0;
    // they are not in order, because they are executed at the same time, but they are all printed once

}