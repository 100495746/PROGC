#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    char *str = NULL;
    char buffer[100];
    size_t str_size = 0;

    printf("Enter file name: ");
    scanf("%s", name);

    int c;
    //getchar reads a single char from stdin and returns an unsigned char casted into an int or EOF
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    // Open the file in read mode to read its contents
    FILE *file = fopen(name, "r");
    

    // Prompt the user to enter additional content
    printf("Write what you want to append to the file: ");
    while (fgets(buffer, sizeof(buffer), stdin)) {
        size_t buffer_len = strlen(buffer);

        char *new_str = realloc(str, str_size + buffer_len + 1);
        if (new_str == NULL) {
            printf("Memory allocation failed\n");
            free(str);
            return 1;
        }

        str = new_str;

        strcpy(str + str_size, buffer);
        str_size += buffer_len;

        if (buffer[buffer_len - 1] == '\n') {
            break;
        }
    }

    // Open the file in append mode to add the new content
    file = fopen(name, "a");
    if (file == NULL) {
        printf("File not found\n");
        free(str);
        return 1;
    }

    // Write the new content to the file
    fputs(str, file);
    fprintf(file, str,)
    printf("String written to file successfully.\n");

    fclose(file);
    free(str);

    return 0;
}