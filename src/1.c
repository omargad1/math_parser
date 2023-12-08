/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// char stack


int top=-1,stack[25];
char infix[25],postfix[25];

void push(char item){
	stack[++top]=item;

}

char pop(void){
	return stack[top--];
}

int precedance(char symbol){

	switch(symbol){

	case '+':
	case '-':
		     return 1;

	case '*':
	case '/':
			 return 2;

	case '^':
		     return 3;
	default:
		return 0;
	}


}






void infixTOpostfix(char infix[],char postfix[]){
	char symbol;
	int i,j=0;

	for(i=0;i<strlen(infix);i++){

		symbol=infix[i];

		switch(symbol){

		case '(':
			push(symbol);
			break;
		case ')':
			while(stack[top] != '('){
				postfix[j++]=pop();
			}
			pop();
			break;
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
			while((precedance(symbol)<=precedance(stack[top])) && (top!=-1) ){
				postfix[j++]=pop();
			}
			push(symbol);
			break;

		default:
			postfix[j++]=symbol;
			break;

		}//end of switch case




	} //end of the for loop


while(top!=-1){
	postfix[j++]=pop();
}
	postfix[j]='\0';

}


int evaluate(char postfix[]){
	int i,a,b;
	top=-1;
	for(i=0;i<strlen(postfix);i++){
		if( (postfix[i]>='0') && (postfix[i])<='9'  ){
			push(postfix[i]-'0');
		}
		else{
			a=pop();
			b=pop();
			switch(postfix[i]){

			case '+':
				push(b+a);
				break;
			case '-':
				push(b-a);
				break;
			case '*':
				push(b*a);
				break;
			case '/':
				push(b/a);
				break;
			case '^':
				push(pow(b,a));
				break;

			}//end of switch



		}//end of else

	}//end of for loop

	return pop();

}


int main(void) {
	int result=0;

	setbuf(stdout, NULL);
	printf("enter the expression\n");
    gets(infix);

infixTOpostfix(infix, postfix);
puts(infix);

result= evaluate(postfix);

printf("result = %d\n",result);

return 0;

}

















