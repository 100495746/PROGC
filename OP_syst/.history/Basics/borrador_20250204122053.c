#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[20];
    int age;
    float grade;
};

int main() {
    int number;
    printf("Enter number of students: ");
    scanf("%d", &number); //remember, scanf stores it in an address, number might be confused with an address thus segmentation fault, so we give its address

    struct Student student[number];

    for (int i=0; i<number; ++i){
        printf("Enter details of student %d", i+1);
        printf("Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        printf("Age: ");
        scanf("%d", &student[i].age);
        printf("Grade: ");
        scanf("%f", &student[i].grade);
        // Clear the input buffer after each scanf
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    FILE *file = fopen("fichero2", "wb");
    size_t written = fwrite(&student, number*sizeof(struct Student), number ,file);
    if (written != number) {
        printf("Error writing to file\n");
    } else {
        printf("Data written to file successfully\n");
    }

    file = fopen("fichero2", "rb");
    size_t content= fread(&student, number*sizeof(struct Student), number ,file);

    fclose(file);

    printf("%", content);
    
    

    return 0;
}