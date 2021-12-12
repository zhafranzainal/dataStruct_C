#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for exit()
#include <ctype.h>  //for isdigit(char)

#define SIZE 100

//This program converts infix expression to postfix expression.
//This program assume that there are 6 operators (+, -, *, /, %, ^) in infix expression and alphanumeric operands.
//This program will not work for fractional numbers.

//Function Declaration (Prototype)
void infixToPostfix(char infix_exp[], char postfix_exp[]);
void push(char item);
int isOperator(char symbol);
char pop();
int precedence(char symbol);

//Global Variable
char stack[SIZE];
int top=-1;

int main(void){

    char infix[SIZE], postfix[SIZE];

    printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.");

    printf("\n\nEnter a valid infix expression\n");
    gets(infix);

    printf("\nThe infix expression      : %s", infix);

    infixToPostfix(infix, postfix);

    printf("\nThe postfix expression    : %s", postfix);

    printf("\n");

return 0;
}

//Function Definition: convert infix to postfix expression
void infixToPostfix(char infix_exp[], char postfix_exp[]){

    int loopInfix=0, loopPostfix=0;
    char item, x;

    //push '(' to stack
    push('(');

    //add ')' to infix expression
    strcat(infix_exp, ")");

    //initialize before loop
    item=infix_exp[loopInfix];

    //run loop till end of infix expression
    while(item!='\0'){

        //if symbol is '('
        if(item=='('){
           push(item);}

        else if(isdigit(item) || isalpha(item)){
            //add operand symbol to postfix expression
            postfix_exp[loopPostfix]=item;
            loopPostfix++;}

        //if symbol is operator
        else if(isOperator(item)==1){

            x=pop();

            while(isOperator(x)==1 && precedence(x)>=precedence(item)){

                //pop all higher precedence operator
                postfix_exp[loopPostfix]=x;
                loopPostfix++;

                //add them to postfix expression
                x = pop();}

            push(x);

            //push current operator symbol onto stack
            push(item);}

		//if current symbol is ')'
		else if(item==')'){

            x = pop();

			while(x!='('){

				postfix_exp[loopPostfix]=x;
				loopPostfix++;
				x = pop();}}

		//if current symbol is neither operand nor '()' and nor operator
		else{
			printf("\nInvalid infix expression.\n");
			getchar();
			exit(1);}

		loopInfix++;

		item = infix_exp[loopInfix];
	}

	if(top>0){
		printf("\nInvalid infix expression.\n");
		getchar();
		exit(1);}

	postfix_exp[loopPostfix]='\0';
}

//Function Definition: push operation
void push(char item){

	if(top>=SIZE-1){
		printf("\nStack Overflow.");}
	else{
		top+=1;
		stack[top]=item;}
}

//Function Definition: determine whether a symbol is an operator or an operand
int isOperator(char symbol){

	if(symbol=='+' || symbol=='-' || symbol=='*'|| symbol=='/'|| symbol=='%'|| symbol=='^'){
		return 1;}
	else{
        return 0;}
}

//Function Definition: pop operation
char pop(){

    char item;

	if(top<0){
		//underflow may occur for invalid expression where ( and ) are not matched
		printf("Stack underflow! Invalid infix expression");
		getchar();
		exit(1);}
	else{
        item=stack[top];
		top=top-1;
		return(item);}
}

//Function Definition: assign precedence to operator
int precedence(char symbol){

    //assume the higher the int value, the higher the precedence
	//exponent operator '^' as the highest precedence
    //addition and subtraction operator '+' '-' as the lowest precedence

	if(symbol=='^'){
		return(3);}
	else if(symbol=='*' || symbol=='/' || symbol=='%'){
		return(2);}
	else if(symbol == '+' || symbol == '-'){
		return(1);}
	else{
		return(0);}
}


