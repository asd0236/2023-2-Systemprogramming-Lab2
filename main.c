#include <stdio.h>
//#include "operations.h"

int main() {
    int a = 10;
    int b = 5;

    printf("a = %d, b = %d\n", a, b);
    printf("add: %d\n", a+b);
    printf("subtract: %d\n", a-b);
    printf("multiply: %d\n", a*b);
    printf("divide: %.2f\n", (double)a/b);

    return 0;
}