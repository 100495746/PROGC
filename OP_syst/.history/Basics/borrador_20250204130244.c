#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[20];
    int age;
    float grade;
};

int main() {
    int c;
    int number;
    char option[10];
    printf("Enter number of students: ");
    scanf("%d", &number); //remember, scanf stores it in an address, number might be confused with an address thus segmentation fault, so we give its address
    while ((c = getchar()) != '\n' && c != EOF) {}

    struct Student student[number];

    for (int i=0; i<number; ++i){
        printf("Enter details of student %d \n", i+1);
        printf("Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0'; // Remove trailing newline



        printf("Age: ");
        scanf("%d", &student[i].age);
        printf("Grade: ");
        scanf("%f", &student[i].grade);

        // Clear the input buffer after each scanf
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    FILE *file = fopen("fichero2", "wb");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }



    size_t written = fwrite(&student, sizeof(struct Student), number ,file);
    if (written != number) {
        printf("Error writing to file\n");
    } else {
        printf("Data written to file successfully\n");
    }
    fclose(file);

    file = fopen("fichero2", "rb");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }
    
    size_t content= fread(student, sizeof(struct Student), number ,file);
    printf("Reading from file...");
    if (content != number) {
        printf("Error reading from file\n");
    } else {
        printf("Data read from file successfully\n");
    }
    fclose(file);

    // Print the content of the students array
    for (int i = 0; i < number; ++i) {
        printf("\nDetails of student %d\n", i + 1);
        printf("Name: %s\n", student[i].name);
        printf("Age: %d\n", student[i].age);
        printf("Grade: %.2f\n", student[i].grade);
    }

    int student_number;
    printf("Enter student number to modify %d-%d", 1, number);
    scanf("%d", &student_number);
    printf("Modify age or grade?: ");
    fgets(option, sizeof(option), stdin);
    option[strcspn(option, "\n")] = '\0';
    //fseek: move the file pointer to a specific location within a file
    //int fseek(FILE *stream, long int offset, int whence);

    /*
        stream: Pointer to the FILE object that identifies the stream.
        offset: Number of bytes to offset from whence.
        whence: Position from where the offset is added. It can be one of the following constants:
        SEEK_SET: Beginning of the file.
        SEEK_CUR: Current position of the file pointer.
        SEEK_END: End of the file.
    
    */

   if (student_number<1 || student_number> number){
    printf("Student %d does not exist, there are only %d students.\n", student_number, number);
   }


    if(strcmp(option, "age") == 0){
        printf("Enter new age: ");
        scanf

    } else if (strcmp(option, "grade") == 0) {
       
    } else{
        printf("Invalid option");
    }


    return 0;
}