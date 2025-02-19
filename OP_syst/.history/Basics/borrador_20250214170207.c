#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int NUM_DEPOSIT_THREADS=3;
int NUM_WITHDRAW_THREADS=3;
int BALANCE =1000;
pthread_mutex_t mutex;

struct op_bal{
    int addition;
    int threadid;
};

void *add_balance(void *arg){
    struct op_bal *data = (struct op_bal *)arg;
    pthread_mutex_lock(&mutex);
    BALANCE+=data->addition;
    if(data->addition>0){
        printf("Deposit %d from %d ",  data->addition, data->threadid);
    }else{
         printf("Withdrew %d from %d ", data->addition, data->threadid);
    }
    printf("Balance: %d\n", ALANCE);
    pthread_mutex_unlock(&mutex);
    return NULL;
}


int main(){
    pthread_t depositt[NUM_DEPOSIT_THREADS];
    pthread_t withdrawt[NUM_WITHDRAW_THREADS];
    struct op_bal *data = malloc((NUM_DEPOSIT_THREADS + NUM_WITHDRAW_THREADS) * sizeof(struct op_bal));
    pthread_mutex_init(&mutex, NULL);
    data->balance=1000;
    for (int i=0; i<NUM_DEPOSIT_THREADS; i++){
        data->addition=200;
        data->threadid =i;
        pthread_create(&depositt[i], NULL, add_balance, &data);
    }
    
    for (int i=0; i<NUM_WITHDRAW_THREADS; i++){
        data->addition=-100;
        data->threadid =i;
        pthread_create(&withdrawt[i], NULL, add_balance, &data);  
    }

    for (int i=0; i<NUM_DEPOSIT_THREADS; i++){
        pthread_join(depositt[i], NULL);
    }
    for (int i=0; i<NUM_WITHDRAW_THREADS; i++){
        pthread_join(withdrawt[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;

}
