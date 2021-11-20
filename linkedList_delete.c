#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure Declaration (Template)
struct Hostel{

    //Data Field
    int roomNum;
    char studentName[50];

    //Pointer (Link) Field
    struct Hostel *ptrNext;};

//Function Declaration (Prototype)
void read_studentNew();
void display_studentAll();
void delete_studentBegin();
void delete_studentEnd();
void delete_studentMiddle();

struct Hostel *ptrHead, *ptrNew, *ptrCurrent, *ptrPrevious;

int main(void){

    char userChoice[5];
    int userExit=1;

    ptrHead=NULL;

    while(userExit==1){

        printf("e - Enter new student");
        printf("\nl - List all students");
        printf("\ndb - Delete a student record at the beginning of list");
        printf("\nde - Delete a student record at the end of list");
        printf("\ndm - Delete a student record at the middle of list");
        printf("\nx - Exit");

        printf("\n\nEnter choice: ");
        scanf(" %s", &userChoice);

        if(strcasecmp(userChoice, "E") == 0){
            //Function Calling: read_studentNew
            read_studentNew();}

        else if(strcasecmp(userChoice, "L") == 0){
            //Function Calling: display_studentAll
            display_studentAll();}

        else if(strcasecmp(userChoice, "DB") == 0){
            //Function Calling: delete_studentBegin
            delete_studentBegin();}

        else if(strcasecmp(userChoice, "DE") == 0){
            //Function Calling: delete_studentEnd
            delete_studentEnd();}

        else if(strcasecmp(userChoice, "DM") == 0){
            //Function Calling: delete_studentMiddle
            delete_studentMiddle();}

        else{
            userExit=0;}}

return 0;
}

//Function Definition: read_studentNew
void read_studentNew(){

    ptrNew=(struct Hostel *)malloc(sizeof(struct Hostel));

    printf("\nEnter room number   : ");
    scanf(" %d", &ptrNew->roomNum);

    printf("Enter student name  : ");
    scanf(" %[^\n]s", &ptrNew->studentName);

    printf("\n");

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

//Function Definition: display_studentAll
void display_studentAll(){

    system("cls");

    if(ptrHead==NULL){
        printf("No UMP hostel room occupied.\n");}

    else{
        printf("Room Number\t Student Name\n");
        ptrCurrent=ptrHead;

        do{
            printf("%d\t\t %s", ptrCurrent->roomNum, ptrCurrent->studentName);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    printf("\n");
}

//Function Definition: delete_studentBegin
void delete_studentBegin(){

    system("cls");

    if(ptrHead==NULL){
        printf("The list is empty. Nothing to be deleted!\n\n");}

    else{
        ptrCurrent=ptrHead;
        ptrHead=ptrHead->ptrNext;
        free(ptrCurrent);}
}

//Function Definition: delete_studentEnd
void delete_studentEnd(){

    system("cls");

    if(ptrHead==NULL){
        printf("The list is empty. Nothing to be deleted!\n\n");}

    else{
        ptrCurrent=ptrHead;

        while(ptrCurrent->ptrNext!=NULL){
            ptrPrevious=ptrCurrent;
            ptrCurrent=ptrCurrent->ptrNext;}

        if(ptrCurrent==ptrHead){
            ptrHead=NULL;
            free(ptrCurrent);}

        else{
            ptrPrevious->ptrNext=NULL;
            free(ptrCurrent);}}
}

//Function Definition: delete_studentMiddle
void delete_studentMiddle(){

    int listLocation;

    system("cls");

    if(ptrHead==NULL){
        printf("The list is empty. Nothing to be deleted!\n\n");}

    else{
        display_studentAll();
        printf("Enter room number to be deleted: ");
        scanf(" %d", &listLocation);

        ptrCurrent=ptrHead;

        while(ptrCurrent->ptrNext!=NULL){

            if(ptrCurrent->roomNum==listLocation){
                break;}

            else{
                ptrPrevious=ptrCurrent;
                ptrCurrent=ptrCurrent->ptrNext;}}

        if(ptrCurrent->roomNum==listLocation){

            if(ptrCurrent==ptrHead){
                ptrHead=ptrCurrent->ptrNext;
                free(ptrCurrent);}

            else{
                ptrPrevious->ptrNext=ptrCurrent->ptrNext;
                free(ptrCurrent);}}

        else{
            printf("Record to be deleted is not in the list!\n\n");}}
}
