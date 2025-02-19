//
// Created by Raúl Armas Seriñá on 14/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


//execvpe doesn't exist in mac so, this is what some guy created
int execvpe(const char *program, char **argv, char **envp)
{
    char** environ = envp;
    char **saved = environ;
    int rc;
    rc = execvp(program, argv);
    environ = saved;
    return rc;
}




int main(int argc, char* argv[]){

    char* arr[] = {"ping","google.com", NULL};
    char* env[] = {
            "TEST=environment variable",
            NULL
    };
    //Set environment variable
    //setenv("TEST", "environment variable", 1);
    //execvp(arr[0], arr);
    execvpe(
            "ping",
            arr,
            env
            );

    //INSTRUCTION: execl
    //The second argument is basically (int argc, char* argv[])-> argv[]*
    // the second argument is the name of the program to execute (argc)
    //execl basically replaces the current process with a new one, taking a
    //file name to an executable and a list of arguments, it executes the executable
    //and replaces the current process with the new one, the first argument is the name of the program
    //the second argument and so on are the arguments to the program, and the last argument is NULL

    // the execl function changes to another program and does not return, if it returns, it means that
    // it has failed, the return value is -1, and the errno is set to the error that occurred
    //so this last line won't be printed

    //INSTRUCTION: execlp
    // same as execl but with no need to specify path (just put the filename)

    //INSTRUCTION: execvp
    // accepts two arguments, filename and a second argument (normally an array of values,
    // in the same way as when we use execlp

    //INSTRUCTION: execvpe
    //same as execvp but the "e" stands for environment, we pass an array of vars
    int err = errno;
    //if instead of ping, we put ping2 (non existant), then we get error = 2-> ENOENT (no file with that name found)
    printf("ping finished\n");

    return 0;

}
