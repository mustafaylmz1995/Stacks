#include "StackPostPreInfix.h"

int pr = 0;
char peekVal = '\0';

int findPrecedence(char ch1, char ch2);

int main(void){

  //Tüm örnekleri deneyelim
  for(int i = 0; i<23; i++){
    
    int parantez = 0;

    //Örnek üzerindeki değerleri tek tek alalım
    for(char *temp = str[i]; *temp != '\0'; temp++){
      
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
        case '(':
          parantez++;
          
        break;
        case ')':
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
    testprintf(1,"%s\n", operandSTK);
    //testprintf(1, "%s\n", operatorSTK);
    memset(operandSTK, '\0', (operandTOP+1)*sizeof(char));
    memset(operatorSTK, '\0', (operatorTOP+1)*sizeof(char));
    operandTOP = -1;
    operatorTOP = -1;
  }


 
  return 0;
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

