#include <stdio.h>

int fib_calc(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fib_calc(n-1) + fib_calc(n-2);
}

int fibonacci_rec(int n) {
    printf("Sequência de Fibonacci até o termo %d:\n", n);
    
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib_calc(i));
    }
    printf("\n");
    
    return fib_calc(n);
}

int main() {
    int num;
    
    printf("Insira um número: ");
    scanf("%d", &num);
    
    int fibo = fibonacci(num);
    
    printf("Fibonacci(%d) = %d\n", num, fibo);
    
    return 0;
}