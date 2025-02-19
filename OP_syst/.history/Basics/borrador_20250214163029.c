#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int NUM_DEPOSIT_THREADS=3;
int NUM_WITHDRAW_THREADS=3;
pthread_mutex_t mutex;




int main(){
    pthread_t depositt[NUM_DEPOSIT_THREADS];
    pthread_t withdrawt[NUM_WITHDRAW_THREADS];
    int *id_deposit = (pthread_t *)malloc()



}