#include <stdio.h>

//Function Declaration (Prototype)
void calc_towerSteps(int towerSize, char towerOrigin, char towerMiddle, char towerDestination);

int main(void){

    int towerSize;

    printf("There are 3 towers named as A, B, and C. ");
    printf("\n\nOBJECTIVE: Move all the disks over to Tower C.");
    printf("\nRULE: Cannot place a larger disk onto a smaller disk.");

    printf("\n\nEnter number of disks: ");
    scanf(" %d", &towerSize);

    if(towerSize>0){
        //Function Calling: calc_towerSteps
        calc_towerSteps(towerSize, 'A', 'B', 'C');}

    printf("\n");

return 0;
}

//Function Definition: calc_towerSteps
void calc_towerSteps(int towerSize, char towerOrigin, char towerMiddle, char towerDestination){

    static int towerSteps=0;

    if(towerSize==1){
        printf("\nStep %d: Move disk 1 from Tower %c to Tower %c", ++towerSteps, towerOrigin, towerDestination);
        return;}

	else{
        calc_towerSteps(towerSize-1, towerOrigin, towerDestination, towerMiddle);
        printf("\nStep %d: Move disk %d from Tower %c to Tower %c", ++towerSteps, towerSize, towerOrigin, towerDestination);
        calc_towerSteps(towerSize-1, towerMiddle, towerOrigin, towerDestination);}}
