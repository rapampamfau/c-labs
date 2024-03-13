#include <stdio.h>
#include <stdlib.h>

#define BOOL char
#define TRUE 1
#define FALSE 0


typedef struct {
    char * name;
    float finalGrade;
} Student;


void bubbleSortImproved(Student *students, int length) {
    while (TRUE) {
        BOOL z = FALSE;
        
        for (int i = 0; i < length -1; i++) {
            if (students[i].finalGrade < students[i + 1].finalGrade) {
                Student temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
                z = TRUE;
            }
        }

        if (z != TRUE) {
            break;
        }
    }   
}

Student* fillData() {
    Student* students = malloc(100 * sizeof(Student));

    for (int i = 0; i < 100; i++) {
        Student student;
        student.name = "Student";
        student.finalGrade = 2.0 + ((float) rand() / RAND_MAX) * (5.0 - 2.0);
        students[i] = student;
    }

    return students;
}

int main() {
    Student* students = fillData();
    int arrLength = 0;

    while (students[arrLength].name != NULL) {
        arrLength++;
    }
    
    bubbleSortImproved(students, arrLength);
    printf("Sorted: \n");
    for (int i = 0; i < arrLength; i++) {
        printf("%.1f\n", students[i].finalGrade);
    }

    free(students);
    

    return 0;
}
