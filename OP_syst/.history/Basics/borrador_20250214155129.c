#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int NUM_THREADS=5;
pthread_mutex_t mutex; // create a mutex

void *printMessage(void *arg){
    int thread_id = *(int *)arg;
    pthread_mutex_lock(&mutex);
    printf("Soy el hilo número %d\n", thread_id);
    pthread_mutex_unlock(&mutex);
    free(arg);
    return NULL;
}


int main(){
    pthread_t hilos[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    int *thread_ids = malloc(NUM_THREADS *sizeof(int));


    for (int i=0; i<NUM_THREADS; i++ ){
        thread_ids[i]=i+1;
        pthread_create(&hilos[i], NULL, printMessage, &thread_ids[i]);
        pthread_detach(hilos[i]);
    }
    

    
    
    sleep(1);
    pthread_mutex_destroy(&mutex);
    return 0;
}
