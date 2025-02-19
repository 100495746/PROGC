//
// Created by Raúl Armas Seriñá on 21/3/24.
//
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void handle_alarm(int sig) {
    printf("Activated \n");
}
int main() {
    struct sigaction act;
/* Setis handler for SIGALRM */
    act.sa_handler = handle_alarm;
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, NULL);
    act.sa_handler = SIG_IGN; /* ignore SIGINT */
    sigaction(SIGINT, &act, NULL);
    for(;;){ /* SIGALRM every 10 secons */
        alarm(1);
        pause();
    }
}