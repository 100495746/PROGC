#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main() {
    int NumberIn;
    char Day[9];
    printf("Enter a number (1-7) for the day of the week: ");
    scanf("%d", &NumberIn);
    switch(NumberIn){
        case 1:
            strcpy(Day, "Monday");
            break;
        case 2:
            strcpy(Day, "Tues");
            break;
        case 3:
            strcpy(Day, "Monday");
            break;
        case 4:
            strcpy(Day, "Monday");
            break;
        case 5:
            strcpy(Day, "Monday");
            break;
        case 6:
            strcpy(Day, "Monday");
            break;
        case 7:
            strcpy(Day, "Monday");
            break;
        default:
            strcpy(Day, "?");
            break;

    }
    printf("The day is %9s.", Day);
    return 0;


}