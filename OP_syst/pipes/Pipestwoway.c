

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
    int p1[2]; // p1  child to parent  C=>P
    int p2[2]; // p2 parent to child  C<=P
    if (pipe(p1) == -1){return 1;}
    if (pipe(p2) == -1){return 1;}
    int pid = fork(); // we get 2 processes
    if (pid == -1) { return 2;}
    //printf("pid: %d \n", pid);
    if(pid == 0){
        //printf("hello");
        //we read the parent and write in the child.
        //Child process ( read data from parent who generates values)
        close(p1[0]); // we don't read from child
        close(p2[1]); // we don't write to child (we write to parent, we read from parent)
        int x;
        if (read(p2[0], &x, sizeof(x)) == -1){return 3;} // p1[0] read, p1[1] write
        printf("Received %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1){return 4;}
        printf("Wrote %d\n", x);

    }
    else{
        //parent process
        // we read the child and write in parent
        close(p1[1]); // we don't write to child
        close(p2[0]); // we don't read from ourselves (parent
        srand(time(NULL));
        int y = rand() % 10; // numbers from 0 to 9
        if(write(p2[1], &y, sizeof(y))==-1){return 5;}
        printf("wrote %d\n", y);
        if(read(p1[0], &y, sizeof(y)) == -1){return 6;}
        printf("Result is %d\n", y);
        wait(NULL);
    }
    // at this point, every pipe (every end of every pipe) is closed
    return 0;
}
