//Astrid Bailey
//IPC144N1F
//Midterm February 26, 2026

#include <stdio.h>
#include <math.h>

//Function Prototypes
double distance(double x1, double y1, double x2, double y2);
double triangleArea(double a, double b, double c, double s);

int main(void){

    //Initialize and prompt user for points 1, 2, and 3
    double p1x, p1y, p2x, p2y, p3x, p3y;
    printf("Enter point 1 (x and y) in m: \n");
    scanf("%lf%lf", &p1x, &p1y);
    printf("Enter point 2 (x and y) in m: \n");
    scanf("%lf%lf", &p2x, &p2y);
    printf("Enter point 3 (x and y) in m: \n");
    scanf("%lf%lf", &p3x, &p3y);
    
    //Get values for distances between points
    double a, b, c;
    a = distance(p1x, p1y, p2x, p2y);
    b = distance(p2x, p2y, p3x, p3y);
    c = distance(p3x, p3y, p1x, p1y);
    printf("The distance between point 1 and point 2 is %.4lfm\n", a);
    printf("The distance between point 2 and point 3 is %.4lfm\n", b);
    printf("The distance between point 3 and point 1 is %.4lfm\n", c);
    

    //Get value for s
    double s = (a + b + c) / 2;
    
    
    //Display the area of the triangle
    double area = triangleArea(a, b, c, s);
    printf("The area of this triangle is %.4lfm squared\n", area);

    return 0;
}

//Function to implement Pythagoras' Theorem to calculate distance between 2 points
double distance(double x1, double y1, double x2, double y2){

    double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return distance;
}

//Function to calculate the area of the triangle
double triangleArea(double a, double b, double c, double s){
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}