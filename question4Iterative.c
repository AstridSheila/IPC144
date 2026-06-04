//Astrid Bailey
//IPC144N1F
//Midterm February 26, 2026

#include <stdio.h>

//Function Prototype
int integerPower(int base, int exp);

int main(void){

    //Initialize and get value of base and exponent
    int base, exp;
    printf("Enter an integer, and an exponent between 1 and 100: \n");
    scanf("%d%d", &base, &exp);

    //Range check to ensure exponent value is between 1 and 100
    if(exp < 1 || exp > 100){
        printf("%d is not a valid exponent. Please enter an integer between 1 and 100.\n", exp);
    }
    else{
        printf("%d to the power of %d is %d", base, exp, integerPower(base, exp));
    }
    return 0;
}

//Function to loop through exponential multiplication
int integerPower(int base, int exp){
    int power = base;
    int i;
    for(i = 1; i < exp; i++){
        power = power * base;
    }
    return power;
}