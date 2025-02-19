#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int item_available = 0; // Shared resource

void *producer(void *arg) {
    sleep(2);  // Simulate production time
    pthread_mutex_lock(&mutex);
    item_available = 1;  // Produce item
    printf("Producer: Item produced!\n");
    pthread_cond_signal(&cond);  // Signal the consumer
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *consumer(void *arg) {
    pthread_mutex_lock(&mutex);

    while (item_available == 0) {  // Wait until item is available
        printf("Consumer %d: Waiting for item...\n", num);
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Consumer: Item consumed!\n");
    item_available = 0;  // Reset item
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    for (int i=0; i<3; ++i){
        pthread_create(&consumer_thread, NULL, consumer, i);
        pthread_create(&producer_thread, NULL, producer, NULL);
    }
    

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}