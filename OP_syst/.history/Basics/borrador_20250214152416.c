#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int NUM_THREADS=3;

void *printMessage(void *arg){
    int thread_id = *(int *)arg;
    pthread_mutex_lock(&mutex);
    printf("Soy el hilo número %d\n", thread_id);
    return NULL;
}


int main(){
    pthread_t hilos[NUM_THREADS];
    int *thread_ids = malloc(NUM_THREADS *sizeof(int));


    for (int i=0; i<NUM_THREADS; i++ ){
        thread_ids[i]=i+1;
        pthread_create(&hilos[i], NULL, printMessage, &thread_ids[i]);
    }
    for (int i=0; i<NUM_THREADS; i++ ){
        pthread_join(hilos[i], NULL);
    }
    return 0;
}
