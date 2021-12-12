#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_QUEUE 3

int front=0, rear=MAX_QUEUE-1, count=0, queue[MAX_QUEUE], element;

//Function Declaration (Prototype)
void enqueue();
void dequeue();
void display();

int main(void){

    char userChoice;

    do{
        printf("\nFront value   : %d", front);
        printf("\nRear value    : %d", rear);
        printf("\nCount value   : %d", count);

        printf("\n\n[-----------Queue Menu-----------]");
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

        case 'D': display();
                  break;

        case 'X': break;

        default: system("cls");
                 printf("Choose only one of the options!\n");}

    }while(userChoice!='X');

return 0;
}

//Function Definition: enqueue
void enqueue(){

    printf("\nEnter an element: ");
    scanf(" %d", &element);

    if(count==MAX_QUEUE){
        system("cls");
        printf("Queue OVERFLOW - can't insert into queue!\n");
        return;}

    else{
        rear=(rear+1)%MAX_QUEUE;
        count++;
        queue[rear]=element;}

   display();
}

//Function Definition: dequeue
void dequeue(){

    system("cls");

    if(count==0){
        printf("Queue UNDERFLOW - can't delete queue!\n");
        return;}

    else{
        front=(front+1)%MAX_QUEUE;
        count--;}

    display();
}

//Function Definition: display
void display(){

    system("cls");

    int loopFront=front, loopCount=count;

    if(count==0){
        printf("Empty queue.\n");}

    else{
        while(loopCount!=0){
            printf("%d", queue[loopFront]);
            printf("\n");
            loopFront=(loopFront+1)%MAX_QUEUE;
            loopCount--;}
    }
}
