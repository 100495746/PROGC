#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // null pointer to hold dynamically allocated string (so that we can extend it)
    char *str = NULL;
    char buffer[100]; // to read chunks of the input
    size_t str_size = 0; // keep track of the size of the allocated string

    printf("Enter a string (end with ENTER): ");

    while (fgets(buffer, sizeof(buffer), stdin)) {
        size_t buffer_len = strlen(buffer);
        

        // Reallocate memory to accommodate the new input
        char *new_str = realloc(str, str_size + buffer_len + 1);
        if (new_str == NULL) {
            printf("Memory allocation failed\n");
            free(str);
            return 1;
        }

        str = new_str;

        // Copy the buffer to the end of the allocated string
        strcpy(str + str_size, buffer);
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