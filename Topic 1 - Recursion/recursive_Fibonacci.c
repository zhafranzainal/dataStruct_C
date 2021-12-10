#include <stdio.h>

//Function Declaration (Prototype)
int calc_fibonacciSequence(int fibonacciTerm);

int main(void){

    int fibonacciTerm;

    printf("Enter n-th term of a Fibonacci sequence: ");
    scanf(" %d", &fibonacciTerm);

    //Function Calling: calc_fibonacciSequence
    printf("%dth term of the sequence is %d.\n", fibonacciTerm, calc_fibonacciSequence(fibonacciTerm));

return 0;
}

//Function Definition: calc_fibonacciSequence
int calc_fibonacciSequence(int fibonacciTerm){

    if(fibonacciTerm==0 || fibonacciTerm==1){
        return fibonacciTerm;}

	else{
        return (calc_fibonacciSequence(fibonacciTerm-2)+calc_fibonacciSequence(fibonacciTerm-1));}}
