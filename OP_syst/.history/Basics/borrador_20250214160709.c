#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int contador = 0;

void *incrementar(void *arg) {
    for (int i = 0; i < 100000; i++) {
        
        contador++;
    }
    return NULL;
}

int main() {
    pthread_t hilos[2];
    for (int i = 0; i < 2; i++) {
        pthread_create(&hilos[i], NULL, incrementar, NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Valor final del contador: %d\n", contador);
    return 0;
}
