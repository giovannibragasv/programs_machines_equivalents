#include <stdio.h>

int fibonacci_mono(int n) {
    int a = 1;
    int b = 1;
    int i = 1;
    int temp;

    printf("%d ", a);    
    if (n == 0) goto end_1;
    
    printf("%d ", b);
    if (n == 1) goto end_1;

    loop:
        if (i >= n-1) goto end_b;
        temp = a + b;
        a = b;
        b = temp;
        printf("%d ", b);
        i++;
        goto loop;

    end_0:
        printf("\n");
        return 0;
    end_1:
        printf("\n");
        return 1;
    end_b:
        printf("\n");
        return b;
}

int main() {
    int num;

    printf("Insira um número: ");
    scanf("%d", &num);

    printf("Sequência de Fibonacci até o termo %d:\n", num);
    int fibo = fibonacci_mono(num);
    
    printf("fibonacci(%d) = %d\n", num, fibo);
    
    return 0;
}