#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure Declaration (Template)
struct Room{

    //Data Field
    int number;
    char event[30];

    //Pointer (Link) Field
    struct Room *ptrNext;};

//Function Declaration (Prototype)
void read_eventNew();
void display_eventAll();

struct Room *ptrHead, *ptrNew, *ptrCurrent;

int main(void){

    char userChoice[5];
    int userExit=1;

    ptrHead=NULL;

    while(userExit==1){

        printf("e - Enter new event");
        printf("\nl - List all event");
        printf("\nx - Exit");

        printf("\n\nEnter choice: ");
        scanf(" %s", &userChoice);

        if(strcasecmp(userChoice, "E") == 0){
            //Function Calling: read_eventNew
            read_eventNew();}

        else if(strcasecmp(userChoice, "L") == 0){
            //Function Calling: display_eventAll
            display_eventAll();}

        else{
            userExit=0;}}

return 0;
}

//Function Definition: read_eventNew
void read_eventNew(){

    ptrNew=(struct Room *)malloc(sizeof(struct Room));

    printf("\nEnter room number   : ");
    scanf(" %d", &ptrNew->number);

    printf("Enter event name    : ");
    scanf(" %[^\n]s", &ptrNew->event);

    printf("\n");

    if(ptrHead==NULL){
        ptrHead=ptrNew;
        ptrNew->ptrNext=NULL;}

    else{
        ptrNew->ptrNext=ptrHead;
        ptrHead=ptrNew;}
}

//Function Definition: display_eventAll
void display_eventAll(){

    system("cls");

    if(ptrHead==NULL){
        printf("No room reservation yet.\n");}

    else{
        printf("Room number\t Event\n");
        ptrCurrent=ptrHead;

        do{
            printf("%d\t\t %s", ptrCurrent->number, ptrCurrent->event);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    printf("\n");
}
