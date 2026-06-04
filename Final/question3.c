//Astrid Bailey
//IPC144N1F
//April 16, 2026



#include <stdio.h>

    struct Date{
        int day;
        int month;
        int year;
    };
    struct Time{
        int hour;
        int minute;
        int second;
    };
    struct Stock{
    char name[50];
    struct Date date;
    struct Time time;
    float earnings;
    float peRatio;
    float anticipatedPrice;
    };

void getMembers(struct Stock stocks[], int index);
void calcPrice(struct Stock stocks[], int index);
void displayStock(struct Stock stocks[], int index);
void writeFile(struct Stock stocks[], int index, FILE *ptr);

int main(){

    int numStocks;
    do{
        printf("%s", "How many stocks are you entering?\n");
        scanf("%d", &numStocks);
    }while (numStocks < 5);

    struct Stock stocks[numStocks];

    FILE *fptr = fopen("stock_data.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for(size_t i = 0; i < numStocks; i++){
        getMembers(stocks, i);
        calcPrice(stocks, i);
        displayStock(stocks, i);
        writeFile(stocks, i, fptr);

    }
    
    fclose(fptr);
    
    
    return 0;
}

void getMembers(struct Stock stocks[], int index){
    printf("%s", "Enter the name of the stock\n");
    scanf("%s", &stocks[index].name);
    printf("%s", "Enter the transaction date(DD MM YYYY)\n");
    scanf("%d %d %d", &stocks[index].date.day, &stocks[index].date.month, &stocks[index].date.year);
    printf("%s", "Enter the transaction time(HH MM SS)\n");
    scanf("%d %d %d", &stocks[index].time.hour, &stocks[index].time.minute, &stocks[index].time.second);
    printf("%s", "Enter the estimated earnings for this stock:\n");
    scanf("%f", &stocks[index].earnings);
    printf("%s", "What is the price-to-earnings ratio for this stock?\n");
    scanf("%f", &stocks[index].peRatio);
}

void calcPrice(struct Stock stocks[], int index){
    stocks[index].anticipatedPrice = stocks[index].earnings * stocks[index].peRatio;

}

void displayStock(struct Stock stocks[], int index){
    printf("Stock %s was bought on %d/%d/%d at %d:%d:%d with estimated earnings per share of $%.2f and an estimated price-to-earnings ratio of %.2f\n", stocks[index].name, stocks[index].date.day, stocks[index].date.month, stocks[index].date.year, stocks[index].time.hour, stocks[index].time.minute, stocks[index].time.second, stocks[index].earnings, stocks[index].peRatio);
    printf("The anticipated stock price of %s is $%.2f\n", stocks[index].name, stocks[index].anticipatedPrice);
}

void writeFile(struct Stock stocks[], int index, FILE *ptr){
    fprintf(ptr, "Name: %s, Date: %d/%d/%d, Time: %d:%d:%d, Estimated earnings: %.2f, Price-to-earnings ratio: %f, Anticipated Stock Price: %.2f\n", stocks[index].name, stocks[index].date.day, stocks[index].date.month, stocks[index].date.year, stocks[index].time.hour, stocks[index].time.minute, stocks[index].time.second, stocks[index].earnings, stocks[index].peRatio, stocks[index].anticipatedPrice);
}