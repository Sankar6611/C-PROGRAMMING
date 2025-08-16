c
#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks[3];
    float average;
};

int main() {
    struct Student student;
    float total = 0;
    
    printf("Enter student details:\n");
    
    printf("Roll Number: ");
    scanf("%d", &student.rollNo);
    
    printf("Name: ");
    getchar(); // Clear input buffer
    fgets(student.name, sizeof(student.name), stdin);
    
    // Remove newline from name
    if (student.name[strlen(student.name) - 1] == '\n') {
        student.name[strlen(student.name) - 1] = '\0';
    }
    
    printf("Enter marks for 3 subjects:\n");
    for (int i = 0; i < 3; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student.marks[i]);
        total += student.marks[i];
    }
    
    student.average = total / 3;
    
    printf("\n--- Student Information ---\n");
    printf("Roll Number: %d\n", student.rollNo);
    printf("Name: %s\n", student.name);
    printf("Marks: ");
    for (int i = 0; i < 3; i++) {
        printf("%.2f ", student.marks[i]);
    }
    printf("\nAverage: %.2f\n", student.average);
    
    return 0;
}
