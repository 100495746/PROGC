//
// Created by Raúl Armas Seriñá on 11/3/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]){
    // when we use fork, argc and argv will have same values,
    // but the memory place is different.
//supposedly, if we executed without wait, we would get a disordered list of numbers,
// as with fork, both programs would run at the same time
    int id = fork();
    int n;
    if (id == 0) {
        n=1;
    } else{
        n=6;
    }
    if (id !=0){
        wait(0); // our program waits for the child process to end
    }
    int i;
    for (i = n; i < n+5; i++) {

        //with "wait" we tell the program to wait until the parent process ends execution
        printf("%d", i);
        fflush(stdout); //empties the intermediate storage
    }
    if (id !=0){
        printf("\n");
    }
    return 0;

}
