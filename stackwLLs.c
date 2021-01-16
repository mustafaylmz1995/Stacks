#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node {
	struct Node* next;
	int val;
}node;

node* top = NULL;

node* push(node *top, int insert) {

	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	if (newNode) {
		newNode->val = insert;
	}
	else {
		printf("No Space");
		exit(-1);
	}
	

	if (top == NULL) {
		newNode->next = NULL;
		top = newNode;
	}
	else {
		newNode->next = top;
		top = newNode;
	}

	return top;
}

node* pop(node* top) {
	node* ptr;
	
	if (top == NULL) {
		printf("\nUnderflow!");
	}
	else {
		ptr = top;
		top = top->next;
		ptr->next = NULL;
		free(ptr);
	}
	return top;
}


node* peek(node* top) {
	if (top == NULL) {
		printf("\nStack is Empty!");
	}
	else {
		printf("\nPeek value: %d", top->val);
	}
	return top;
}

node* display(node* top) {
	node* ptr;

	ptr = top;
	while (ptr != NULL) {
		printf("\n -->\t%d", ptr->val);
		ptr = ptr->next;
	}

	return top;
}

int main(void) {



	top = peek(top);
	top = pop(top);
	top = push(top, 555);
	//display
	top = display(top);

	//push 
	printf("\nPush");
	for (int a = 1; a < 5; a++) {
		top = push(top, a);
		
	}

	for (int a = -1; a > -5; a--) {
		top = push(top, a);
	}
	
	//display
	top = display(top);

	//pop
	printf("\nPop");

	for (int a = 0; a < 8; a++) {
		top = pop(top);
	}

	//peek
	printf("\nPeek");
	top = peek(top);


	free(top); 


	return 0;
}
