#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define testprintf(type, format, args ...) ( (type)==1 ? (printf(format, ## args)) : (type) )

#define STACKSIZE 50

char operandSTK[STACKSIZE];
int operandTOP = -1;
char operatorSTK[STACKSIZE];
int operatorTOP = -1;
char outputSTK[STACKSIZE];
int outputTOP = -1;


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

int pr = 0;
char peekVal = '\0';

int findPrecedence(char ch1, char ch2);
void reverseOutput(char stk[], int top);

int main(void){

  //Tüm örnekleri deneyelim
  for(int i = 0; i<23; i++){
    int j = 0;  
    int parantez = 0;
    unsigned int len = strlen(str[i]);
    
    //Örnek üzerindeki değerleri tek tek alalım
    for(char *temp = (str[i]+len-1); j<len; temp--){
      
      j++;
      switch(*temp){
        case '^':
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':          
          if(operatorTOP >= (0+parantez) ){
            peekVal = peek(operatorSTK, operatorTOP);
            //0 1 -1 dönecek
            if(findPrecedence(peekVal, *temp) >-1){
              operandTOP = push(operandSTK, operandTOP, max, peekVal);
              operatorTOP = pop(operatorSTK, operatorTOP);
            }
          }
          operatorTOP = push(operatorSTK, operatorTOP, max, *temp);

        break;
        case ')':
          parantez++;
          
        break;
        case '(':
          parantez--;
          while(operatorTOP != (-1) ){
            peekVal = peek(operatorSTK, operatorTOP);
            operandTOP = push(operandSTK, operandTOP, max, peekVal);
            operatorTOP = pop(operatorSTK, operatorTOP);
          }
          
        break;
        default:
          //sayı ise operandSTK ekle
          operandTOP = push(operandSTK, operandTOP, max, *temp);
          
        break;
      }


    }
    
    while(operatorTOP != -1){
      peekVal = peek(operatorSTK, operatorTOP);
      operandTOP = push(operandSTK, operandTOP, max, peekVal);
      operatorTOP = pop(operatorSTK, operatorTOP);
    }

    reverseOutput(operandSTK, operandTOP);

    testprintf(1,"%s\n", outputSTK);
    //testprintf(1, "%s\n", operatorSTK);
    memset(operandSTK, '\0', (operandTOP+1)*sizeof(char));
    memset(operatorSTK, '\0', (operatorTOP+1)*sizeof(char));
    memset(outputSTK, '\0', (outputTOP+1)*sizeof(char));
    outputTOP = -1;
    operandTOP = -1;
    operatorTOP = -1;
  }
 
  return 0;
}


void reverseOutput(char stk[], int top){
  char temp;
  
  while(top!=-1){
    temp = peek(stk, top);
    top = pop(stk, top);
    outputTOP = push(outputSTK, outputTOP, max, temp);
  }

}


int findPrecedence(char ch1, char ch2){
  int Pre[2];
  char st[2];
  st[0] = ch1;
  st[1] = ch2;
  for(int i = 0; i<2; i++){
    switch(st[i]){
      case '^':
        Pre[i] = 4;
      break;
      case '*':
        Pre[i] = 3;
      break;
      case '/':
        Pre[i] = 3;
      break;
      case '%':
        Pre[i] = 2;
      break;
      case '+':
        Pre[i] = 1;
      break;
      case '-':
        Pre[i] = 1;
      break;
    }
  }
  if(Pre[0] > Pre[1]){
    return 1;
  }else if(Pre[0] == Pre[1]){
    return 0;
  }else{
    return -1;
  }

}


int push(char stk[], int top, int max, char insert) {
	if (top >= max - 1) {
		testprintf(pr,"\nOverflow!");
	}
	else {
		top++;
		stk[top] = insert;
	}
	return top;
}

int pop(char stk[], int top) {
	if (top < 0) {
		testprintf(pr,"\nUnderflow!");
	}
	else {
		//testprintf(pr,"\nPop value: \t%d", stk[top]);
		stk[top] = '\0';
		top--;
	}
	return top;
}


char peek(char stk[], int top) {
	if (top < 0) {
		testprintf(pr,"\nStack is Empty!");
		return '\0';
	}
	else {
		//testprintf(pr,"\nPeek value: %d", stk[top]);
		return stk[top];
	}
}
