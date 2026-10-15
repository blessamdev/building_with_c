/*
Author: Blessam
Date: 2026-10-15
Description: An advanced student management system with file persistence 
*/

#include <stdio.h>
#include <string.h>

float calculate_grade(float marks1, float marks2, float marks3) {
    return (marks1 + marks2 + marks3) / 3.0f;
}

int main(){
    int pin = 0;
    int attempts = 0;
    const int correct_pin = 9876;
    char students_name[60];
    int students_age;
    double tuition_balance;

    printf("========================================\n");
    printf("   WELCOME TO STUDENT MANAGEMENT SYSTEM \n");
    printf("========================================\n");

    // PIN Verification Loop
    while (attempts < 3) {
        printf("Please enter your pin: ");
        scanf("%d", &pin);

        if (pin == correct_pin) {
            printf("Access granted. Welcome!\n\n");
            break;
        } else {
            attempts++;
            if (attempts == 3) {
                printf("Too many incorrect attempts. Access denied.\n");
                return 1;
            }
            printf("Incorrect pin. Attempts remaining: %d\n", 3 - attempts);
        }
    }

    // Input Student Details
    printf("--- Enter Student Details ---\n");
    printf("Student's full name: ");
    scanf(" %59[^\n]", students_name);

    printf("Student's age: ");
    scanf("%d", &students_age);

    printf("Tuition balance (Ksh): ");
    scanf("%lf", &tuition_balance);

    // Input Grades
    float grade1, grade2, grade3;
    printf("\nEnter 3 exam grades:\n");
    printf("Grade 1: ");
    scanf("%f", &grade1);
    printf("Grade 2: ");
    scanf("%f", &grade2);
    printf("Grade 3: ");
    scanf("%f", &grade3);

    float average = calculate_grade(grade1, grade2, grade3);
    printf("\nThe average grade is: %.2f\n", average);

    char classification[40];

    if (average >= 70.0) {
        strcpy(classification, "First Class Honors");
    } else if (average >= 60.0 && average < 70.0) {
        strcpy(classification, "Second Class Upper");
    } else if (average >= 50.0 && average < 60.0) {
        strcpy(classification, "Second Class Lower");
    } else {
        strcpy(classification, "Pass/Needs Improvement");
    }

    printf("Standing: %s\n", classification);

    // ✨ NEW FEATURE: Save record to a text file
    FILE *file = fopen("student_records.txt", "a"); // "a" appends data to the file
    if (file != NULL) {
        fprintf(file, "Name: %s | Age: %d | Balance: Ksh %.2lf | Average: %.2f | Standing: %s\n", 
                students_name, students_age, tuition_balance, average, classification);
        fclose(file);
        printf("\n[Success: Record saved to 'student_records.txt']\n");
    } else {
        printf("\n[Error: Could not save record to file]\n");
    }

    return 0;
}