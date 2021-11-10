#include <stdio.h>

//Structure Declaration (Template)
struct Customer{

    char name[50];
    char IDnum[15];
    float purchase;

    struct Reward{
        int current;
        int redemption;
        int collect;}point;

    struct Item{
        char code[5];
        float price;
        float discount;}item[5];
};

//Function Declaration (Prototype)
void read_custInput(int custTotal, struct Customer *cust);
float calc_totalPurchase(struct Customer cust);
struct Customer calc_pointRedemption(int loopCust, struct Customer cust);
void print_infoAll(int custTotal, struct Customer cust[]);

int main(void){

    //Structure Variable
    struct Customer cust[5];

    int custTotal;

    printf("Enter how many customer(s): ");
    scanf(" %d", &custTotal);

    //Function Calling: read_custInput
    read_custInput(custTotal, cust);

    //Function Calling: print_infoAll
    print_infoAll(custTotal, cust);

return 0;
}

//Function Definition: read_custInput
void read_custInput(int custTotal, struct Customer *cust){

    int loopCust;

    for(loopCust=0;loopCust<custTotal;loopCust++){

        printf("\nINSERT CUSTOMER INFO");
        printf("\n====================");
        printf("\n\nCUSTOMER %d", loopCust+1);

        printf("\nEnter Customer Name           : ");
        scanf(" %[^\n]s", &cust[loopCust].name);

        printf("Enter Customer ID             : ");
        scanf(" %[^\n]s", &cust[loopCust].IDnum);

        printf("Enter Customer Current Point  : ");
        scanf(" %d", &cust[loopCust].point.current);

        //Function Calling: calc_totalPurchase
        cust[loopCust].purchase=calc_totalPurchase(cust[loopCust]);

        //Function Calling: calc_pointRedemption
        cust[loopCust]=calc_pointRedemption(loopCust, cust[loopCust]);}}

//Function Definition: calc_totalPurchase
float calc_totalPurchase(struct Customer cust){

    int userExit=1, loopItem=0;

    cust.purchase=0;

    printf("\nPURCHASE ELECTRICAL ITEMS");
    printf("\n=========================\n");

    while(userExit!=0){

        printf("\nITEM %d", loopItem+1);

        printf("\nEnter item code  : ");
        scanf(" %[^\n]s", &cust.item[loopItem].code);

        printf("Enter item price : ");
        scanf(" %f", &cust.item[loopItem].price);

        if(cust.item[loopItem].price<250){
            cust.item[loopItem].discount=cust.item[loopItem].price*0;}
        else if(cust.item[loopItem].price<750){
            cust.item[loopItem].discount=cust.item[loopItem].price*0.03;}
        else if(cust.item[loopItem].price<1000){
            cust.item[loopItem].discount=cust.item[loopItem].price*0.05;}
        else{
            cust.item[loopItem].discount=cust.item[loopItem].price*0.1;}

        cust.purchase+=cust.item[loopItem].price-cust.item[loopItem].discount;

        printf("\nItem Price            = RM%.2f", cust.item[loopItem].price);
        printf("\nItem Discounted Value = RM%.2f", cust.item[loopItem].discount);
        printf("\nTotal Purchase %s = RM%.2f", cust.name, cust.purchase);

        printf("\n\nPurchase more items? (Yes=1, No=0): ");
        scanf(" %d", &userExit);

        loopItem++;}

    return cust.purchase;}

//Function Definition: calc_pointRedemption
struct Customer calc_pointRedemption(int loop, struct Customer cust){

    cust.point.collect=cust.purchase/10;
    cust.point.current+=cust.point.collect;

    printf("\nPOINT REDEMPTION %d", loop+1);

    //prompt error
    for(;;){
    printf("\nEnter point to redeem (must not exceed %d): ", cust.point.current);
    scanf(" %d", &cust.point.redemption);

    if(cust.point.redemption<=cust.point.current){
        break;}

    printf("\n\nERROR! Exceed your current point\nPlease try again.\n");}

    cust.point.current-=cust.point.redemption;

    return cust;};

//Function Definition: print_infoAll
void print_infoAll(int custTotal, struct Customer cust[]){

    int loop;

    for(loop=0;loop<custTotal;loop++){
        printf("\nDisplay Customer %d Points", loop+1);
        printf("\nCustomer Name : %s", cust[loop].name);
        printf("\nCustomer ID   : %s", cust[loop].IDnum);
        printf("\nUpdated Point : %d\n", cust[loop].point.current);}}

