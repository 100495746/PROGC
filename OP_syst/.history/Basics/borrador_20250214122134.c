#include <stdio.h>
#include <pthread.h>

int NUM_THREADS=3;

void *printMessage(void *arg){
    int thread_id = *()
    printf("Soy el hilo número %d\n");
    return NULL;
}

int main(){
    pthread_t hilos[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i=0; i<NUM_THREADS; i++ ){
        thread_ids[i]=i+1;
        pthread_create(&hilos[i], NULL, printMessage, &thread_ids[i]);
    }
    for (int i=0; i<NUM_THREADS; i++ ){
        pthread_join(hilos[i], NULL);
    }
    return 0;
}
