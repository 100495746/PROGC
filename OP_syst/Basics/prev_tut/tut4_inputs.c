#include <stdio.h>

int main(void) {
    int age; // for, inputs we need to create and declare "empty" variables
    double gpa;
    char grade[12]; // we need to specify how many characters
    char name[20];
    /*printf("Enter your age: ");
    scanf("%d", &age); //allows the user to input something, we need to put the type that will be input (%d ect)
    // and the variable where it will be stored accompanied by &
    printf("You are %d years old\n", age);
    printf("Enter your gpa:");
    scanf("%lf", &gpa);  // lf is for doubles
    printf("Your gpa is %lf", gpa);
    printf("\nEnter your grade: ");
    scanf("%s", &grade);
    printf("your grade is %s\n", grade);
    scanf("%s", name);
    printf("Your name is %s", &name);// only scans until the first space (Jhon Smith-> Jhon)
*/

    printf("\n Enter name and surname");
    fgets(name, 20, stdin); // name where to store it, space it occupies,stdin= standard input
    // the only downside of fgets is it prints a new blank line/ things after a var in new line
    printf("Name and surname: %s nani?", name);


    // %f = float, %d = integers, %s = string of chars


    return 0;

}