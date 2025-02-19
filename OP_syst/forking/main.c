#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
    int id=fork(); //A child process is born executed at the same time, it returns an id (0 for the child)
    if (id != 0) {
        fork();// If we call fork 'n' times, we will get 2^n processes
        // If we want an odd number of executions, then we should make an if, for id=0 not to fork again
    }
    printf("Hello world\n");
     //We get two ids, everything below "fork" is executed twice
    //printf("Hello world from id: %d\n", id);
    /*if (id == 0) {
        printf("Hello from child process\n");
    }  else{
        printf("Hello from main process\n");

    }*/
    return 0;
}
