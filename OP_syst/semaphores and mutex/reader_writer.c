//
// Created by Raúl Armas Seriñá on 9/5/24.
//
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t readblock, writeblock;
//sem_t *sem: Pointer to a semaphore
// writeblock: semaphore to control writing
// readblock: semaphore to control reading


int data = 0, readcount = 0;
//data: shared data
//readcount: number of readers reading the data

void *reader(void *arg)
{
    int f;
    f = ((int)arg);
    //dereferencing the pointer to the argument, which is an integer
    //f is the id of the thread
    sem_wait(&readblock);
    //wait until the readblock is unlocked (readblock to 0)
    readcount++;
    if(readcount==1) {
        sem_wait(&writeblock);
        //if there is a reader, we lock the writeblock
    }
    sem_post(&readblock);
    printf("Data read by the reader%d is %d\n",f,data);
    sleep(1);
    sem_wait(&readblock);
    readcount--;
    if(readcount==0) {
        sem_post(&writeblock);
    }
    sem_post(&readblock);
}

void *writer(void *arg)
{
    int f;
    f = ((int) arg);
    sem_wait(&writeblock);
    data++;
    printf("Data writen by the writer%d is %d\n",f,data);
    sleep(1);
    sem_post(&writeblock);
}

int main()
{
    int i,b;
    pthread_t rtid[3],wtid[3];
    sem_init(&readblock, 0, 1);
    sem_init(&writeblock,0,1);
    for(i=0;i<=2;i++)
    {
        pthread_create(&wtid[i],NULL,writer,(void *)i);
        pthread_create(&rtid[i],NULL,reader,(void *)i);
    }
    for(i=0;i<=2;i++)
    {
        pthread_join(wtid[i],NULL);
        pthread_join(rtid[i],NULL);
    }
    return 0;
}