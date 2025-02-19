//
// Created by Raúl Armas Seriñá on 20/3/24.
//

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;

void* routine(){
    for(int i=0; i <10000; i ++){
        mails++;
        //with big numbers, we enter "race conditions" it should have printed 20000
        // it does not print that
        //(read mails-> increment value->write mail back to memmory)
        // this is ok if we work with one thread, but with multiple threads
        //
    }
    return 0;
}

int main(int argc, char* argv[]){
    pthread_t p1, p2;
    if (pthread_create(&p1, NULL, &routine, NULL)!=0){
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL)!=0){
        return 2;
    }
    if(pthread_join(p1, NULL) != 0){
        return 3;
    }
    printf("Number of mails: %d\n", mails);
    return 0;

};
