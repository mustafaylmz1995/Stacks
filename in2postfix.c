#include "StackPostPreInfix.h"



void main(void) {

	// Tüm örnekleri deneyelim
	for (int i = 17; i < 22; i++) {

		int precedence = 0;
		int islemtamam[10] = { 0 };
		int parantez = 0;

		//örnek üzerindeki karakterleri tek tek alalım
		for (char* temp = str[i]; *temp != '\0'; temp++) {
			
			//operand ve operator diye ayırıp stackle
			if (*temp == '^') {
				precedence = 2;
				operatorTOP = push(operatorSTK, operatorTOP, max, *temp);
			}
			else if (*temp == '*' ||
					 *temp == '/') {
				precedence = 1;
				operatorTOP = push(operatorSTK, operatorTOP, max, *temp);
			}
			else if (*temp == '+' ||
					 *temp == '-' ) {
				precedence = 0;
				operatorTOP = push(operatorSTK, operatorTOP, max, *temp);
			}
			else if (*temp == '(') {
				//parantez açildi yeni bir alanda çalşmalıyız
				parantez++;
			}
			else if (*temp == ')') {
				//parantez kapandı islem tamamlandı parantez sayısı azaldı
				islemtamam[parantez] = 0;
				parantez--;
				//parantezli kısım işlemin bir operand'ıdır.
				islemtamam[parantez]++;
			}
			else {
				//sayı ise operandSTK'a ekle
				operandTOP = push(operandSTK, operandTOP, max, *temp);
				islemtamam[parantez]++;
	
			}

			//bir islem tamamlandı
			if (islemtamam[parantez] == 2) {
				if (precedence == 2) {
					operandTOP = push(operandSTK, operandTOP, max, peek(operatorSTK, operatorTOP));
					operatorTOP = pop(operatorSTK, operatorTOP);
					
				}
				else if (precedence == 1) {
					//bir sonraki operator precedence 2 olmadığından emin ol
					if (*(temp+1) == '\0' ||
						*(temp+1) != '^') {
						operandTOP = push(operandSTK, operandTOP, max, peek(operatorSTK, operatorTOP));
						operatorTOP = pop(operatorSTK, operatorTOP);

						if (parantez == 0 && (operatorTOP != -1) && ((peek(operatorSTK, operatorTOP) == '+' ) || (peek(operatorSTK, operatorTOP) == '-')) ) {
							operandTOP = push(operandSTK, operandTOP, max, peek(operatorSTK, operatorTOP));
							operatorTOP = pop(operatorSTK, operatorTOP);
						}
					}
				}
				else {
					//bir sonraki operatorun precedence degeri yüksek olmamalı
					if (*(temp+1) == '\0'||	( *(temp+1) != '^' && *(temp+1) != '/' && *(temp+1) != '*') ){
						operandTOP = push(operandSTK, operandTOP, max, peek(operatorSTK, operatorTOP));
						operatorTOP = pop(operatorSTK, operatorTOP);
					}
					
				}
				islemtamam[parantez] = 1;
			}

		}


		//Yazdır
		printf("\n%s", operandSTK);
		//Stackleri temizle
		memset(operandSTK, '\0', (operandTOP + 1) * sizeof(char));
		operandTOP = -1;

		memset(operatorSTK, '\0', (operatorTOP + 1) * sizeof(char));
		operatorTOP = -1;

		

	}




}

