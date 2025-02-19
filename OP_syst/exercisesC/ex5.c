//
// Created by Raúl Armas Seriñá on 17/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void executeCommand(char* command){
    if (strcmp(command, "NoName" ) == 0){
        printf("No name introduced");
        return;
    }
    else if (strcmp(command, "NoAge") == 0){
        printf("No age introduced");
        return;
    }
}
int main(){
    char* name = malloc(50 * sizeof(char));
    int age;
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    printf("Enter your age: ");
    scanf("%d", &age);
    if (!(name)){
        executeCommand("NoName");
    }
    else if (!(age)){
        executeCommand("NoAge");
    }
    else{
        name[strcspn(name, "\n")] = '\0';
        printf("Name: %s Age: %d", name, age);
    }
    return 0;
}