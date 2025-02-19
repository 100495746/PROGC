//
// Created by Raúl Armas Seriñá on 17/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int numb;
    int result = 0;
    int array[10];
    printf("Enter number: ");
    scanf("%d", &numb);
    int i = 0;
    for (i; i<sizeof(array)/sizeof(array[1]); i++ ){
        array[i] = numb;
        result += numb;
    }
    printf("For result: %d \n", result);
    result=0;

    i = 0;
    while (i<sizeof(array)/sizeof(array[1])){
        result += numb;
        i++;
    }
    printf("While result: %d", result);

    return 0;
}