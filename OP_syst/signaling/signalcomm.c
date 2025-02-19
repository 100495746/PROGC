//
// Created by Raúl Armas Seriñá on 22/4/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int x = 0;

void handle_sigusr1(int sig){
    if (x==0) {
        printf("(HINT)Remember that multiplication is repetitive addition\n");
    }
}

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1){
        return 1;
    }
    if (pid == 0){
        //child process
        sleep(5);
        kill(getppid(), SIGUSR1);
        //we send the signal SIGUSR1 to the parent process
        //getppid() returns the parent process id, so we create a child process
        //that just waits 5 seconds
        // kill is a system call that sends a signal to a process, so the parent
        // process receives the signal SIGUSR1
    }
    else{
        //parent process
        struct sigaction sa = {0}; //initialize the struct to 0
        sa.sa_flags = SA_RESTART; //restart the system call if it is interrupted
        sa.sa_handler = &handle_sigusr1;
        //we assign the function handle_sigusr1 to the handler, when the signal is received
        //it runs the function
        sigaction(SIGUSR1, &sa, NULL);


        printf("What is the result of 3 x 5: ");
        scanf("%d", &x);
        if (x == 15){
            printf("Correct\n");
        }
        else{
            printf("Incorrect\n");
        }
    }
}