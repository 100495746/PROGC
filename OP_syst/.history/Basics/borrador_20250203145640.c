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

    // Clear the input buffer to avoid issues with fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Write what you want to write into the file: ");
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

    FILE *file = fopen(name, "w");
    if (file == NULL) {
        printf("File not found\n");
        free(str);
        return 1;
    }

    fputs(str, file);
    printf("String written to file successfully.\n");

    fclose(file);
    free(str);

    return 0;
}
   