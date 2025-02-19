//
// Created by Raúl Armas Seriñá on 20/3/24.
//
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t readblock;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//we initialize the condition variable with the macro PTHREAD_COND_INITIALIZER
//this is a macro that initializes a condition variable with default attributes
// a condition variable is used to synchronize threads,
// it is used to block a thread until a condition is met

//when the signal is called, the thread is unblocked and can continue


int finished_threads = 0;

typedef struct {
    int i;
    int n;

    //i is the id of the thread
    //n is the number of threads


} args;


void* routine(void* arg){
    args* value = (args*)arg;
    //we cast the argument to the struct, so value is a pointer to the struct
    pthread_mutex_lock(&readblock);
    printf("There are %d non finished threads\n", (value->n) - (value->i)-1);
    finished_threads++;
    if (finished_threads == value->n){
        pthread_cond_signal(&cond);
        //we give the signal once all "n" threads have finished, so the
        // main thread can continue ( the wait finishes, as the condition is met)
    }
    pthread_mutex_unlock(&readblock);
    return NULL;
}


int main(int argc, char* argv[]){
    args count[10];
    pthread_t threads[10];
    pthread_attr_t attr;

    pthread_mutex_init(&readblock, NULL);
    pthread_attr_init(&attr);
    //the attributes are set to default values
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    //we detach the threads, so we don't have to join them (stored in attr)
    for (int i = 0; i < 10; i++){
        count[i].n = 10;
        count[i].i = i;


        if (pthread_create(&threads[i], &attr, &routine, &count[i]) != 0){
            perror("Error creating thread\n");
            return 1;
        }
    }
    pthread_attr_destroy(&attr);
    pthread_mutex_lock(&readblock);
    while (finished_threads < 10){
        //while all threads are not finished, we wait
        pthread_cond_wait(&cond, &readblock);
        // the wait locks the readblock, so we can unlock it
        //the wait ends when the condition is met

    }
    pthread_mutex_unlock(&readblock);
    pthread_mutex_destroy(&readblock);
    pthread_cond_destroy(&cond);
    return 0;
}