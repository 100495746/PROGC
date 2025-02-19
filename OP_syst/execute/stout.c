//
// Created by Raúl Armas Seriñá on 21/3/24.
//
//
// Created by Raúl Armas Seriñá on 14/3/24.
//

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>





int main(int  argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        //Child process
        int file = open("output.txt", O_CREAT | O_WRONLY, 0777);
        //Redirecting output to a file, the flags are for creating the file if it doesn't exist and writing to it
        //There are many other flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND, O_CREAT, O_TRUNC, O_EXCL, O_NOCTTY,
        // O_NONBLOCK, O_DSYNC, O_RSYNC, O_SYNC), with "|" you can combine them
        // lastly the last argument is the permissions for the file, 0777 is the maximum permissions, 0644 is the
        // default for files

        // a file descriptor is a number that the operating system uses to identify a file, it is a number that
        // is used to access the file, it is like a pointer to the file, it is unique for each file
        // it is like a handle to the file
        //Whenever we open a process, linux gives us a file descriptor,id= 0 is stdin, id =1 is stdout, id =2 is stderr
        // So putting "read(0) would be like scanf()
        // "write(1)" would be like printf(),
        //so the actual first id we can use is 3 for our file descriptor
        printf("The file descriptor: %d\n", file);
        int file2 = dup2(file, STDOUT_FILENO); //dup duplicates the file descriptor, so now the file descriptor 4
        // is the file we just opened (created), so both 3, 4 are the same file
        //We can also use dup2 to duplicate a file descriptor to a specific number
        //STDOUT_FILENO = 1, so we are duplicating the file descriptor to the stdout file descriptor
        // with dup2, we can also close a file descriptor and open a file descriptor with a specific number
        // if we put "1" it will "eliminate" (substitute) the stdout file descriptor with the file we just opened

        printf("The duplicated fd: %d\n", file2);
        close(file); // we close the file descriptor 3, as we don't need it anymore

        int err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
        //exec overwrites the current process with the new process, so the code after exec is not executed
        //but exec does not change the file descriptors, so the file descriptors are still open
        // ths means that if we change the STDOUT, to a new file, it will not print on the terminal
        //it will print it in the file

        //now we really only use one output, so we should try and close the unused one
        if (err == -1) {
            printf("Could not find program to execute");
            return 2;
        }
    } else {
        int wstatus;
        //Parent process
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            int statusCode = WEXITSTATUS(wstatus);
            if (statusCode == 0) {
                printf("Success!!\n");
            } else {
                printf("Failure with status code %d\n", statusCode);
            }
        }
        printf("Some post processing goes here!\n");


    }
}