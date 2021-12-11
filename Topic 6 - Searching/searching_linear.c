#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//Structure Declaration (Template)
struct Node{

    //Data Field
    int element;

    //Pointer (Link) Field
    struct Node *ptrNext;};

//Function Declaration (Prototype)
void read_number();
void display_number();
void search_number();

struct Node *ptrHead, *ptrNew, *ptrCurrent, *ptrPrevious;

int main(void){

    char userChoice;

    ptrNew=(struct Node*)malloc(sizeof(struct Node));
    ptrNew->element=22;
    read_number();

    ptrNew=(struct Node*)malloc(sizeof(struct Node));
    ptrNew->element=56;
    read_number();

    ptrNew=(struct Node*)malloc(sizeof(struct Node));
    ptrNew->element=2;
    read_number();

    ptrNew=(struct Node*)malloc(sizeof(struct Node));
    ptrNew->element=45;
    read_number();

    ptrNew=(struct Node*)malloc(sizeof(struct Node));
    ptrNew->element=23;
    read_number();

	do{
        printf("l - List all numbers");
        printf("\nd - Search a number");
        printf("\nx - Exit");

        printf("\n\nEnter choice: ");
        scanf(" %c", &userChoice);

        userChoice=toupper(userChoice);

        switch(userChoice){

		case 'L': display_number();
				  break;

		case 'D': search_number();
				  break;

		case 'X': break;

		default: system("cls");
                 printf("Choose only one of the options!\n");}

    }while(userChoice!='X');

return 0;
}

//Function Definition: read_number
void read_number(){

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

//Function Definition: display_number
void display_number(){

    system("cls");

    if(ptrHead==NULL){
        printf("Nothing in the list.\n");}

    else{
        ptrCurrent=ptrHead;

        do{
            printf("%d", ptrCurrent->element);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    printf("\n");

}

//Function Definition: search_number
void search_number(){

    int searchValue;

    system("cls");

    if(ptrHead==NULL){
        printf("The list is empty. Nothing to be searched!\n\n");}

    else{

        display_number();

        printf("Enter key value for linear sequential search: ");
        scanf(" %d", &searchValue);

        ptrCurrent=ptrHead;

        while(ptrCurrent->ptrNext!=NULL){

            if(ptrCurrent->element==searchValue){
                printf("\nKey match %d found!\n\n", ptrCurrent->element);
                return;}
            else{
                ptrCurrent=ptrCurrent->ptrNext;}}

        if(ptrCurrent->element==searchValue){
            printf("\nKey match %d found!\n\n", ptrCurrent->element);}
        else{
            printf("\nSorry, no match found!\n\n");}
    }
}
