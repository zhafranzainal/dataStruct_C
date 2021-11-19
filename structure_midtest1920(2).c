#include <stdio.h>

//Structure Declaration (Template)
struct Billpayment{

    int referNo;

    struct Date{
        int day;
        int month;
        int year;}date;

    struct List{
        int accNo;
        char corpName[50];
        float amount;}list;
};

//Function Declaration (Prototype)
void insert(struct Billpayment bil[]);
void update(struct Billpayment bil[]);
void display(struct Billpayment bil[]);

int main(void){

    struct Billpayment bil[3];
    insert(bil);

return 0;}

//Function Definition: insert
void insert(struct Billpayment bil[]){

    int loop;

    printf("ENTER INPUT\n");

    for(loop=0;loop<3;loop++){

        printf("Input %d\n", loop+1);

        printf("Enter Ref. No           :");
        scanf(" %d", &bil[loop].referNo);

        printf("Enter Date (DD/MM/YYYY) :");
        scanf(" %d/%d/%d", &bil[loop].date.day, &bil[loop].date.month, &bil[loop].date.year);

        printf("Enter Acc. No           :");
        scanf(" %d", &bil[loop].list.accNo);

        printf("Enter Corp. Name        :");
        scanf(" %s", &bil[loop].list.corpName);

        printf("Enter Amount            :");
        scanf(" %f", &bil[loop].list.amount);
        printf("\n");}

    display(bil);
    update(bil);
    display(bil);
}

//Function Definition: update
void update(struct Billpayment bil[]){

    int referNoUpdate, loop;
    float amountUpdate;

    printf("\n\nUPDATE DATA\n");

    printf("Enter Ref. No for updated   :");
    scanf(" %d", &referNoUpdate);

    for(loop=0;loop<3;loop++){

        if(bil[loop].referNo==referNoUpdate){

        printf("Enter Update Amount         :");
        scanf(" %f", &amountUpdate);

        bil[loop].list.amount=amountUpdate;}}

    printf("\n");
}

//Function Definition: display
void display(struct Billpayment bil[]){

    int loop;
    float amountGrand;

    printf("DISPLAY DATA\n");

    for(loop=0;loop<3;loop++){
        printf("\nPayment %d", loop+1);
        printf("\nRef. No       :%d", bil[loop].referNo);
        printf("\nDate          :%d.%d.%d", bil[loop].date.day, bil[loop].date.month, bil[loop].date.year);
        printf("\nAcc. No       :%d", bil[loop].list.accNo);
        printf("\nCorp. Name    :%s", bil[loop].list.corpName);
        printf("\nAmount        :%.2f\n", bil[loop].list.amount);}

     for(loop=0;loop<3;loop++){
        amountGrand+=bil[loop].list.amount;}

    printf("\n*******************");
    printf("\nGrand Total: %.2f", amountGrand);
    printf("\n*******************");
}



