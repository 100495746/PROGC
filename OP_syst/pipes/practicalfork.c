//
// Created by Raúl Armas Seriñá on 12/3/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
int main(int argc, char* argv[]){
    //we will sum all elements, in a manner that takes advantage of several processes
    //it sums them up by dividing the array into two and leaving one of the arrays to one process
    //and the other to another process, at the end both processes will have a partial sum, and one
    // process will write the partial sum to the pipe and the other will read it and sum it up together

    int arr[]={1,2,3,4,1,2, 7, 7};
    int arrSize = sizeof(arr)/sizeof(int); // number of integers in the array
    int start, end;
    int fd[2]; //array of two ints;
    if (pipe(fd) == -1){
        printf("An error ocurred opening the pipe\n");
        return 1; //the two arguments of pipe are the file descriptors (fd[0] and fd[1]) (read and write)
    }  //pipe takes two int arguments, which are "keys" to access a determined file
    int id = fork();
    if (id == -1){
        printf("An error occurred when forking\n");
        return 2;
    }
    if (id == 0){
        start=0;
        end= arrSize/2;
    } else{
        start=arrSize/2;
        end=arrSize;
    }

    int sum =0;
    int i;
    for (i = start; i < end; i++) {
        sum += arr[i];
    }

    printf("Calculated partial sum %d\n", sum);
    if (id ==0){
        close(fd[0]);
        // this is standard, usually when we open a pipe (read/write) we close one end,
        //write receives the address of the variable, and the size of the variable
        //write(fd[1], &sum, sizeof(sum))==-1) is the same as write(fd[1], &sum, sizeof(int))==-1)
        //so it writes the address of the variable and the size of the variable
        if (write(fd[1], &sum, sizeof(sum))==-1){
            printf("An error ocurred writing to the pipe\n");
            return 3;
        } //&x is the address where we want to write (we reserve a size)
        close(fd[1]);
    } else{
        close(fd[1]);
        int sumFromChild;
        if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) ==-1){
            printf("An error occurred reading from the pipe\n");
            return 4;
        }
        close(fd[0]);
        int totalSum = sum + sumFromChild;
        //sums the partial sums
        printf("Total sum is: %d\n", totalSum);
        wait(NULL);//
    }
    return 0;
 }
// sortcut for copilot activate autocomplete: alt+Blockmayus
//sortcut for copilot deactivate autocomplete: ctrl+Blockmayus