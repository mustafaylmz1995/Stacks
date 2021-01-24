#pragma once
#ifndef __STACKPOSTPREINFIX_H__
#define __STACKPOSTPREINFIX_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STACKSIZE 50

char operandSTK[STACKSIZE];
int operandTOP = -1;
char operatorSTK[STACKSIZE];
int operatorTOP = -1;

const int max = STACKSIZE;

int push(char stk[], int top, int max, char insert);
int pop(char stk[], int top);
char peek(char stk[], int top);

char* str[22] = {"A+B", "A+B+C", "A+B+C+D", 
				"(A+B)-C", "C+(A-B)", "(A+B)-(C+D)",  
				"G-(A+B)-D-E+(C-F)+H", //6
				"A*B", "A*B/C", "A*B/C/D", "A*(B/C)", 
				"(A/B)*C", "(A/B)*(C/D)", 
				"(A*(B/E))*(C/D)*F", //13
				"A+B/C", "A*B-C", "(A+B)*C", 
				"A+(B*C)", "A*(B-C)", "B+(C-(D/F))",
				"(A*B)-(C/D)", "((B-C/E)/(A-D)-F)"//21
};

const char ops[6] = { '-', '+', '%', '/', '*', '^' }; //with precedence 

int push(char stk[], int top, int max, char insert) {
	if (top >= max - 1) {
		printf("\nOverflow!");
	}
	else {
		top++;
		stk[top] = insert;
	}
	return top;
}

int pop(char stk[], int top) {
	if (top < 0) {
		printf("\nUnderflow!");
	}
	else {
		//printf("\nPop value: \t%d", stk[top]);
		stk[top] = '\0';
		top--;
	}
	return top;
}


char peek(char stk[], int top) {
	if (top < 0) {
		printf("\nStack is Empty!");
		return '\0';
	}
	else {
		//printf("\nPeek value: %d", stk[top]);
		return stk[top];
	}
}


#endif /*__STACKPOSTPREINFIX_H__*/
