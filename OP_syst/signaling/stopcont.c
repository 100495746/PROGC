//
// Created by Raúl Armas Seriñá on 20/3/24.
//
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


//remember, in fork() the parent gets the pid of its child (and the child, which has no sons
// gives 0)
//basically  the id received is the id of the child, not the id of itself.
// So if parents id (its real, own id) =123 And the child's id is 777,
//  when we call fork() we will receive: fork()->(parent->pid=777); (child->pid=0)
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
        kill(pid, SIGSTOP); //stop, id of the child (stops child)
        int t;
        do{
            printf("Time in seconds for execution: ");
            scanf("%d", &t);
            if (t>0){
                kill(pid, SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }

        } while (t>0);
        kill(pid,SIGKILL);
        wait(NULL);
    }
    return 0;
}