#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void determine_membership();
void display_custInfo();

struct Customer *ptrHead, *ptrNew, *ptrCurrent;

int main(void){

    printf("\t\tWELCOME TO KEDAI KUCINGKU");
    printf("\n\t\t*************************\n\n");

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

    determine_membership();
    display_custInfo();

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

//Function Definition: determine_membership
void determine_membership(){

    if(ptrHead!=NULL){

        ptrCurrent=ptrHead;

        do{
            if(ptrCurrent->point<=1000){
                strcpy(ptrCurrent->membership, "Silver");}

            else{
                strcpy(ptrCurrent->membership, "VIP");}

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

//Function Definition: display_custInfo
void display_custInfo(){

    if(ptrHead==NULL){
        printf("No customer yet.\n");}

    else{
        printf("Name\t\t\t ID\t Accumulated Points\n");
        printf("===================================================\n");
        ptrCurrent=ptrHead;

        do{
            printf("%-24s %-13s %d", ptrCurrent->name, ptrCurrent->numID, ptrCurrent->point);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    printf("\n");
}

