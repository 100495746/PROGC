#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Required for malloc()

int digit_counter(int num){
    int digits=0;
    do{
        digits++;
    }while(abs(num)/10>=1);

    return digits;

}


int main() {
    


    }
   