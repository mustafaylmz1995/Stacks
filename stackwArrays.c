#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 50

int stk[STACKSIZE];
int top = -1;
const int max = STACKSIZE;

void push(int insert) {
	if (top >= max - 1) {
		printf("\nOverflow!");
	}
	else {
		top++;
		stk[top] = insert;
	}
}

void pop(void) {
	if (top < 0) {
		printf("\nUnderflow!");
	}
	else {
		printf("\nPop value: \t%d", stk[top]);
		top--;
	}
}


void peek(void) {
	if (top < 0) {
		printf("\nStack is Empty!");
	}
	else {
		printf("\nPeek value: %d", stk[top]);
	}
}

int main(void) {

	peek();
	pop();
	push(555);
	//push 
	printf("\nPush");
	for (int a = 1; a < 5; a++) {
		push(a);
		
	}

	for (int a = -1; a > -5; a--) {
		push(a);
	}
	

	//pop
	printf("\nPop");

	for (int a = 0; a < 8; a++) {
		pop();
	}

	//peek
	printf("\nPeek");
	peek();

	return 0;
}
