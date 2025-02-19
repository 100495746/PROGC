//
// Created by Raúl Armas Seriñá on 20/3/24.
//
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


//signals just send a simple integer to a process, which tells it what to do
//(stop process, continue, etc)
int main(int argc, char* argv[]){
    int pid = fork();
    if (pid == -1){
        return -1;
    }
    if (pid == 0){
        //child
        while(1){
            printf("printing...\n");
            usleep(50000);  //millionths of a second; 50000 = 1/20 sec
        }
    } else {
        //parent
        sleep(1);
        // wait 1 sec (let it print 20 lines)
        kill(pid, SIGKILL);
        //kill sends a signal to a process (pid),  (in this case, terminate process)
        wait(NULL);
    }
    return 0;
}
//some signal examples: SIGSTOP, stops process until signal SIGCONT is received
//SIGCHILD signal, returned when child ends execution