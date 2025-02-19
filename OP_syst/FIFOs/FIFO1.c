//
// Created by Raúl Armas Seriñá on 12/3/24.
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
    if (mkfifo("myfifo1",0777) == -1){

        //the second argument is the permissions, 0666 is the most common
        //the third argument is the type of file, 1 is a FIFO
        //0777 means that the file is readable, writable and executable by everyone
        if (errno != EEXIST){
            printf("An error occurred creating the fifo\n");
            return 1;
        }
    }
    printf("Opening...\n"); // the program seems to hang here
    //Opening the read or write end of a FIFO blocks until the other end is also opened
    //If we open the read end of a FIFO, it will block until the write end is opened
    int fd = open("myfifo1", O_WRONLY); //this opens the file for writing
    //If we make it O_RDWR it will terminate as it is opened for both and does not have to
    // wait for a write process to end
    if (fd == -1){
        printf("Error fd");
        return 3;
    }

    printf("Opened\n");
    int x = 97; // in the ascii table 97 = 'a', that is what it prints
    if(write(fd, &x, sizeof(x)) == -1)
    {
        printf("An error occurred \n");
        return 2;
    }
    printf("Written\n");
    close(fd);
    printf("Closed\n");
    return 0;
}

//We have put in the terminal, first "ls"+enter; then "cat myfifo1"+enter;
//with FIFOs we always have to have both ends open, if not, one of the opens is
//going to hang in there,

// We can create the myfifo1 file from the terminal and mkfifo program