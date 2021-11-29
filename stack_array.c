#include <stdio.h>
#include <stdlib.h>

#define MAX 7

//Function Declaration (Prototype)
void push(int getPush, int* top);
void pop(int* top);
void palindromeCheck();
void display(int list);

int stack[MAX];

int main(void){

    int userChoice, number, top=-1;

    do{
		printf("\n-------------------Stack Menu-------------------");
        printf("\nEnter 1 to insert an element into the stack");
        printf("\nEnter 2 to delete an element from the stack");
        printf("\nEnter 3 to check whether an element is palindrome");
        printf("\nEnter 4 to check status of the stack");
        printf("\nEnter 5 to exit");

        printf("\n\nYou enter: ");
        scanf(" %d", &userChoice);

        switch(userChoice){
            case 1: printf("\nPlease enter the number to push stack: ");
                    scanf(" %d", &number);
                    push(number, &top);
                    break;

            case 2: pop(&top);
                    break;

            case 3: palindromeCheck();
                    break;

            case 4: display(top);
                    break;

            default: printf("Invalid entry. Please choose 1-5 only.");}

    }while(userChoice!=5);

return 0;
}

//Function Definition: push
void push(int getPush, int* top){

    system("cls");

    if(*top+1==MAX){
        printf("Stack OVERFLOW! Can't push more stack before deleting any element.\n");
        return;}

    else{
        stack[++*top]=getPush;
        display(*top);
        return;}
}

//Function Definition: pop
void pop(int* top){

    system("cls");

    if(*top<0){
        printf("Stack UNDERFLOW! No element to be deleted.\n");
        return;}

    else{
        printf("Element popped is %d\n", stack[*top]);
        *top-=1;
        return;}
}

//Function Definition: palindromeCheck
void palindromeCheck(){

    int integer, original, remainder, reversed=0;

    printf("\nEnter the element to check whether it is palindrome: ");
    scanf(" %d", &integer);

    original=integer;

    //reversed integer is stored in reversed variable
    while(integer!=0){
        remainder=integer%10;
        reversed=reversed*10+remainder;
        integer/=10;}

    system("cls");

    //palindrome if original and reversed are equal

    if(original==reversed){
        printf("%d is a palindrome\n", original);}
    else{
        printf("%d is not a palindrome\n", original);}
}

//Function Definition: display
void display(int list){

    int loop;

    system("cls");

    printf("The status of the stack is\n");

    if(list==-1){
        printf("0\n");}

    else{
        for(loop=list;loop>=0;loop--){
            printf("%d\n", stack[loop]);}}
}
