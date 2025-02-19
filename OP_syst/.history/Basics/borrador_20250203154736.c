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

    FILE *file = fopen(name, "a");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }




    while (fgets(buffer, sizeof(buffer), file)) {
        size_t buffer_len = strlen(buffer);

        char *new_str = realloc(str, str_size + buffer_len + 1);
        if (new_str == NULL) {
            printf("Memory allocation failed\n");
            free(str);
            fclose(file);
            return 1;
        }

        str = new_str;

        strcpy(str + str_size, buffer);
        str_size += buffer_len;
    }

    printf("Content of %s:\n%s", name, str);

    fclose(file);
    free(str);

    return 0;
}