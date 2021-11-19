#include <stdio.h>

#define TOTAL_EMPLOYEE 3

//Structure Declaration (Template)
struct Project{

    char code[10];
    char title[20];
    float budget;
    char manager[50];

    struct Employee{
        char number[10];
        char name[50];
        float rateHourly;}employee[TOTAL_EMPLOYEE];
};

//Function Declaration (Prototype)
void display(struct Project pro);

int main(void){

    struct Project pro;

    int loop;
    float rateHourlyAverage;

    printf("PROJECT MANAGEMENT REPORT.\n");
    printf("==========================\n");

    //Key-in Project Information
    printf("Enter Project Code    : ");
    scanf(" %s", &pro.code);

    printf("Enter Project Title   : ");
    scanf(" %s", &pro.title);

    printf("Enter Project Budget  : ");
    scanf(" %f", &pro.budget);

    printf("Enter Project Manager : ");
    scanf(" %s", &pro.manager);

    printf("\n--------------------------\n");
    printf("Employees involved in the project.\n");

    //Key-in Employee Information using array-based
    for(loop=0; loop<TOTAL_EMPLOYEE; loop++){

        printf("\nEmployee #%d", loop+1);

        printf("\nEnter Employee Number       : ");
        scanf(" %s", &pro.employee[loop].number);

        printf("Enter Employee Name         : ");
        scanf(" %s", &pro.employee[loop].name);

        printf("Enter Employee Rate (Hour)  : ");
        scanf(" %f", &pro.employee[loop].rateHourly);}

    display(pro);

return 0;}

//Function Definition: display
void display(struct Project pro){

    system("cls");

    int loop;
    float total_Hrate=0;
    float avg_Hrate=0;

    for(loop=0; loop<TOTAL_EMPLOYEE; loop++){
        total_Hrate+=pro.employee[loop].rateHourly;}

    avg_Hrate=total_Hrate/TOTAL_EMPLOYEE;

    printf("PROJECT MANAGEMENT REPORT.\n");
    printf("==========================\n");

    printf("\nProject Code    : %s", pro.code);
    printf("\nProject Title   : %s", pro.title);
    printf("\nProject Budget  : %.0f", pro.budget);
    printf("\nProject Manager : %s", pro.manager);

    printf("\n\nEmployee No.\t Employee Name\t Hourly Rate");
    printf("\n============================================");

    for(loop=0; loop<TOTAL_EMPLOYEE; loop++){
        printf("\n%s\t\t %s\t\t %.2f", pro.employee[loop].number, pro.employee[loop].name, pro.employee[loop].rateHourly);}

    printf("\n============================================");
    printf("\nAverage Hourly Rate: %.2f", avg_Hrate);

    printf("\n");
}


