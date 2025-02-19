//
// Created by Raúl Armas Seriñá on 13/3/24.
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

// we will generate two programs one which generates numbers and another one that
// reads them and prints a sum


int main(int argc, char* argv[]){
    // 5=> 5 * 4 = 20 => 20
    int p1[2];
    if (pipe(p1) == -1){return 1;}
    int pid = fork(); // we get 2 processes
    if (pid == -1) { return 2;}
    //printf("pid: %d \n", pid);


    if(pid == 0){
        //printf("hello");
        //Child process ( read data from parent who generates values)

        int x;
        if (read(p1[0], &x, sizeof(x)) == -1){return 3;} // p1[0] read, p1[1] write
        printf("Received %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1){return 4;}
        printf("cWrote %d\n", x);

    }
    else{
        //parent process
        srand(time(NULL));
        int y = rand() % 10; // numbers from 0 to 9
        if(write(p1[1], &y, sizeof(y))==-1){return 5;}
        printf("Pwrote %d\n", y);// here we should wait for child??--> yes, until result is written
        wait(NULL); // a pipe can only have one end opened, and either read or write (not at the same time)
        // we wait
        if(read(p1[0], &y, sizeof(y)) == -1){return 6;}
        printf("Result is %d\n", y);
    }
    close(p1[0]);
    close(p1[1]);
    return 0;
}