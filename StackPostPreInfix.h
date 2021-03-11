#pragma once
#ifndef __STACKPOSTPREINFIX_H__
#define __STACKPOSTPREINFIX_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define testprintf(type, format, args ...) ( (type)==1 ? (printf(format, ## args)) : (type) )

#define STACKSIZE 50

char operandSTK[STACKSIZE];
int operandTOP = -1;
char operatorSTK[STACKSIZE];
int operatorTOP = -1;

const int max = STACKSIZE;

int push(char stk[], int top, int max, char insert);
int pop(char stk[], int top);
char peek(char stk[], int top);
char* str[23] = {
  "A+B",  //AB+ x
  "A+B+C",  //AB+C+ x
  "A+B+C+D",  //AB+C+D+ x
	"(A+B)-C",  //AB+C- x
  "C+(A-B)",  //CAB-+ x
  "(A+B)-(C+D)",  //AB+CD+-  x
	"G-(A+B)-D-E+(C-F)+H",  //GAB+-D-E-CF-+H+  //6  x
	"A*B",  //AB* x
  "A*B/C",  //AB*C/ x
  "A*B/C/D",  //AB*C/D/ x
  "A*(B/C)",  //ABC/* x
	"(A/B)*C",  //AB/C* x
  "(A/B)*(C/D)", //AB/CD/*  x
	"(A*(B/E))*(C/D)*F",  //ABE/*CD/*F*  //13 x
	"A+B/C",  //ABC/+ x
  "A*B-C",  //AB*C- x
  "(A+B)*C",  //AB+C* x
	"A+(B*C)",  //ABC*+ x
  "A*(B-C)",  //ABC-* x
  "B+(C-(D/F))",  //BCDF/-+ x
	"(A*B)-(C/D)",  //AB*CD/- x
  "((B-C/E)/(A-D)-F)", //BCE/-AD-/F- //21
  "((A-D)/(B-C/E)-F)" //AD-BCE/-/F-
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
