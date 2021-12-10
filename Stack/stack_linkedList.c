#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Structure Declaration (Template)
struct Element{

    //Data Field
    int number;

    //Pointer (Link) Field
    struct Element *ptrNext;};

//Function Declaration (Prototype)
void push();
void pop();
void display();

struct Element *ptrHead, *ptrNew, *ptrCurrent;

int main(void){

    char userChoice;

    ptrHead=NULL;

    do{
        printf("-------------------Stack Menu-------------------");
        printf("\nEnter E to insert an element into the stack");
        printf("\nEnter D to delete an element from the stack");
        printf("\nEnter L to check status of the stack");
        printf("\nEnter X to exit");

        printf("\n\nEnter choice: ");
        scanf(" %c", &userChoice);

        userChoice=toupper(userChoice);

        switch(userChoice){
            case 'E': push();
                      break;
            case 'D': pop();
                      break;
            case 'L': display();
                      break;

            default:  system("cls");
                      printf("Invalid entry. Please choose E/D/L/X only.\n\n");}

    }while(userChoice!='X');

return 0;
}

//Function Definition: push
void push(){

    ptrNew=(struct Element *)malloc(sizeof(struct Element));

    printf("\nPlease enter the number to push stack: ");
    scanf(" %d", &ptrNew->number);

    printf("\n");

    if(ptrHead==NULL){
        ptrHead=ptrNew;
        ptrNew->ptrNext=NULL;}

    else{
        ptrNew->ptrNext=ptrHead;
        ptrHead=ptrNew;}
}

//Function Definition: pop
void pop(){

    system("cls");

    if(ptrHead==NULL){
        printf("Stack UNDERFLOW! No element to be deleted!\n\n");}

    else{
        printf("Element popped is %d\n\n", ptrHead->number);
        ptrCurrent=ptrHead;
        ptrHead=ptrHead->ptrNext;
        free(ptrCurrent);}
}

//Function Definition: display
void display(){

    system("cls");

    printf("The status of the stack is\n");

    if(ptrHead==NULL){
        printf("0\n");}

    else{
        ptrCurrent=ptrHead;

        do{
            printf("%d", ptrCurrent->number);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

    printf("\n");
}
