//
// Created by Raúl Armas Seriñá on 5/2/24.
//

#include <stdio.h>

int main() {
    char color[20];
    char pluralNoun[20];
    char celebrity[20];
    printf("Enter a color: ");
    scanf("%s, color"); //& is not needed for strings of chars
    printf("Enter a plural: ");
    scanf("%s, pluralNoun");
    printf("Enter a celebrity: ");
    scanf("%s%s, celebrity"); // with two %s, the program will wait always for two inputs

    printf("Roses are {color}\n");
    printf("{pluralNoun} are blue\n");
    printf("I love {celebrity}\n");


    return 0;
}