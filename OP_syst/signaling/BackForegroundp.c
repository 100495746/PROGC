//
// Created by Raúl Armas Seriñá on 20/3/24.
//
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void handle_sigstp(int sig){
    printf("Stopped not allowed\n");
}
//Notes: handler is a function that is called when a signal is received, it has to have the same
// signature as the one in the example
// sig is the signal that is received


int main(int argc, char* argv[]) {
    struct sigaction sa;
    //sigaction is a struct that contains information about signals
    sa.sa_handler = &handle_sigstp; //we assign the function handle_sigstp to the handler
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);
    //SIGTSTP is the signal that is sent when we press ctrl+z, we are telling the system
    //to perform the function handle_sigstp when we receive that signal
    // SIGTSTP prevents the process from being stopped

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d *5 = %d\n", x, x*5);
    return 0;
}