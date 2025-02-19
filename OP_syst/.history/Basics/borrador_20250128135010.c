#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int Number1, Number2;
    char oper[2];
    union {
        int intResult;
        float floatResult;
    } result;
    bool isfloat=false;

    printf("Enter the first number: ");
    scanf("%d", &Number1);
    printf("Enter the second number: ");
    scanf("%d", &Number2);
    printf("Choose an operation (+, -, *, /): ");
    scanf("%s", oper);
    if (strcmp(oper, "+")==0){
        result.intResult= Number1+Number2;

    } else if (strcmp(oper, "-")==0)
    {
        result.intResult=Number1-Number2;
    } else if (strcmp(oper, "*")==0)
    {
        result.intResult = Number1 * Number2;
    } else if (strcmp(oper, "/")==0)
    {
        if 
        if (Number1%Number2 ==0){
            result.intResult = Number1/Number2;
        } else{

            result.floatResult = (float)Number1/(float)Number2;
            isfloat= true;
        }
    
    }else{
        printf("invalid operation. \n");
        return -1;
    };
    if (isfloat){
        printf("The result is %f\n", result.floatResult);

    }else{
        printf("The result is %d\n", result.intResult);
    }

}