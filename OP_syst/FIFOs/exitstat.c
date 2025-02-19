//
// Created by Raúl Armas Seriñá on 14/3/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>




int main(int argc, char* argv[]){
    int pid = fork();
    if (pid == -1){
        return 1;
    }

    if(pid==0){
        //Child process
        int err = execlp("ping", "ping","-c", "3", "google.com", NULL);
        if (err == -1){
            printf("Could not find program to execute");
            return 2;
        }
    } else{
        int wstatus;
        //Parent process
        wait(&wstatus);
        if (WIFEXITED(wstatus)){
            int statusCode = WEXITSTATUS(wstatus);
            if (statusCode== 0){
                printf("Success!!\n");
            } else{
                printf("Failure with status code %d\n", statusCode );
            }
        }
        printf("Some post processing goes here!\n");


    }


    // we should call execlp inside the child, and wait in the parent.
    return 0;

}