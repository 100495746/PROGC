#include <stdio.h>
#include <pthread.h>

int NUM_THREADS=3;

void *printMessage(void *arg){
    printf("Soy el hilo número ");
    return NULL;
}

int main(){
    pthread_t hilos[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i=0; i<NUM_THREADS; i++ ){
        threa
        pthread_create(&hilos[i], NULL, printMessage, );
    }
    for (int i=0; i<NUM_THREADS; i++ ){
        pthread_join(hilos[i], NULL);
    }
    return 0;
}
