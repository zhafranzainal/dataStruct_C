#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

//Structure Declaration (Template)
struct Carpark{

    //Data Field
    int plateNo;
    int parkNo;
    int level;
    char zone[10];

    //Pointer (Link) Field
    struct Carpark *ptrNext;};

//Function Declaration (Prototype)
void insert_carInfo();
void swap_task(struct Carpark *data1, struct Carpark *data2);
void sort_parkNo();
void display_carpark();
void search_plateNo();

struct Carpark *ptrHead, *ptrNew, *ptrCurrent, *ptrPrevious;

int main(void){

    char userChoice;

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=2340;
    ptrNew->parkNo=1402;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=112;
    ptrNew->parkNo=300;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=4345;
    ptrNew->parkNo=1255;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=432;
    ptrNew->parkNo=987;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=500;
    ptrNew->parkNo=230;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=888;
    ptrNew->parkNo=350;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=1007;
    ptrNew->parkNo=481;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=2554;
    ptrNew->parkNo=700;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=7334;
    ptrNew->parkNo=800;
    insert_carInfo();

    ptrNew=(struct Carpark*)malloc(sizeof(struct Carpark));
    ptrNew->plateNo=777;
    ptrNew->parkNo=540;
    insert_carInfo();

    sort_parkNo();

    do{
        printf("D - List all parked cars");
        printf("\nS - Search a car plate number");
        printf("\nx - Exit");

        printf("\n\nEnter choice: ");
        scanf(" %c", &userChoice);

        userChoice=toupper(userChoice);

        switch(userChoice){

		case 'D': display_carpark();
				  break;

		case 'S': search_plateNo();
				  break;

		case 'X': break;

		default: system("cls");
                 printf("Choose only one of the options!\n");}

    }while(userChoice!='X');

return 0;
}

//Function Definition: insert_carInfo
void insert_carInfo(){

    if(ptrHead==NULL){
        ptrHead=ptrNew;
        ptrNew->ptrNext=NULL;}

    else{
        ptrCurrent=ptrHead;

        while(ptrCurrent->ptrNext!=NULL){
            ptrCurrent=ptrCurrent->ptrNext;}

        ptrCurrent->ptrNext=ptrNew;
        ptrNew->ptrNext=NULL;}

}

//Function Definition: swap_task
void swap_task(struct Carpark *data1, struct Carpark *data2){

    int tempPlateNo, tempParkNo, tempLevel;
    char tempZone[10];

    tempPlateNo=data2->plateNo;
    data2->plateNo=data1->plateNo;
    data1->plateNo=tempPlateNo;

    tempParkNo=data2->parkNo;
    data2->parkNo=data1->parkNo;
    data1->parkNo=tempParkNo;

    tempLevel=data2->level;
    data2->level=data1->level;
    data1->level=tempLevel;

    strcpy(tempZone, data2->zone);
    strcpy(data2->zone, data1->zone);
    strcpy(data1->zone, tempZone);

}

//Function Definition: sort_parkNo
void sort_parkNo(){

    int swapped;
    struct Carpark *ptrFirst;
    struct Carpark *ptrSecond=NULL;

    if(ptrHead==NULL){
        system("cls");
        printf("Empty carpark. Nothing to be sorted!\n\n\n");
        return;}

    do{
        swapped=FALSE;
        ptrFirst=ptrHead;

        while(ptrFirst->ptrNext!=ptrSecond){

            if(ptrFirst->parkNo > ptrFirst->ptrNext->parkNo){
                swap_task(ptrFirst, ptrFirst->ptrNext);
                swapped = TRUE;}

            ptrFirst=ptrFirst->ptrNext;}

        ptrSecond=ptrFirst;

    }while(swapped==TRUE);

}

//Function Definition: display_carpark
void display_carpark(){

    system("cls");

    if(ptrHead==NULL){
        printf("Empty carpark.\n");}

    else{
        ptrCurrent=ptrHead;

        printf("Car Plate No\t Level\t Parking No\t Zone\n");
        printf("=============================================\n");

        do{

            if(ptrCurrent->parkNo<=200){
                ptrCurrent->level=1;
                strcpy(ptrCurrent->zone, "Blue");}

            else if(ptrCurrent->parkNo<=400){
                ptrCurrent->level=1;
                strcpy(ptrCurrent->zone, "Green");}

            else if(ptrCurrent->parkNo<=600){
                ptrCurrent->level=2;
                strcpy(ptrCurrent->zone, "Blue");}

            else if(ptrCurrent->parkNo<=800){
                ptrCurrent->level=2;
                strcpy(ptrCurrent->zone, "Green");}

            else if(ptrCurrent->parkNo<=1000){
                ptrCurrent->level=3;
                strcpy(ptrCurrent->zone, "Blue");}

            else if(ptrCurrent->parkNo<=1200){
                ptrCurrent->level=3;
                strcpy(ptrCurrent->zone, "Green");}

            else if(ptrCurrent->parkNo<=1400){
                ptrCurrent->level=4;
                strcpy(ptrCurrent->zone, "Blue");}

            else{
                ptrCurrent->level=4;
                strcpy(ptrCurrent->zone, "Green");}

            printf("%-18d %-9d %-10d %s", ptrCurrent->plateNo, ptrCurrent->level, ptrCurrent->parkNo, ptrCurrent->zone);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    printf("\n");

}

//Function Definition: search_plateNo
void search_plateNo(){

    int searchValue;

    system("cls");

    if(ptrHead==NULL){
        printf("The list is empty. Nothing to be searched!\n\n");}

    else{

        display_carpark();

        printf("Enter key value for linear sequential search: ");
        scanf(" %d", &searchValue);

        ptrCurrent=ptrHead;

        while(ptrCurrent->ptrNext!=NULL){

            if(ptrCurrent->plateNo==searchValue){
                printf("\nPlate no          : %d", ptrCurrent->plateNo);
                printf("\nLevel             : %d", ptrCurrent->level);
                printf("\nParking bay no    : %d", ptrCurrent->parkNo);
                printf("\nZone              : %s\n\n", ptrCurrent->zone);
                return;}
            else{
                ptrCurrent=ptrCurrent->ptrNext;}}

        if(ptrCurrent->plateNo==searchValue){
            printf("\nPlate no          : %d", ptrCurrent->plateNo);
            printf("\nLevel             : %d", ptrCurrent->level);
            printf("\nParking bay no    : %d", ptrCurrent->parkNo);
            printf("\nZone              : %s\n\n", ptrCurrent->zone);}
        else{
            printf("\nSorry, no match found!\n\n");}
    }
}
