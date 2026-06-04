//Astrid Bailey
//IPC144N1F
//Midterm February 26, 2026

#include <stdio.h>

//Function Prototype
void convertToRoman(int year);

int main(void){

    int year;
    
    //Loop will continue to prompt user for year as long as integer given is positive
    while(1){

        printf("Enter a year (positive integer): \n");
        scanf("%d", &year);
        if(year < 0){
            //Range check to ensure integer is positive - loop will break if integer is negative
            printf("Invalid input");
            break;
        }
        else{
            convertToRoman(year);
        }
    }

    return 0;
}

//Function to covert a year to a Roman numeral
void convertToRoman(int year){
    printf("Roman Equivalent: ");

    //Initialize variables for function
    int thousand, hundred, hundredRemainder, ten, tenRemainder, one;

    //Separation of digits

    //Separate thousand
    thousand = year / 1000;
    //Separate hundred
    hundredRemainder = year % 1000;
    hundred = hundredRemainder / 100;
    //Separate ten
    tenRemainder = year % 100;
    ten = tenRemainder / 10;
    //Separate one
    one = year % 10;

    int i;
    //Iteration to generate Roman numerals for thousands
    while(i < thousand){
        printf("M");
        i++;
    }

    //Switch case to generate Roman numerals for hundreds
    switch(hundred){
        case 1:
            printf("C");
            break;
        case 2:
            printf("CC");
            break;
        case 3:
            printf("CCC");
            break;
        case 4:
            printf("CD");
            break;
        case 5:
            printf("D");
            break;
        case 6:
            printf("DC");
            break;
        case 7:
            printf("DCC");
            break;
        case 8:
            printf("DCCC");
            break;
        case 9:
            printf("CM");
            break;
    }

    //Switch case to generate Roman numerals for tens
    switch(ten){
        case 1:
            printf("X");
            break;
        case 2:
            printf("XX");
            break;
        case 3:
            printf("XXX");
            break;
        case 4:
            printf("XL");
            break;
        case 5:
            printf("L");
            break;
        case 6:
            printf("LX");
            break;
        case 7:
            printf("LXX");
            break;
        case 8:
            printf("LXXX");
            break;
        case 9:
            printf("XC");
            break;
    }

    //Switch case to generate Roman numerals for ones
    switch(one){
        case 1:
            printf("I");
            break;
        case 2:
            printf("II");
            break;
        case 3:
            printf("III");
            break;
        case 4:
            printf("IV");
            break;
        case 5:
            printf("V");
            break;
        case 6:
            printf("VI");
            break;
        case 7:
            printf("VII");
            break;
        case 8:
            printf("VIII");
            break;
        case 9:
            printf("IX");
            break;
    }
    //New line to separate each user response
    printf("\n");
}