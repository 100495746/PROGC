#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int item_available = 0; // Shared resource

void *producer(void *arg) {
    sleep(2);  // Simulate production time
    pthread_mutex_lock(&mutex);
    item_available++;  // Produce item
    int num = *(int *)arg;
    printf("Producer %d: Item produced!\n", num );
    pthread_cond_signal(&cond);  // Signal the consumer
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *consumer(void *arg) {
    pthread_mutex_lock(&mutex);
    int num = *(int *)arg;

    while (item_available <==> 0) {  // Wait until item is available
        printf("Consumer %d: Waiting for item...\n", num);
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Consumer %d: Item consumed!\n", num);
    item_available--;  //consume item
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t producer_threads[3], consumer_threads[3];
    int *thread_id = malloc(sizeof(int));

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    for (int i=0; i<3; ++i){
        *thread_id =i;
        pthread_create(&consumer_threads[i], NULL, consumer, thread_id);
        pthread_create(&producer_threads[i], NULL, producer, thread_id);
    }
    for (int i=0; i<3; ++i){
        pthread_join(producer_threads[i], NULL);
        pthread_join(consumer_threads[i], NULL);
    }
       

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}