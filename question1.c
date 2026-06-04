//Astrid Bailey
//IPC144N1F
//Midterm February 26, 2026

#include <stdio.h>

//Function Prototype
double calc_intelligence(double x, double y);

int main(void){

    //Initialize variables
    double i, x;
    int y = 1;

    //Print table headings
    printf("y\tx\ti\t\n");
    printf("%s", "-------------------\n");

    //Outer loop to detect when y reaches 6
    while(y <= 6){
        x = 5.5;
        
        //Inner loop to detect each time x reaches 12.5
        while(x <= 12.5){
            i = calc_intelligence(x, y);
            printf("%d\t%.2lf\t%.2lf\t\n", y, x, i);
            x+=0.5;
        }
        y++;
    }
    return 0;
}

//Function to calculate value of i within inner loop
double calc_intelligence(double x, double y){
    double i = 2 + (y + 0.5 * x);
    return i;
}