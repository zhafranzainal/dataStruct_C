#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Function Declaration (Prototype)
void display_carpark(int maxCar, int plateNo[maxCar], int parkNo[maxCar]);
void search_plateNo(int maxCar, int plateNo[maxCar], int parkNo[maxCar]);
void searchLinear_carpark(int parkNo);

int main(void){

    int loop, maxCar;
    char userChoice;

    printf("Enter number of cars\n");
    scanf(" %d", &maxCar);

    int plateNo[maxCar], parkNo[maxCar];

    printf("\nEnter the plate number followed by bay number one by one\n");

    for(loop=0;loop<maxCar;loop++){
        printf("\nEnter plate number for car no %d    : ", loop+1);
        scanf("%d", &plateNo[loop]);

        printf("Enter bay number for car no %d      : ", loop+1);
        scanf("%d", &parkNo[loop]);}

    do{
        printf("\nD - List all parked cars");
        printf("\nS - Search a car plate number");
        printf("\nx - Exit");

        printf("\n\nEnter choice: ");
        scanf(" %c", &userChoice);

        userChoice=toupper(userChoice);

        switch(userChoice){

		case 'D': display_carpark(maxCar, plateNo, parkNo);
				  break;

		case 'S': search_plateNo(maxCar, plateNo, parkNo);
				  break;

		case 'X': break;

		default: system("cls");
                 printf("Choose only one of the options!\n");}

    }while(userChoice!='X');

return 0;
}

//Function Definition: display_carpark
void display_carpark(int maxCar, int plateNo[maxCar], int parkNo[maxCar]){

    int loop;

    system("cls");

    printf("\nList of car plate numbers:\n");

    for(loop=0;loop<maxCar;loop++){
        printf("\nCar plate number %d     : %d\n", loop+1, plateNo[loop]);
        printf("Parking bay number %d   : %d\n", loop+1, parkNo[loop]);}

}

//Function Definition: search_plateNo
void search_plateNo(int maxCar, int plateNo[maxCar], int parkNo[maxCar]){

    int loop, searchValue;

    system("cls");
    display_carpark(maxCar, plateNo, parkNo);

    printf("\nEnter plate number to be searched\n");
    scanf(" %d", &searchValue);

    for(loop=0;loop<maxCar;loop++){
        if(plateNo[loop]==searchValue){
            printf("\n%d is located in bay number %d.\n", searchValue, parkNo[loop]);
            printf("\nPlate no          : %d", plateNo[loop]);
            printf("\nParking bay no    : %d", parkNo[loop]);
            searchLinear_carpark(parkNo[loop]);}
    }

    if((loop-1)==maxCar){
        printf("Could not find car with the plate number %d\n", searchValue);}

}

//Function Definition: searchLinear_carpark
void searchLinear_carpark(int parkNo){

    char zone[10];
    int level;

    if(parkNo<=400){
        level=1;
        if(parkNo<=200){
            strcpy(zone, "Blue");}
        else{
            strcpy(zone, "Green");}
    }

    else if(parkNo<=800){
        level=2;
        if(parkNo<=600){
            strcpy(zone, "Blue");}
        else{
            strcpy(zone, "Green");}
    }

    else if(parkNo<=1200){
        level=3;
        if(parkNo<=1000){
            strcpy(zone, "Blue");}
        else{
            strcpy(zone, "Green"); }
    }

    else{
        level=4;
        if(parkNo<=1400){
            strcpy(zone, "Blue");}
        else{
            strcpy(zone, "Green");}
    }

    printf("\nZone              : %s", zone);
    printf("\nLevel             : %d", level);

    printf("\n");

}
