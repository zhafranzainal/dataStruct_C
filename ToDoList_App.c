#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//Structure Declaration (Template)
/*struct User{



};*/

struct Date{
    int day;
    int month;
    int year;};

struct Task{

    //Data Field
    int num;
    char name[100];

    struct Subtask{
        char name[100];
        char details[100];
        char time[5];
        struct Date date;}subtask;

    //Pointer (Link) Field
    struct Task *ptrNext;};

struct Task *front, *rear, *ptrNew, *ptrCurrent;

//Function Declaration (Prototype)
void enqueue_taskDefault();
void enqueue_task();
void dequeue_task();
void display_task();
void display_subtaskMenu();
void create_subtask();
void delete_subtask();
void display_subtask();
void adjust_num();

int main(void){

    char userChoice;
    int userExit=TRUE;

    front=NULL;

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Project Phase 3 OOP");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Final SRS SRW");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Recommendation Report UHL");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Project DSA");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Homework Stats");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam DSA");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam OOP");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam HCI");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam Stats");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Git");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Web Engineering");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Turkish");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Web Frameworks");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Mobile Development");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Read Finance Articles");
    enqueue_taskDefault();

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n} : } : } : } : WELCOME TO the TO-DO-LIST APPLICATION : { : { : { : {");
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\t\t\t\t\t\t    @Section5_Group9\n");

	system("pause");

    while(userExit==TRUE){

        printf("\n[----------TO-DO-APP Menu----------]");
        printf("\nA - Create new task (enqueue)");
        printf("\nB - Delete task (dequeue)");
        printf("\nD - Display tasks list");
        printf("\nS - Display subtask menu");
        printf("\nX - Exit\n");

        printf("\nEnter choice: ");
        scanf(" %c", &userChoice);

        userChoice=toupper(userChoice);

        switch(userChoice){
        case 'A': enqueue_task();
                  break;
        case 'B': dequeue_task();
                  break;
        case 'D': display_task();
                  break;
        case 'S': display_subtaskMenu();
                  break;
        case 'X': userExit=FALSE;
                  break;

        default: system("cls");
                 printf("Choose only one of the options!\n");}}

    getch();

return 0;
}

//Function Definition: enqueue_taskDefault
void enqueue_taskDefault(){

    ptrNew->ptrNext=NULL;

    if(front==NULL){
        front=ptrNew;
        rear=ptrNew;
        ptrNew->num=1;}

    else{
        rear->ptrNext=ptrNew;
        rear=ptrNew;}

    adjust_num();

}

//Function Definition: enqueue_task
void enqueue_task(){

    ptrNew=(struct Task *)malloc(sizeof(struct Task));

    printf("\nEnter task name:\n");
    scanf(" %[^\n]s", &ptrNew->name);
    ptrNew->ptrNext=NULL;

    if(front==NULL){
        front=ptrNew;
        rear=ptrNew;
        ptrNew->num=1;}

    else{
        rear->ptrNext=ptrNew;
        rear=ptrNew;}

    adjust_num();
    display_task();
}

//Function Definition: dequeue_task
void dequeue_task(){

    system("cls");

    ptrCurrent=front;

    if(front==NULL){
        printf("Nothing to be deleted!\n\n");
        return;}

    else{
        front=front->ptrNext;
        free(ptrCurrent);
        adjust_num();}

    display_task();
}

//Function Definition: display_task
void display_task(){

    system("cls");

    printf("TO-DO-LIST\n");

    if(front==NULL){
        printf("Empty task list for today.\n");}

    else{
        ptrCurrent=front;

        do{
            printf("%d. %s", ptrCurrent->num, ptrCurrent->name);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

//Function Definition: display_subtask
void display_subtaskMenu(){

    int userChoice, userExit=TRUE;

    system("cls");

    printf("TO-DO-LIST\n");

    if(front==NULL){
        printf("Empty task list for today.\n");}

    else{
        ptrCurrent=front;

        do{
            printf("%d. %s", ptrCurrent->num, ptrCurrent->name);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);


        while(userExit==TRUE){

            printf("\n[-----------Subtask Menu-----------]");
            printf("\n1 - Create new To-Do-List");
            printf("\n2 - Delete To-Do-List");
            printf("\n3 - Display To-Do-List");
            printf("\n4 - Return to main menu\n");

            printf("\nEnter choice: ");
            scanf(" %d", &userChoice);

            switch(userChoice){
            case 1: create_subtask();
                    break;
            case 2: delete_subtask();
                    break;
            case 3: display_subtask();
                    break;
            case 4: return;

            default: system("cls");
                     printf("Choose only one of the options!\n");}}

    }

}

//Function Definition: create_subtask
void create_subtask(){



}

//Function Definition: delete_subtask
void delete_subtask(){



}

//Function Definition: display_subtask
void display_subtask(){



}

//Function Definition: adjust_num
void adjust_num(){

	int loop=1;

	ptrNew=front;

	while(ptrNew!=NULL){
        ptrNew->num=loop;
		loop++;
		ptrNew=ptrNew->ptrNext;}

}
