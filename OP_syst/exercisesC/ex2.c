//
// Created by Raúl Armas Seriñá on 17/3/24.
//
#include <stdio.h>
int main(){
    char name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    printf("Hello %s", name);
    return 0;
}