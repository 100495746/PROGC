//
// Created by Raúl Armas Seriñá on 5/2/24.
//
#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2, int num3) {
    int result;
    if (num1 >= num2 && num1 >= num3) { // && = and
        result = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        result = num2;
    } else {
        result = num3;
    }
    return result;

}

int main() {
    if (3 > 2 || 2 > 5) {// || = or, != not equal, == equal...!(3>2) is negated
        printf("True");
    } else {
        printf("False");
    }
    printf("%d", max(4, 10, 20));
    int index = 5;
    while (index <= 5) {
        printf("%d\n", index);
        index++; // index+=1

    }
    //do while loop
    do {
        printf("%d\n", index);
        index++;
    } while (index <= 5); // we do the loop once before checking condition


    int i; // we have to declare the "counter"
    for (i = 1; i <= 5; i++) {
        // Inside the for loop we have 3 things, var i-> counter ; i<= 5 (repeat until); i++ (i+=1 per iteration)
        printf("%d\n", i);
    }


    return 0;
}