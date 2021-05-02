#include <stdio.h>

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int fact(int a) {
    if ((a == 1) || (a == 0)) {
        return 1;
    }
    else {
        return a * fact(a - 1);
    }
}

int expo(int n, int y) {

    if (y == 0) {
        return 1;
    }
    else {
        return expo(n, y - 1) * n;
    }

}

int fibo(int n) {
    if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else {
        return fibo(n - 2) + fibo(n - 1);
    }
}

int tail_recursive_fact(int a) {
    return tail_recursive_fact1(a, 1);
}

int tail_recursive_fact1(int a, int res) {
    if (a == 1) {
        return res;
    }
    else {
        return tail_recursive_fact1(a - 1, res*a);
    }
}


int main(void) {


    printf("gcd : %d\n", gcd(3, 5));
    printf("fact : %d\n", fact(5));
    printf("expo : %d\n", expo(2, 4));
    printf("fibo : %d\n", fibo(6));

    printf("\ntailed_fact : %d\n", tail_recursive_fact(6));

    return 0;
}
