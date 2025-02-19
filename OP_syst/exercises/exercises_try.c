//
// Created by Raúl Armas Seriñá on 19/5/24.
//

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

//int main(){
//    int i, pid, state;
//    int pids[10];
//    for(i =0; i<10; i++){
//        pid= fork();
//        switch(pid){
//            case -1:
//                fprintf(stderr, "Fork fail");
//                exit(-1);
//            case 0:
//                sleep(i);
//                //execl("cat", "fic1", NULL);
//                printf("%d awaken", i);
//                exit(0);
//            default:
//                pids[i]=pid;
//                break;
//        }
//    }
//    for(i=0; i<10; i++){
//        waitpid(pids[i], &state,0);
//    }
//    return 0;
//};

/*
#define TAMCOLA 100
int cola[TAMCOLA];
int puntInsercion=0;
int puntExtraccion=0;
int cont=32300;
int vacia(){
    return puntInsercion==puntExtraccion;
}
int insertadosTodos(){
    return puntInsercion==TAMCOLA;
}
int numElementosEnCola(){
    return puntInsercion-puntExtraccion;
}
void insertar(){
    printf("voy a insertar el %d\n", cont);
    if (!insertadosTodos())
        cola[puntInsercion++]=cont++; //simulación para simplificar. Se debe suponer que es un elemento cualquiera.
}
int extraer(){
    if (!vacia())
        return cola[puntExtraccion++];
    return -1;
}


#define NUMTHREADS 10
pthread_mutex_t mtx2;
// mutex para controlar la cola, puntInsercion y puntExtraccion
//mtx2 es un mutex para controlar la cola, puntInsercion y puntExtraccion
pthread_cond_t v2;
// condición para controlar la cola, puntInsercion y puntExtraccion
//v2 es una condición para controlar la cola, puntInsercion y puntExtraccion
//when we put signal v2 the condition is true
void evaluarFinProd(){
    if (insertadosTodos()){
        pthread_cond_signal (&v2);
        pthread_mutex_unlock (&mtx2);
        pthread_exit(0);
    }
}
void *fthreadProd (void *idthread){
    while (1){
        pthread_mutex_lock (&mtx2);
        evaluarFinProd();
        while (numElementosEnCola()>9){
            pthread_cond_wait (&v2, &mtx2);
            evaluarFinProd();
        }
        insertar();
        pthread_cond_signal (&v2);
        pthread_mutex_unlock (&mtx2);
    }
}
void evaluarFinCons(){
    if (insertadosTodos() && vacia() ){
        pthread_cond_signal (&v2);
        pthread_mutex_unlock (&mtx2);
        pthread_exit(0);
    }
}
void *fthreadCons (void *idthread) {
    while(1){
        pthread_mutex_lock (&mtx2);
        evaluarFinCons();
        while (vacia()){
            pthread_cond_wait (&v2, &mtx2);
            evaluarFinCons();
        }
        printf("Valor extraido%d\n", extraer());
        pthread_cond_signal (&v2);
        pthread_mutex_unlock (&mtx2);
    }
}
int main() {
    pthread_attr_t attr; // thread attributes, we can set the stack size, the priority, etc
    pthread_t threadcons[NUMTHREADS];// thread identifiers
    pthread_t threadprod[NUMTHREADS];
    int i;
    pthread_cond_init (&v2, NULL); // initialize the condition, when called, the condition is true
    pthread_mutex_init (&mtx2, NULL); // initialize the mutex, when locked, the mutex is locked
    srandom((unsigned)pthread_self()); // seed for random number generator

    pthread_attr_init(&attr); // initialize the attributes
    for (i=1;i<=NUMTHREADS;i++) {
        pthread_create(&threadprod[i-1],&attr,fthreadProd,NULL); // create the producer threads
        // the first argument is the thread identifier, the second argument is the attributes,
        // the third argument is the function to be executed, the fourth argument is the argument to the function
    }
    for (i=1;i<=NUMTHREADS;i++) {
        pthread_create(&threadcons[i-1],&attr,fthreadCons,NULL);
    }
    for (i=1;i<=NUMTHREADS;i++) {
        pthread_join(threadcons[i-1],NULL);
    }
    for (i=1;i<=NUMTHREADS;i++) {
        pthread_join(threadprod[i-1],NULL);
    }
    printf("Fin de la aplicación\n");
}

*/


