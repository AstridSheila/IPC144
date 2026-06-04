//Astrid Bailey
//IPC144N1F
//Midterm February 26, 2026

#include <stdio.h>

//Function Prototypes
double calc_average(int grade1, int grade2, int grade3, int grade4, int grade5);
char determine_grade(int score);

int main(void){

    //Initialize variables for grades
    int grade1, grade2, grade3, grade4, grade5;

    //Display letter grades and average
    printf("Please enter 5 grades: ");
    scanf("%d%d%d%d%d", &grade1, &grade2, &grade3, &grade4, &grade5);
    printf("Score %d\t%c\n", grade1, determine_grade(grade1));
    printf("Score %d\t%c\n", grade2, determine_grade(grade2));
    printf("Score %d\t%c\n", grade3, determine_grade(grade3));
    printf("Score %d\t%c\n", grade4, determine_grade(grade4));
    printf("Score %d\t%c\n", grade5, determine_grade(grade5));
    printf("Average grade is %.2lf", calc_average(grade1, grade2, grade3, grade4, grade5));

    return 0;
}

//Function to calculate the average of given scores
double calc_average(int grade1, int grade2, int grade3, int grade4, int grade5){
    double average = (double)(grade1 + grade2 + grade3 + grade4 + grade5) / 5;
    return average;
}
//Function to determine letter grade
char determine_grade(int score){
    char letterGrade;

    //Determine letter grade based on score
    if(score >= 90 && score <= 100){
        letterGrade = 'A';
    }
    else if(score >= 80 && score < 90){
        letterGrade = 'B';
    }
    else if(score >= 70 && score < 80){
        letterGrade = 'C';
    }
    else if(score >= 60 && score < 70){
        letterGrade = 'D';
    }
    else if(score >= 0 && score < 60){
        letterGrade = 'F';
    }

    return letterGrade;
}