/*
Author: Blessam
Date: 2026-10-15
Description: A simple student management system 
*/

#include <stdio.h>
#include <string.h>

float calculate_grade(float grade1, float grade2, float grade3) {
    return (grade1 + grade2 + grade3) / 3.0f;
}

int main(){
    int pin = 0;
    int attempts = 0;
    const int correct_pin = 9876;
    char students_name[60];
    int students_age;
    double tution_balance;


    printf("Feel Welcomed to the Student Management System\n");

    printf("Please enter your pin: ");
    scanf("%d", &pin);

    while (pin != correct_pin && attempts < 3) {
        attempts++;
        if (attempts == 3) {
            break;
        }
        printf("Please enter your pin: ");
        scanf("%d", &pin);
        if (pin != correct_pin) {
            printf("Incorrect pin. Attempts remaining: %d\n", 3 - attempts);
        }
    }
    if (attempts == 3 && pin != correct_pin) {
        printf("Too many incorrect attempts. Access denied.\n");
        return 1;
    }

    printf("Access granted. Welcome to the Student Management System!\n");

    printf("\nPlease enter the student's name: ");
    scanf(" %59[^\n]", students_name);

    printf("Please enter the student's age: ");
    scanf("%d", &students_age);

    printf("Please enter the student's tuition balance: ");
    scanf("%lf", &tution_balance);

    float grade1, grade2, grade3;
    printf("Enter the first grade: ");
    scanf("%f", &grade1);
    printf("Enter the second grade: ");
    scanf("%f", &grade2);
    printf("Enter the third grade: ");
    scanf("%f", &grade3);

    float average = calculate_grade(grade1, grade2, grade3);
    printf("The average grade is: %.2f\n", average);

    if (average >= 70.0) {
        printf("Attained a First Class Honors\n");
    } else if (average >= 60.0 && average < 70.0) {
        printf("Attained a Second Class Upper\n");
    } else if (average >= 50.0 && average < 60.0) {
        printf("Attained a Second Class Lower\n");
    } else {
        printf("Pass/Needs Improvement\n");
    }
    return 0;
}