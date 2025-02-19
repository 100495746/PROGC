#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int NumberRand, NumberGuess=-1;
    srand(time(NULL));
    NumberRand= (rand()%100)+1;
    printf("Welcome to the Number Guessing Game!");
    printf("I have selected a number between 1 and 100. Try to guess it! \n");
    do
    {printf("Enter guess: ");
    scanf("%d", &NumberGuess);
    }
    


}