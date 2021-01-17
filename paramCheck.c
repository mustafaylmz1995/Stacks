#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 50

int stk[STACKSIZE];
int top = -1;
const int max = STACKSIZE;

int push(int stk[], int top, int max, int insert) {
	if (top >= max - 1) {
		printf("\nOverflow!");
	}
	else {
		top++;
		stk[top] = insert;
	}
	return top;

}

int pop(int stk[], int top) {
	if (top < 0) {
		printf("\nUnderflow!");
	}
	else {
		printf("\nPop value: \t%d", stk[top]);
		top--;
	}
	return top;
}


void peek(int stk[], int top) {
	if (top < 0) {
		printf("\nStack is Empty!");
	}
	else {
		printf("\nPeek value: %d", stk[top]);
	}
}



void par_check(char* str) {
	for (; *str != '\0'; str++) {

		//push
		if (*str == '(' || *str == '{' || *str == '[') {
			top = push(stk, top, max, *str);
		}
		//pop
		if (
			(*str == ')' && stk[top] == '(') ||
			(*str == '}' && stk[top] == '{') ||
			(*str == ']' && stk[top] == '[')
			){
			top = pop(stk, top);
		}

	}

	
}

int main(void) {

	char str[50];
	printf("Give some paranthesis!\n");
	gets_s(str, sizeof(str));

	par_check(str);


	return 0;
}
