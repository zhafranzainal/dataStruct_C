#include <stdio.h>

//Structure Declaration (Template)
struct Employee{

    int IDno;
    char name[50];
    int age;

    struct Salary{
        float basic;
        float allowance;}salary;

    struct Address{
        char city[20];
        char houseNo[20];}address;

    struct Payment_Date{
        int day;
        int month;
        int year;}date;
};

//Function Declaration (Prototype)
void display(struct Employee E1);

int main(void){

    struct Employee E1={2309, "Ahmad", 51, {1000,500}, {"Kuantan","A9"}, {11,12,2018}};

    display(E1);

return 0;}

//Function Definition: display
void display(struct Employee E1){

    if(E1.age>50){
        E1.salary.allowance+=0.05*E1.salary.basic;}

    printf("Staff ID      : %d", E1.IDno);
    printf("\nStaff Name    : %s", E1.name);
    printf("\nStaff Age     : %d", E1.age);
    printf("\nBasic Salary  : RM%.2f", E1.salary.basic);
    printf("\nAllowance     : RM%.2f", E1.salary.allowance);
    printf("\nAddress       : %s", E1.address.city);

    printf("\n");}
