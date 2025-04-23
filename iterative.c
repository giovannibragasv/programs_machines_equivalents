#include <stdio.h>

int fibonacci_it(int n) {
    if (n == 0) {
        printf("0 \n");
        return 0;
    }
    
    if (n == 1) {
        printf("0 1 \n");
        return 1;
    }
    
    int a = 0;
    int b = 1;
    int resultado;
    
    printf("%d %d ", a, b);
    
    for (int i = 2; i <= n; i++) {
        resultado = a + b;
        printf("%d ", resultado);
        a = b;
        b = resultado;
    }
    
    printf("\n");
    return b;
}

int main() {
    int num;
    
    printf("Insira um número: ");
    scanf("%d", &num);
    
    printf("Sequência de Fibonacci até o termo %d:\n", num);
    int fibo = fibonacci(num);
    
    printf("Fibonacci(%d) = %d\n", num, fibo);
    
    return 0;
}