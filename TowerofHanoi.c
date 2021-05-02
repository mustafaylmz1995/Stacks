#include <stdio.h>


void move(int nRings, char source, char dest, char spare) {
	if (nRings == 1) {
		printf("\n Move from %c to %c", source, dest);
	}
	else {
		move(nRings - 1, source, spare, dest);
		move(1, source, dest, spare);
		move(nRings - 1, spare, dest, source);
	}
}



int main() {

	int n;
	printf("\n Enter the number of rings: ");

	scanf("%d", &n);
	move(n, 'A', 'B', 'C');

	return 0;
}
