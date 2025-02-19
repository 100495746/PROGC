//
// Created by Raúl Armas Seriñá on 6/5/24.
//
#include <stdio.h>
#include <stdlib.h>


int main() {
    int ex1(), ex2(), ex3(), ex4();

    ex3();
}


int ex1(){
    int i, n;
    float *element; // Pointer to float type to store elements

    //element is a pointer to a float type
    //while *element is the value of the element

    printf("\n\n Pointer : Find the largest element using Dynamic Memory Allocation :\n");
    printf("-------------------------------------------------------------------------\n");

    // Input the total number of elements
    printf(" Input total number of elements (1 to 100): ");
    scanf("%d", &n);

    element = (float *)malloc(n * sizeof(float)); // Allocate memory for 'n' elements
    //element points to the first element of the memory block
    //by putting (float *) we are casting the memory block to a float type pointer(it was a void pointer)
    // (float) would convert it to float and not a float pointer

    if (element == NULL) {
        printf(" No memory is allocated."); // If memory allocation fails
        exit(0);
    }

    printf("\n");

    // Input 'n' numbers and store them dynamically in the allocated memory
    for (i = 0; i < n; i++) {
        printf(" Number %d: ", i + 1);
        scanf("%f", element + i);
    }

    // Find the largest element among the 'n' elements
    for (i = 1; i < n; ++i) {
        if (*element < *(element + i)) {
            *element = *(element + i); // Store the largest element in the first memory location
        }
    }

    printf(" The Largest element is :  %.2f \n\n", *element); // Display the largest element found
    free(element); //??
    return 0;
}



// C program to calculate length using pointer
int ex2(){
    char str[25];
    int l;
    int ex2calcLength(char*);

    printf("Calculate string length\n");
    printf("---------------------\n\n");

    printf("Input a string: ");
    fgets(str, sizeof(str), stdin);
    l =  ex2calcLength(str);
    printf("The length from string is %d: ", l);
//

};

int ex2calcLength(char* ch)
{
    int count = 0;
    //strings all end (in memory) with null pointer \0
    while ( *ch != '\0')
    {
        if (*ch != '\n'){
            count++;
        }
            ch++;

    }
    return count;

}


//Write a program in C to print all permutations of a given string using pointers.

//abc-> bac, cba,acb,bca, cab->  6 posibilities
void changePos(char *ch1, char *ch2){
    char tmp;
    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}

void charPer(char *cht, int stno, int endno){
    int i;
    if (stno == endno){
        printf("%s\n",cht);
    }
    else{
        for(i = stno; i<endno; i++){

            changePos((cht+stno), (cht+i));
            charPer(cht, stno +1, endno);
            changePos((cht+stno), (cht+i));
        }
    }

}



int ex3(){
    char str[25];
    int f = 1;
    printf("----Permutations---\n");
    printf("Input string: ");
    scanf("%s", str);
    int n = ex2calcLength(str);
    charPer(str,0, n);
    for(int i=n; i>1; i--){
        f = f*(i);
    }
    printf("\nNumber of permutations = %d", f);

    return 0;


}
