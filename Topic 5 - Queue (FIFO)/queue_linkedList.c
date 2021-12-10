#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0

//Structure Declaration (Template)
struct Node{

    //Data Field
    int element;

    //Pointer (Link) Field
	struct Node *ptrNext;};

struct Node *front, *rear, *ptrNew, *ptrCurrent;

//Function Declaration (Prototype)
void enqueue();
void dequeue();
void list_node();

int main(void){

	char userChoice;
	int userExit=TRUE;

	front=NULL;

	while(userExit==TRUE){

        printf("\n[-----------Queue Menu-----------]");
		printf("\nA - Enqueue queue");
		printf("\nB - Dequeue queue");
		printf("\nD - Display queue content");
		printf("\nX - Exit\n");

		printf("\nEnter choice: ");
		scanf(" %c", &userChoice);

		userChoice=toupper(userChoice);

		switch(userChoice){
		case 'A': enqueue();
                  break;
		case 'B': dequeue();
                  break;
		case 'D': list_node();
                  break;
		case 'X': userExit=FALSE;
                  break;

		default: system("cls");
                 printf("Choose only one of the options!\n");}}

    getch();

return 0;
}

//Function Definition: enqueue
void enqueue(){

    ptrNew=(struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter an element   : ");
    scanf(" %d", &ptrNew->element);
    ptrNew->ptrNext=NULL;

    printf("\n");

    if(front==NULL){
        front=ptrNew;
        rear=ptrNew;}

    else{
        rear->ptrNext=ptrNew;
        rear=ptrNew;}

    list_node();
}

//Function Definition: dequeue
void dequeue(){

    system("cls");

    ptrCurrent=front;

    if(front==NULL){
        printf("Nothing to be deleted!\n");
        return;}

    else{
        front=front->ptrNext;
        free(ptrCurrent);}

    list_node();
}

//Function Definition: list_node
void list_node(){

    system("cls");

    if(front==NULL){
        printf("Empty queue.\n");}

    else{
        ptrCurrent=front;

        do{
            printf("%d", ptrCurrent->element);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

