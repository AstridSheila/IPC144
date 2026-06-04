//Astrid Bailey
//IPC144N1F
//April 16, 2026

#include <stdio.h>

long int fibonacci(int counter);

int main(){

    printf("%s", "How many times should the sequence be calculated?\n");
    int n;
    scanf("%d", &n);

    long int fibonacciNumber = fibonacci(n - 1);

    printf("The %d number in the Fibonaci sequence is %ld.\n", n, fibonacciNumber);


    
    return 0;
}

long int fibonacci(int counter){

    if(counter <= 1){
        return counter;
    } else{
        return fibonacci(counter - 1) + fibonacci(counter - 2);
    }
}