#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 50


void push(char* stack[], int* stkTop, int stkMax, char* insert) {
	if (*stkTop >= stkMax - 1) {
		printf("\nOverflow!");
	}
	else {
		(*stkTop)++;
		stack[*stkTop] = insert;
	}

}


void pop(char* stack[], int* stkTop) {
	if (*stkTop < 0) {
		printf("\nUnderflow!");
	}
	else {
		printf("\nPop value :\t%s", stack[*stkTop]);
		(*stkTop)--;
	}
}


char* peek(char* stack[], int* stkTop) {
	if (*stkTop < 0) {
		printf("\nStack is Empty!");
	}
	else {
		printf("\nPeek value :\t%s", stack[*stkTop]);
	}
	return stack[*stkTop];
}


void display(char* stack[], int* stkTop) {
	
	for (int a = *stkTop; a > -1; a--)
		printf("\nStack[%d] :\t%s", a, stack[a]);

}

int main(void) {

	/****Decleration***/
	//Create Stacks
	char* stk[STACKSIZE];
	char* stk2[STACKSIZE];

	int* top;
	int* top2;
	top = (int*)malloc(sizeof(int));
	top2 = (int*)malloc(sizeof(int));

	if(top)
		*top = -1;
	if (top2)
		*top2 = -1;

	const int max = STACKSIZE;
	const int max2 = STACKSIZE;


	//Push
	printf("\nPush First Stack\n");

	push(stk, top, max, "Ilk");
	push(stk, top, max, "Yorum");
	push(stk, top, max, "Merhaba");
	push(stk, top, max, "dunya");
	push(stk, top, max, "C");
	push(stk, top, max, "Veri");
	push(stk, top, max, "Yapilari");
	
	//display
	printf("\nStack1");
	display(stk, top);
	printf("\nStack2");
	display(stk2, top2);


	//Pushing Second Stack
	printf("\nPush Second Stack");
	while(-1 != *top){
		push(stk2, top2, max2, peek(stk, top));
		pop(stk, top);
	}

	//display2
	printf("\nStack1");
	display(stk, top);
	printf("\nStack2\n");
	display(stk2, top2);


	return 0;
}
