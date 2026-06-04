//Astrid Bailey
//IPC144N1F
//April 16, 2026

void inputWeather(float weather[4][7][3]);
float weeklyAvgTemp(float weather[4][7][3], int city);
void printCityReport(float weather[4][7][3], int city);
int hottestCity(float weather[4][7][3]);

#include <stdio.h>

int main(){

    float weather[4][7][3];
    // float weather[4][7][3] = {{{22.5, 55, 10}, {23.1, 57, 12}, {21.8, 57, 12}, {22, 54, 9}, {23.5, 56, 11}, {24, 55, 10}, {22.9, 57, 12}}, {{25.5, 60, 15}, {26.1, 62, 14}, {27, 63, 16}, {25.9, 61, 13}, {26.5, 60, 15}, {26.8, 62, 14}, {27.2, 63, 16}}, {{18.5, 50, 7}, {19, 52, 8}, {18.8, 51, 6}, {19.2, 50, 7}, {18.9, 52, 6}, {19.1, 51, 7}, {18.7, 50, 8}},  {{30, 70, 20}, {31.2, 72, 18}, {29.5, 69, 22}, {30.8, 71, 19}, {31, 70, 21}, {30.5, 72, 20}, {31.5, 73, 22}}};
    int city;

    inputWeather(weather);
    printf("%s", "Which city would you like to view?\n");
    scanf("%d", &city);
    printf("The average temperature for city %d this week is %.1f\n", city, weeklyAvgTemp(weather, city));
    printCityReport(weather, city);
    printf("The hottest city this week was city %d\n", hottestCity(weather));
    return 0;
}

void inputWeather(float weather[4][7][3]){
    float temp, humidity, wind;
    for (size_t i = 0; i <= 3; i++){
        for(size_t j = 0; j <= 6; j++){
            printf("Enter the temperature, humidity, and wind speed for city %u on day %u\n", i + 1, j + 1);
            scanf("%f %f %f", &temp, &humidity, &wind);
            weather[i][j][0] = temp;
            weather[i][j][1] = humidity;
            weather[i][j][2] = wind;
        }
    }
}

float weeklyAvgTemp(float weather[4][7][3], int city){
    float tempTotal = 0.0;
    for(size_t i = 0; i <= 6; i++){
        tempTotal = tempTotal + weather[city][i][0];
    }
    float avgTemp = tempTotal / 7;
    return avgTemp;
}

void printCityReport(float weather[4][7][3], int city){
    printf("City %d Weekly Weather Report:\n", city);
    for(size_t i = 0; i <= 6; i++){
        printf("Day %u:   Temp: %.1fC: Humidity: %.1f%%, Wind Speed: %.1fkm/h\n", i + 1, weather[city][i][0], weather[city][i][1], weather[city][i][2]);
    }
}

int hottestCity(float weather[4][7][3]){
    float hottestTemp = weather[0][0][0];
    int hottestCityIndex = 0;
    for (size_t i = 0; i <= 3; i++){
        for(size_t j = 0; j <= 6; j++){
            if(weather[i][j][0] > hottestTemp){
                hottestTemp = weather[i][j][0];
                hottestCityIndex = i;
            }

        }
    }
    return hottestCityIndex;
}