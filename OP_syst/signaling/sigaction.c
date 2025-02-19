//
// Created by Raúl Armas Seriñá on 20/3/24.
//
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
pid_t pid;
void handle_alarm(int sig) {
    printf("Time out\n");
    kill(pid, SIGKILL);
    //if the child process takes too long, we kill it
}
int main(int argc, char **argv) {
    int status;
    char **args;
    struct sigaction act;
    //we create a struct sigaction, which will contain the information about the signal
    //the struct is something like:
    //struct sigaction {
    //    void (*sa_handler)(int); -> the function that will be executed when the signal is received
    //    unsigned long sa_flags; -> the flags that we can set for the signal
    //    void (*sa_restorer)(void); -> not used
    args = &argv[1];
    pid = fork();
    switch(pid) {
        case -1: /* error in fork() */
            perror ("fork");
            exit(-1);
        case 0: /* child */
            sleep(6);
            execvp(args[0], args);
            // execute the program at the path given in the first argument
            perror("exec");
            exit(-1);
        default: /* parent */
/* set handler*/
            //the "handler" is the function that will be executed when the signal is received
            act.sa_handler = handle_alarm;
            //the flags are the options that we can set for the signal, in this case, 0 (no flags)
            act.sa_flags = 0;
            //we set the handler for the signal SIGALRM (alarm signal), and we pass the struct act
            sigaction(SIGALRM, &act, NULL);
            alarm(5);
            //wait for child to finish
            wait(&status);
    }
    exit(0);
}

