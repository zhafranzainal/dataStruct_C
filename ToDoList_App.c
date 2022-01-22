#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//Structure Declaration (Template)
struct User{

    char username[20];
    char password[20];

};

struct Date{
    int day;
    int month;
    int year;};

struct Task{

    //Data Field
    int num;
    char name[100];

    struct Details{
        char category[100];
        char time[5];
        struct Date date;}details;

    //Pointer (Link) Field
    struct Task *ptrNext;};

struct Task *front, *rear, *ptrNew, *ptrCurrent;

//Function Declaration (Prototype)
struct User display_login();
struct User get_userDetails();
void process_userAuthentication(struct User user);
void enqueue_taskDefault();
void enqueue_task();
void dequeue_task();
void adjust_num();
void display_task();
void searchLinear_task();
void swap_task(struct Task *data1, struct Task *data2);
void sort_taskByDate();

int main(void){

    //Structure Variable
    struct User user;

    char userChoice;
    int userExit=TRUE;

    front=NULL;

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Project Phase 3 OOP");
    strcpy(ptrNew->details.category, "Assignment");
    ptrNew->details.date.day=26;
    ptrNew->details.date.month=01;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1159");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Final SRS SRW");
    strcpy(ptrNew->details.category, "Assignment");
    ptrNew->details.date.day=26;
    ptrNew->details.date.month=01;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1159");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Recommendation Report UHL");
    strcpy(ptrNew->details.category, "Assignment");
    ptrNew->details.date.day=28;
    ptrNew->details.date.month=01;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1159");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Project DSA");
    strcpy(ptrNew->details.category, "Assignment");
    ptrNew->details.date.day=31;
    ptrNew->details.date.month=01;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1159");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Submit Homework Stats");
    strcpy(ptrNew->details.category, "Assignment");
    ptrNew->details.date.day=24;
    ptrNew->details.date.month=01;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "0800");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam DSA");
    strcpy(ptrNew->details.category, "Test");
    ptrNew->details.date.day=11;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1445");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam OOP");
    strcpy(ptrNew->details.category, "Test");
    ptrNew->details.date.day=9;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1400");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam HCI");
    strcpy(ptrNew->details.category, "Test");
    ptrNew->details.date.day=9;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "0900");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Prepare Exam Stats");
    strcpy(ptrNew->details.category, "Test");
    ptrNew->details.date.day=07;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "0900");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Git");
    strcpy(ptrNew->details.category, "Hobby");
    ptrNew->details.date.day=14;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "0900");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Web Engineering");
    strcpy(ptrNew->details.category, "Hobby");
    ptrNew->details.date.day=15;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1000");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Turkish");
    strcpy(ptrNew->details.category, "Hobby");
    ptrNew->details.date.day=16;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "2030");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Web Frameworks");
    strcpy(ptrNew->details.category, "Hobby");
    ptrNew->details.date.day=16;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "0830");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Practice Mobile Development");
    strcpy(ptrNew->details.category, "Hobby");
    ptrNew->details.date.day=15;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "0930");
    enqueue_taskDefault();

    ptrNew=(struct Task *)malloc(sizeof(struct Task));
    strcpy(ptrNew->name, "Read Finance Articles");
    strcpy(ptrNew->details.category, "Hobby");
    ptrNew->details.date.day=10;
    ptrNew->details.date.month=02;
    ptrNew->details.date.year=2022;
    strcpy(ptrNew->details.time, "1745");
    enqueue_taskDefault();

    //Function Calling: display_login
    user=display_login();

    //Function Calling: process_userAuthentication
    process_userAuthentication(user);

    while(userExit==TRUE){

        printf("\n[----------TO-DO-APP Menu----------]");
        printf("\nA - Create new task (enqueue)");
        printf("\nB - Delete task (dequeue)");
        printf("\nD - Display tasks list");
        printf("\nS - Search task");
        printf("\nT - Sort task by date");
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
        case 'S': searchLinear_task();
                  break;
        case 'T': sort_taskByDate();
                  break;
        case 'X': userExit=FALSE;
                  break;

        default: system("cls");
                 printf("Choose only one of the options!\n");}}

return 0;
}

//Function Definition: display_login
struct User display_login(){

    struct User user;

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n} : } : } : } : WELCOME TO the TO-DO-LIST APPLICATION : { : { : { : {");
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\t\t\t\t\t\t    @Section5_Group9\n");

    //Function Calling: get_userDetails
    user=get_userDetails();

    return user;
}

//Function Definition: get_userDetails
struct User get_userDetails(){

    struct User user;

    printf("\t\t Username: ");
    scanf(" %s", &user.username);

    printf("\t\t Password: ");
    scanf(" %s", &user.password);

    return user;

}

//Function Definition: process_userAuthentication
void process_userAuthentication(struct User user){

    if(strcmp(user.password, "123")==0){
         system("cls");}
    else{
        printf("\n\tTHE PASSWORD IS INCORRECT! PLEASE TRY AGAIN (Pass: 123)\n\n\n");
        system("pause");
        system("cls");
        display_login();}

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

    printf("\n");

    printf("Enter task category  : ");
    scanf(" %[^\n]s", &ptrNew->details.category);

    printf("Enter date (dd/mm/yyyy) : ");
    scanf(" %d/%d/%d", &ptrNew->details.date.day, &ptrNew->details.date.month, &ptrNew->details.date.year);

    printf("Enter time (24-hour)    : ");
    scanf(" %s", &ptrNew->details.time);

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
        printf("Nothing to be deleted!\n\n\n");
        return;}

    else{
        front=front->ptrNext;
        free(ptrCurrent);
        adjust_num();}

    display_task();
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

//Function Definition: display_task
void display_task(){

    system("cls");

    printf("\t\t\t\tTO-DO-LIST\n");
    printf("===============================================================================");

    if(front==NULL){
        printf("\nEmpty task list for today.\n");}

    else{
        ptrCurrent=front;

        printf("\n\n\tTask Name\t\t\t  Category\t   Date\t\t  Time");
        printf("\n-------------------------------------\t ----------\t ----------\t ------\n");

        do{
            printf("%2d. %-36s %-15s %2d/%d/%d %11s", ptrCurrent->num, ptrCurrent->name, ptrCurrent->details.category, ptrCurrent->details.date.day, ptrCurrent->details.date.month, ptrCurrent->details.date.year, ptrCurrent->details.time);

            printf("\n");

            ptrCurrent=ptrCurrent->ptrNext;

        }while(ptrCurrent!=NULL);}

}

//Function Definition: searchLinear_task
void searchLinear_task(){

    int searchValue;

    system("cls");

    if(front==NULL){
        printf("The task list is empty. Nothing to be searched!\n\n\n");}

    else{

        display_task();

        printf("\nEnter task number: ");
        scanf(" %d", &searchValue);

        ptrCurrent=front;

        while(ptrCurrent->ptrNext!=NULL){

            if(ptrCurrent->num==searchValue){
                printf("\nTask %d found!\n", ptrCurrent->num);
                return;}
            else{
                ptrCurrent=ptrCurrent->ptrNext;}}

        if(ptrCurrent->num==searchValue){
            printf("\nTask %d found!\n", ptrCurrent->num);}
        else{
            printf("\nSorry, no match found!\n");}
    }
}

//Function Definition: swap_task
void swap_task(struct Task *data1, struct Task *data2){

    int temp;
    char tempTaskName[100], tempCategory[100], tempTime[5];

    temp=data2->details.date.year;
    data2->details.date.year=data1->details.date.year;
    data1->details.date.year=temp;

    temp=data2->details.date.month;
    data2->details.date.month=data1->details.date.month;
    data1->details.date.month=temp;

    temp=data2->details.date.day;
    data2->details.date.day=data1->details.date.day;
    data1->details.date.day=temp;

    strcpy(tempTaskName, data2->name);
    strcpy(data2->name, data1->name);
    strcpy(data1->name, tempTaskName);

    strcpy(tempCategory, data2->details.category);
    strcpy(data2->details.category, data1->details.category);
    strcpy(data1->details.category, tempCategory);

    strcpy(tempTime, data2->details.time);
    strcpy(data2->details.time, data1->details.time);
    strcpy(data1->details.time, tempTime);

}

//Function Definition: sort_taskByDate
void sort_taskByDate(){

    int swapped;
    struct Task *ptrFirst;
    struct Task *ptrSecond=NULL;

    if(front==NULL){
        system("cls");
        printf("Empty task list for today. Nothing to be sorted!\n\n\n");
        return;}

    do{
        swapped=FALSE;
        ptrFirst=front;

        while(ptrFirst->ptrNext!=ptrSecond){

            if(ptrFirst->details.date.year > ptrFirst->ptrNext->details.date.year){
                swap_task(ptrFirst, ptrFirst->ptrNext);
                swapped = TRUE;}

            else{

                if(ptrFirst->details.date.year == ptrFirst->ptrNext->details.date.year){

                    if(ptrFirst->details.date.month > ptrFirst->ptrNext->details.date.month){
                        swap_task(ptrFirst, ptrFirst->ptrNext);
                        swapped = TRUE;}

                    else{

                        if(ptrFirst->details.date.month == ptrFirst->ptrNext->details.date.month){

                            if(ptrFirst->details.date.day > ptrFirst->ptrNext->details.date.day){
                                swap_task(ptrFirst, ptrFirst->ptrNext);
                                swapped = TRUE;}
                        }
                    }
                }
            }

            ptrFirst=ptrFirst->ptrNext;}

        ptrSecond=ptrFirst;

    }while(swapped==TRUE);

    display_task();

}
