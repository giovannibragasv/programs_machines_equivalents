#include <stdio.h>

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    int i = 1;
    int temp;

    if (n == 0) goto end_0;
    if (n == 1) goto end_1;

    loop:
        if (i >= n-1) goto end_b;
        temp = a + b;
        a = b;
        b = temp;
        i++;
        goto loop;

    end_0:
        return 0;
    end_1:
        return 1;
    end_b:
        return b;

}