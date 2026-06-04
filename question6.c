//Astrid Bailey
//IPC144N1F
//Midterm February 26, 2026

#include <stdio.h>

int main(void){

    //Get credit card number
    char creditCardNumber[17];
    printf("Enter credit card number: ");
    scanf("%s", creditCardNumber);

    //create arrays for alternating and opposite numbers
    int cardAlternatingDigits[9];
    int cardOppositeDigits[9];


    //Looping through both alternating and opposing numbers to assign each to new array
    int i, j = 0, k = 0;
    for(i = 0; i < 16; i++){
        if(i % 2 == 0){
            cardAlternatingDigits[j] = (creditCardNumber[i] - '0') * 2;
            // printf("%d ", cardAlternatingDigits[j]);
            j++;
        }
        else{
            cardOppositeDigits[k] = (creditCardNumber[i] - '0');
            k++;
        }
    }

    //Subtract 9 from any subscript greater than or equal to 10
    for(i = 0; i < 8; i++){
        if(cardAlternatingDigits[i] >= 10){
            cardAlternatingDigits[i] = cardAlternatingDigits[i] - 9;
        }
    }

    //Calculate the sum of each new array
    int sumAlternating = 0, sumOpposite = 0;
    for(i = 0; i < 8; i++){
        sumAlternating = sumAlternating + cardAlternatingDigits[i];
        sumOpposite = sumOpposite + cardOppositeDigits[i];
    }

    //Calculate the sum of both arrays and validate
    int totalSum;
    totalSum = sumAlternating + sumOpposite;
    if(totalSum % 10 == 0){
        printf("This card number is valid");
    }
    else{
        printf("This card number is not valid");
    }

    
    return 0;
}