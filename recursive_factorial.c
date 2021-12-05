#include <stdio.h>

//Function Declaration (Prototype)
int calc_numFactorial(int numPositive);

int main(void){

    int numPositive, numFactorial;

    printf("Enter a positive number: ");
    scanf(" %d", &numPositive);

    //Function Calling: calc_numFactorial
    numFactorial=calc_numFactorial(numPositive);

    printf("Factorial number for %d! is %d.\n", numPositive, numFactorial);

return 0;
}

//Function Definition: calc_numFactorial
int calc_numFactorial(int numPositive){

    if(numPositive==0){
        return 1;}

	else{
        return (numPositive*calc_numFactorial(numPositive-1));}}
