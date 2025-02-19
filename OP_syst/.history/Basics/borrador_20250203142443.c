#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()



int main() {
    char name[20];
    char *str = NULL;
    char buffer[100]; // to read chunks of the input
    size_t str_size = 0;

    printf("Enter file name: ");
    scanf("%s", name);
     FILE *file = fopen(name, "w");
    //the pointer points to an address, so without the "*" it gives whatever is stored at the address
    if(file== NULL){
        printf("File not found");

    }

    // Clear the input buffer to avoid issues with fgets
    int c;
    //getchar reads a single char from stdin and returns an unsigned char casted into an int or EOF
    while ((c = getchar()) != '\n' && c != EOF) {}



    printf("Write what you want to write into the file: ");
    while (fgets(buffer, sizeof(buffer), file)) {
        //determines the length of the input read into the buffer
        size_t buffer_len = strlen(buffer);


        // Reallocate memory to accommodate the new input
        char *new_str = realloc(str, str_size + buffer_len + 1);
        if (new_str == NULL) {
            printf("Memory allocation failed\n");
            free(str);
            return 1;
        }

        // Remember that an array is basically a memory address
        str = new_str;

        // Copy the buffer to the end of the allocated string
        strcpy(str + str_size, buffer); //appends the contents of buffer to the end of str.
        str_size += buffer_len;

        // Check if the input ends with a newline character
        if (buffer[buffer_len - 1] == '\n') {
            break;
        }
    }

    

    
    // Write the string to the file
    printf("Content of ", str);
    fclose(file);
    free(str); // always free pointers


    }
   