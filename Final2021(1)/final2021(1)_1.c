#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

//Structure Declaration (Template)
struct Customer{

    //Data Field
    char name[30];
    char numID[10];
    int point;
    char membership[10];

    //Pointer (Link) Field
    struct Customer *ptrNext;};

//Function Declaration (Prototype)
void add_custInfo();
void display_custInfo();
void display_memberSilver();
void display_memberVIP();
void filter_custInfo();

struct Customer *ptrHead, *ptrNew, *ptrCurrent;

int main(void){

    char userChoice;
    int userExit=TRUE;

    ptrNew=(struct Customer *)malloc(sizeof(struct Customer));
    strcpy(ptrNew->name, "Rokiah Ahmad");
    strcpy(ptrNew->numID, "KK011");
    ptrNew->point=1360;
    add_custInfo();

    ptrNew=(struct Customer *)malloc(sizeof(struct Customer));
    strcpy(ptrNew->name, "Latifah Ismail");
    strcpy(ptrNew->numID, "KK050");
    ptrNew->point=540;
    add_custInfo();

    ptrNew=(struct Customer *)malloc(sizeof(struct Customer));
    strcpy(ptrNew->name, "Siti Rahayu Razak");
    strcpy(ptrNew->numID, "KK005");
    ptrNew->point=1770;
    add_custInfo();

    ptrNew=(struct Customer *)malloc(sizeof(struct Customer));
    strcpy(ptrNew->name, "Sue Ann Lee");
    strcpy(ptrNew->numID, "KK021");
    ptrNew->point=975;
    add_custInfo();

    ptrNew=(struct Customer *)malloc(sizeof(struct Customer));
    strcpy(ptrNew->name, "Remy Tan");
    strcpy(ptrNew->numID, "KK063");
    ptrNew->point=120;
    add_custInfo();

    start:
    printf("\t\tWELCOME TO KEDAI KUCINGKU");
    printf("\n\t\t*************************\n\n");

    display_custInfo();

    while(userExit==TRUE){

        printf("\nD - Display all customer info");
        printf("\nF - Filter based on membership types");
        printf("\nX - Exit\n");

        printf("\nEnter choice: ");
        scanf(" %c", &userChoice);

        userChoice=toupper(userChoice);

        switch(userChoice){
            case 'D':   system("cls");
                        goto start;
                        break;
            case 'F':   filter_custInfo();
                        break;
            case 'X':   userExit=FALSE;
                        break;

            default:    system("cls");
                        printf("Choose only one of the options!\n");}}

return 0;
}

//Function Definition: add_custInfo
void add_custInfo(){

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

//Function Definition: display_custInfo
void display_custInfo(){

    if(ptrHead==NULL){
        printf("No customer yet.\n");}

    else{
        printf("Name\t\t\t ID\t Accumulated Points\t Membership\n");
        printf("===================================================================\n");
        ptrCurrent=ptrHead;

        do{

            if(ptrCurrent->point<=1000){
                strcpy(ptrCurrent->membership, "Silver");}

            else{
                strcpy(ptrCurrent->membership, "VIP");}

            printf("%-24s %-13s %-17d %s", ptrCurrent->name, ptrCurrent->numID, ptrCurrent->point, ptrCurrent->membership);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

//Function Definition: display_memberSilver
void display_memberSilver(){

    system("cls");

    if(ptrHead==NULL){
        printf("No customer yet.\n");}

    else{
        printf("Name\t\t\t ID\t Accumulated Points\t Membership\n");
        printf("===================================================================\n");
        ptrCurrent=ptrHead;

        do{
            if(strcmp(ptrCurrent->membership, "Silver")==0){
                printf("%-24s %-13s %-17d %s", ptrCurrent->name, ptrCurrent->numID, ptrCurrent->point, ptrCurrent->membership);
                printf("\n");}

                ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

//Function Definition: display_memberVIP
void display_memberVIP(){

    if(ptrHead==NULL){
        printf("No customer yet.\n");}

    else{
        printf("\nName\t\t\t ID\t Accumulated Points\t Membership\n");
        printf("===================================================================\n");
        ptrCurrent=ptrHead;

        do{
            if(strcmp(ptrCurrent->membership, "VIP")==0){
                printf("%-24s %-13s %-17d %s", ptrCurrent->name, ptrCurrent->numID, ptrCurrent->point, ptrCurrent->membership);
                printf("\n");}

                ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

//Function Definition: filter_custInfo
void filter_custInfo(){

    display_memberSilver();
    display_memberVIP();

}


