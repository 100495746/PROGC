//
// Created by Raúl Armas Seriñá on 14/3/24.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char path[1035];

    /* Open the command for reading. */
    fp = popen("/usr/bin/which ping", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    /* close */
    pclose(fp);

    return 0;
}