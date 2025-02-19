//
// Created by Raúl Armas Seriñá on 12/3/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
int main(int argc, char* argv[]){
    int id1 = fork();
    int id2 = fork();
    if (id1 == 0){
        if (id2 == 0){
            printf("We are process y\n");
        } else{
            printf("We are process x\n");
        }
    }
    else{
        if (id2 == 0){
            printf("We are process z\n");

        } else{
            printf("We are parent  process \n");

        }
    }
    //wait(NULL); //this is wrong, the wait function only waits for one child
    //(the parent has two children and these children only have one child (so they wait for it)),
    //basically, with two children, using wait(NULL) with two children, chooses to wait for the fastest child
    while(wait(NULL) != -1 || errno != ECHILD){
        printf("waited for a child to finish\n");
    }
    return 0;

}

//Basically, if we draw a schematic
// (id1=x,id2=z)->(x,id1=0,id2=y)->(y,id1=0,id2=0) id1=0 means it is a child of parent
//             L

