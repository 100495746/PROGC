#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int NUM_DEPOSIT_THREADS=3;
int NUM_WITHDRAW_THREADS=3;
pthread_mutex_t mutex;

struct op_bal{
    int balance;
    int addition;
}

void *add_balance(void *arg){
    int balance = *(int *)arg;
    pthread_mutex_lock(&mutex);
    balance+=
    printf("Balance: %d\n", balance);
    pthread_mutex_unlock(&mutex);
    return NULL;
}


int main(){
    pthread_t depositt[NUM_DEPOSIT_THREADS];
    pthread_t withdrawt[NUM_WITHDRAW_THREADS];
    
    int balance = 1000;
    if (NUM_DEPOSIT_THREADS>=NUM_WITHDRAW_THREADS){
        for (int i=0; i<NUM_DEPOSIT_THREADS){


            if(i-1<NUM_WITHDRAW_THREADS){
                pthread_create(&depositt[i], NULL, add_balance, &balance);
            }

        }

    }else{


    }
        



}