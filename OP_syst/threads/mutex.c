//
// Created by Raúl Armas Seriñá on 20/3/24.
//
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;



// we create a "lock variable" (mutex), we unlock it whenever we are done doing something
// , and we lock it  when we are doing something

void* routine(){
    for(int i=0; i <10000; i ++){
        pthread_mutex_lock(&mutex);

            //wait until lock is 0, we do so that nowhere, a thread starts reading and
            // the other starts executing (race condition)

        mails++;
        pthread_mutex_unlock(&mutex);
        // once we are done incrementing, we unlock the mutex

        // this "lock-unlock" of mutex basically "protects" a part of the code from
        // other threads executing it at the same time ( so if at any point there is a thread
        // executing this part of the code, none other will access it (until mutex is unlocked)
    }
    return 0;
}

int main(int argc, char* argv[]){
    pthread_t p1, p2, p3, p4;
    pthread_mutex_init(&mutex, NULL);
    //we allocate memory, so we later have to destroy mutex to free memory


    if (pthread_create(&p1, NULL, &routine, NULL)!=0){
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL)!=0){
        return 2;
    }
    if (pthread_create(&p3, NULL, &routine, NULL)!=0){
        return 3;
    }
    if (pthread_create(&p4, NULL, &routine, NULL)!=0) {
        return 4;
    }
    if(pthread_join(p1, NULL) != 0){
        return 5;
    }
    if(pthread_join(p2, NULL) != 0){
        return 6;
    }
    if(pthread_join(p3, NULL) != 0){
        return 7;
    }
    if(pthread_join(p4, NULL) != 0){
        return 8;
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;

}
