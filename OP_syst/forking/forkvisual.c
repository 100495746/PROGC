//
// Created by Raúl Armas Seriñá on 11/3/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int id = fork();
    if (id == 0) {
        sleep(1);
    }
    printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
    //this gives current id and the parent id
    // Waits for a child, if not it will be equal to -1
    int res = wait(NULL);
    //wait(NULL) waits for any child to finish
    if (res == -1){
        printf("No children to wait for\n");
    } else{
        printf("%d finished execution", res);
    }

    return 0;
// Every process has an id, every process has a parent id
}