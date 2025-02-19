#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int NUM_DEPOSIT_THREADS=3;
int NUM_WITHDRAW_THREADS=3;
pthread_mutex_t mutex;

struct op_bal{
    int balance;
    int addition;
};

void *add_balance(void *arg){
    struct op_bal *data = (struct op_bal *)arg;
    int balance = data->balance;
    int addition = data->addition;
    pthread_mutex_lock(&mutex);
    balance+=addition;
    printf("Balance: %d\n", balance);
    pthread_mutex_unlock(&mutex);
    return NULL;
}


int main(){
    pthread_t depositt[NUM_DEPOSIT_THREADS];
    pthread_t withdrawt[NUM_WITHDRAW_THREADS];
    struct op_bal data;
    data.balance=1000;
    if (NUM_DEPOSIT_THREADS>=NUM_WITHDRAW_THREADS){
        for (int i=0; i<NUM_DEPOSIT_THREADS; i++){
            data.addition=+200;
            pthread_create(&depositt[i], NULL, add_balance, &data);

            if(i-1<NUM_WITHDRAW_THREADS){
                data.addition=-100;
                pthread_create(&withdrawt[i], NULL, add_balance, &data);
            }
        }

    }else{
         for (int i=0; i<NUM_WITHDRAW_THREADS; i++){
            data.addition-=100;
            pthread_create(&withdrawt[i], NULL, add_balance, &data);

            if(i-1<NUM_DEPOSIT_THREADS){
                data.addition=+200;
                pthread_create(&depositt[i], NULL, add_balance, &data);
            }
            pthread_join(&depossitt)
        }
    }
    pthread_mutex_destroy(&mutex)
    return 0;

}
