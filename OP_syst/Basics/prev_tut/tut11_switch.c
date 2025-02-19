//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdlib.h>
#include <printf.h>

int main() {

    char grade = 'k';

    switch (grade) {
        case 'A':
            printf("You did great! ");
            break;
        case 'B':
            printf("You did alright! ");
            break;
        case 'C':
            printf("You did poorly ");
            break;
        case 'D':
            printf("You did very poorly ");
            break;
        case 'F':
            printf("womp womp ");
            break;
        default :
            printf("Invalid Grade"); // basically an else

    }

    return 0;
}