#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // null pointer to hold dynamically allocated string (so that we can extend it)
    char *str = NULL;
    char buffer[100]; // to read chunks of the input
    size_t str_size = 0; // keep track of the size of the allocated string

    printf("Enter a string (end with ENTER): ");

    // at the moment we press enter, the input string is stored at "stdin"
    // fgets reads an stdin of at most sizeof(buffer)-1 , and stores it on "buffer"
    //when fgets read the end of file (or end of string !! not to confuse with end of line) returns Null =>false
    while (fgets(buffer, sizeof(buffer), stdin)) {
        //determines the length of the input read into the buffer
        size_t buffer_len = strlen(buffer);


        // Reallocate memory to accommodate the new input
        char *new_str = realloc(str, str_size + buffer_len + 1);
        if (new_str == NULL) {
            printf("Memory allocation failed\n");
            free(str);
            return 1;
        }

        // Remember that
        str = new_str;

        // Copy the buffer to the end of the allocated string
        strcpy(str + str_size, buffer); //appends the contents of buffer to the end of str.
        str_size += buffer_len;

        // Check if the input ends with a newline character
        if (buffer[buffer_len - 1] == '\n') {
            break;
        }
    }

    printf("You entered: %s", str);

    // Free the allocated memory
    free(str);

    return 0;
}