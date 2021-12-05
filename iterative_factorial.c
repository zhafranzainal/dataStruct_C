#include <stdio.h>

int main(void){

    int numPositive, numFactorial=1, loop;

    printf("Enter a positive number: ");
    scanf(" %d", &numPositive);

    for(loop=numPositive;loop>1;loop--){
        numFactorial*=loop;}

    printf("Factorial number for %d! is %d.\n", numPositive, numFactorial);

return 0;
}
