#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main() {
    char name[50];
    printf("Enter your full name:");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    printf("Hello, %s!", &name);
    return 0;


}