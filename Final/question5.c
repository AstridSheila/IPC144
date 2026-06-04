//Astrid Bailey
//IPC144N1F
//April 16, 2026

#include <stdio.h>
#include <string.h>

    struct Vehicle{
        char vin[20];
        char make[20];
        char model[20];
        int year;
        char engineSizes[3][10];
        char colour[20];
        unsigned long int vehicleID;
    } vehicle, vehicle2;



void getVehicleData(struct Vehicle *v);
void printVehicleInfo(struct Vehicle *v);
void vehicleCopy(struct Vehicle *dest, struct Vehicle *source);
int sameVehicle(struct Vehicle *v1, struct Vehicle *v2);
int sameMake(struct Vehicle *v1, struct Vehicle *v2);
unsigned int userOption(void);

int main(){

    unsigned int userChoice;
    
    while((userChoice) != 6){
        userChoice=userOption();
        switch(userChoice){
            case 1:
                getVehicleData(&vehicle);
                break;
            case 2:
                printVehicleInfo(&vehicle);
                break;
            case 3:
                vehicleCopy(&vehicle2, &vehicle);
                break;
            case 4:
                sameVehicle(&vehicle, &vehicle2);
                break;
            case 5:
                sameMake(&vehicle, &vehicle2);
                break;

        }

    }
    
    return 0;
}

void getVehicleData(struct Vehicle *v){
    char vin[20];
    char make[20];
    char model[20];
    int year;
    char engineSizes[3][10];
    char colour[20];
    unsigned long int vehicleID;

    printf("%s", "Enter the vehicle's VIN:\n");
    scanf("%s", &vin);
    strcpy(v->vin, vin);
    
    printf("%s", "Enter the vehicle make:\n");
    scanf("%s", &make);
    strcpy(v->make, make);
    
    printf("%s", "Enter the vehicle model:\n");
    scanf("%s", &model);
    strcpy(v->model, model);
    
    printf("%s", "Enter the vehicle year:\n");
    scanf("%d", &year);
    v->year = year;
    
    printf("%s", "Enter the vehicle's engine sizes:\n");
    int i = 0;
    for (i = 0; i < 3; i++) {
    scanf("%s", &v->engineSizes[i]);
    }   
    
    printf("%s", "Enter the vehicle's colour:\n");
    scanf("%s", &colour);
    strcpy(v->colour, colour);
    
    printf("%s", "Enter the vehicle's ID number:\n");
    scanf("%lu", &vehicleID);
    v->vehicleID = vehicleID;
}

void printVehicleInfo(struct Vehicle *v){
    printf("Make:   %10s\nModel:  %10s\nYear:   %10d\nEngine Sizes: %s, %s, %s\nColour: %10s\nVehicle ID: %10lu\n", v->make, v->model, v->year, v->engineSizes[0], v->engineSizes[1], v->engineSizes[2], v->colour, v->vehicleID);
}

void vehicleCopy(struct Vehicle *dest, struct Vehicle *source){
    memcpy(dest, source, sizeof(struct Vehicle));
}

int sameVehicle(struct Vehicle *v1, struct Vehicle *v2){
    if(strcmp(v1->make, v2->make) == 0 && strcmp(v1->model, v2->model) == 0 && v1->year == v2->year){
        printf("These vehicles are the same.\n");
        return 1;
    }
    printf("These vehicles are not the same.\n");
    return 0;
}

int sameMake(struct Vehicle *v1, struct Vehicle *v2){
    if(strcmp(v1->make, v2->make) == 0){
        printf("These vehicles are the same make.\n");
        return 1;
    }
    printf("These vehicles are not the same make.\n");
    return 0;
}

unsigned int userOption(void){
    unsigned int option=0;
    printf("Please enter your choice\n"
           "1. Get vehicle data\n"
           "2. Display vehicle information\n"
           "3. Copy vehicle structure\n"
           "4. Compare Vehicles\n"
           "5. Compare Car Makes\n"
           "6. Exit\n");
    scanf("%d",&option);

    return option;
}