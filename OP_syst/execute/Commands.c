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




int main(int argc, char* argv[]){
    int pid = fork();
    if (pid == -1){
        return 1;
    }

    if(pid==0){
        //Child process
        execlp("ping", "ping","-c", "3", "google.com", NULL);
        //execlp("ls", "ls", "-l", NULL), execlp is a function that replaces the current process with a new one
        //this means that the child process will be replaced by the new process
        // The arguments mean the following:
        // ping: the name of the program
        // -c: the first argument
        // 3: the second argument
        // google.com: the third argument which is the server to ping
        // NULL: the last argument
        // The first argument is the name of the program, the second is the name of the program,
        // and the rest are the arguments
        // this returns -1 if it fails.
        //An output can be for example: PING google.com (142.250.185.14): 56 data bytes
        // which means that the program is working, ping is a program that sends a request to a server
        // and waits for a response, if the server responds, it will print the response, if not, it will print
        // that the server is not responding.
        // The -c flag means that it will send 3 requests to the server ( 3 pings)
        // (142.250.185.14) is the ip address of the server (google.com)
        // 56 data bytes is the size of the data that is being sent to the server
        // 64 bytes from 142.250.185.14: icmp_seq=0 ttl=118 time=23.967 ms
        // this means, icmp_seq=0 is the sequence of the request, ttl=118 is the time to live of the request
        // time=23.967 ms is the time it took for the server to respond
    } else{
        //Parent process
        wait(NULL);
        printf("Success!!!\n");
        printf("Some post processing goes here!\n");
    }


    // we should call execlp inside the child, and wait in the parent.
    return 0;

}