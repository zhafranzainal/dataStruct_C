#include <stdio.h>

//Structure Declaration (Template)
struct Water{
    int unitCurrent;
    int unitPrevious;
    int unitUsed;
    float totalBillOriginal;
    float totalBillDiscount;};

struct Electric{
    int unitCurrent;
    int unitPrevious;
    int unitUsed;
    float totalBillOriginal;
    float totalBillDiscount;};

struct House{

    char nameOwner[50];
    char address[50];
    float totalBillUndiscounted;
    float totalBill;

    struct Electric electric;
    struct Water water;};

//Function Declaration (Prototype)
struct House getInfo();
struct House calculateBill(struct House house);
float calculateTotalBillsAfterDiscount(struct House house);
void display(struct House house[]);

int main(void){

    //Structure Variable
    struct House house[3];

    for(int i=0;i<3;i++)
    {
        house[i]=getInfo();
        house[i]=calculateBill(house[i]);
        house[i].totalBill=calculateTotalBillsAfterDiscount(house[i]);
    }

    display(house);

return 0;}

//Function Definition: getInfo
struct House getInfo(){

    struct House house;

    printf("\nEnter House Owner Name              : ");
    scanf(" %[^\n]s", &house.nameOwner);

    printf("Enter House Address                 : ");
    scanf(" %[^\n]s", &house.address);

    printf("Enter Current Unit for Electric     : ");
    scanf(" %d", &house.electric.unitCurrent);

    printf("Enter Previous Unit for Electric    : ");
    scanf(" %d", &house.electric.unitPrevious);

    printf("Enter Current Unit for Water        : ");
    scanf(" %d", &house.water.unitCurrent);

    printf("Enter Previous Unit for Water       : ");
    scanf(" %d", &house.water.unitPrevious);

    return house;}

//Function Definition: calculateBill
struct House calculateBill(struct House house){

    house.electric.unitUsed=house.electric.unitCurrent-house.electric.unitPrevious;

    if(house.electric.unitUsed<100){
        house.electric.totalBillOriginal=house.electric.unitUsed*0.10;}

    else if(house.electric.unitUsed<200){
        house.electric.totalBillOriginal=house.electric.unitUsed*0.20;}

    else{
        house.electric.totalBillOriginal=house.electric.unitUsed*0.40;}

    house.water.unitUsed=house.water.unitCurrent-house.water.unitPrevious;

    if(house.water.unitUsed<20){
        house.water.totalBillOriginal=house.water.unitUsed*0.50;}

    else{
        house.water.totalBillOriginal=house.water.unitUsed*1;}

    house.totalBillUndiscounted+=house.electric.totalBillOriginal+house.water.totalBillOriginal;

    return house;}

//Function Definition: calculateTotalBillsAfterDiscount
float calculateTotalBillsAfterDiscount(struct House house){

    if(house.electric.totalBillOriginal<100){
        house.electric.totalBillDiscount=house.electric.totalBillOriginal*0.8;}

    else{
        house.electric.totalBillDiscount=house.electric.totalBillOriginal*0.9;}

    if(house.water.totalBillOriginal<10){
        house.water.totalBillDiscount=house.water.totalBillOriginal*0.8;}

    else{
        house.water.totalBillDiscount=house.water.totalBillOriginal*0.9;}

    house.totalBill=house.electric.totalBillDiscount+house.water.totalBillDiscount;

    return house.totalBill;}

//Function Definition: display
void display(struct House house[]){

    int loop;

    printf("\n\tHOUSE BILL REPORT");

    for(loop=0;loop<3;loop++){
        printf("\n\nHouse Owner Name              : %s", house[loop].nameOwner);
        printf("\nHouse Address                 : %s", house[loop].address);
        printf("\nElectric bill                 : RM%.2f", house[loop].electric.totalBillOriginal);
        printf("\nWater bill                    : RM%.2f", house[loop].water.totalBillOriginal);
        printf("\nTotal bills                   : RM%.2f", house[loop].totalBillUndiscounted);
        printf("\nTotal bills after discount    : RM%.2f", house[loop].totalBill);}

    printf("\n");}
