#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int Number1, Number2;
    char oper[2];
    int result;
    bool isfloat=false;

    printf("Enter the first number: ");
    scanf("%f", Number1);
    printf("Enter the second number: ");
    scanf("%f", Number2);
    printf("Choose an operation (+, -, *, /): +");
    scanf("%s", oper);
    if (oper=="+"){
        result= Number1+Number2;
    } else if (oper == "-")
    {
        result=Number1-Number2;
    } else if (oper=="*")
    {
        result = Number1 * Number2;
    } else if (oper== "/")
    {
        if (Number1%Number2 ==0){
            result = Number1/Number2;
        } else{
            result = (float)Number1/Number2;
            isfloat!=isfloat
        }
    
    };
    
    printf("The result is %d", result);

}