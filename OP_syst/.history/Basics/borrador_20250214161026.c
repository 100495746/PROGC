#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int contador = 0;
pthread_mutex_t mutex;

void *incrementar(void *arg) {
    for (int i = 0; i < 100000; i++) {
        p

        contador++;
    }
    return NULL;
}

int main() {
    pthread_t hilos[2];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 2; i++) {
        pthread_create(&hilos[i], &mutex, incrementar, NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Valor final del contador: %d\n", contador);
    return 0;
}
