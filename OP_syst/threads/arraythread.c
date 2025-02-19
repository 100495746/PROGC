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
    int sum =0;
    for (int j = 0; j < 5; j++){
        sum += primes[index + j];
    }
    printf("local sum: %d \n", sum);
    *(int *)arg = sum;
    return arg;

}

int main(int argc, char* argv[]){
    pthread_t threads[2];
    int i;
    for (i = 0; i < 2; i++){
        int* a = malloc(sizeof(int)); // we allocate memory for the argument,
        //but we have to deallocate it somewhere in the routine
        *a = i * 5; //we want to sum the first 5 primes in one thread and the other 5 in the other
        if (pthread_create(&threads[i], NULL, &routine, a) != 0){
            // we pass the address of i, so the thread can access it (argument)
            perror("Error creating thread\n");
        }
    }
    int globalSum = 0;
    for (int i = 0; i < 2; i++){
        int* r; //we have to store the return value of the thread
        if(pthread_join(threads[i],&r) !=0){
            perror("Error joining thread\n");
        }
        globalSum += *r;
        free(r);
        // free the memory we allocated in the routine
    }
    printf("The sum of the first 10 primes is %d\n", globalSum);
    return 0;
    // they are not in order, because they are executed at the same time, but they are all printed once

}