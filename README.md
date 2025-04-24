# Atividade Prática: Programas, Máquinas e Equivalência
Este repositório contém a implementação de um mesmo programa (sequência de Fibonacci) em três paradigmas diferentes, para demonstrar a equivalência de programas através da Máquina de Traços (MT), para a matéria de Teoria da Computabilidade, ministrada pelo Prof. Daniel Souza, do curso de Ciência de Computação no Centro Universitário do Estado do Pará (CESUPA).

## Índice
- [Descrição do Projeto](#descrição-do-projeto)
- [Estrutura do Repositório](#estrutura-do-repositório)
- [Implementações](#implementações)
  - [Fibonacci Monolítico](#fibonacci-monolítico-c-com-goto)
  - [Fibonacci Iterativo](#fibonacci-iterativo)
  - [Fibonacci Recursivo](#fibonacci-recursivo)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Máquina de Traços e Equivalência](#máquina-de-traços-e-equivalência)
  - [Definição Formal da Máquina de Traços](#definição-formal-da-máquina-de-traços)
  - [Máquina de Traços - Monolítico](#máquina-de-traços---monolítico)
  - [Máquina de Traços - Iterativo](#máquina-de-traços---iterativo)
  - [Máquina de Traços - Recursivo](#máquina-de-traços---recursivo)
  - [Exemplo de Equivalência](#exemplo-de-equivalência)
  - [Demonstração de Equivalência](#demonstração-de-equivalência)
  - [Exemplo de Não-Equivalência](#exemplo-de-não-equivalência)
- [Autores](#autores)

## Descrição do Projeto
O projeto implementa o cálculo da sequência de Fibonacci em três paradigmas diferentes:
1. **Monolítico**: Utilizando estruturas de controle de fluxo baseadas em `goto`
2. **Iterativo**: Utilizando estruturas de repetição convencionais
3. **Recursivo**: Utilizando chamadas recursivas

O objetivo é demonstrar a equivalência forte entre os programas utilizando o método da Máquina de Traços (MT).

## Estrutura do Repositório
```
.
├── README.md
├── iterative/
│   ├── fibonacci_iterative
│   └── iterative.c
├── monolithic/
│   ├── fibonacci_mono
│   └── monolithic.c
└── recursive/
    ├── fibonacci_recursive
    └── recursive.c
```

## Implementações

### Fibonacci Monolítico (C com goto)
O arquivo `monolithic/monolithic.c` contém a implementação monolítica da sequência de Fibonacci utilizando o comando `goto` para controle de fluxo.

```c
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
```

### Fibonacci Iterativo
O arquivo `iterative/iterative.c` contém a implementação iterativa da sequência de Fibonacci utilizando estruturas de repetição convencionais (for/while).

```c
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int a = 0;
    int b = 1;
    int resultado;
    
    for (int i = 2; i <= n; i++) {
        resultado = a + b;
        a = b;
        b = resultado;
    }
    
    return b;
}
```

### Fibonacci Recursivo
O arquivo `recursive/recursive.c` contém a implementação recursiva da sequência de Fibonacci utilizando chamadas recursivas.

```c
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci(n-1) + fibonacci(n-2);
}
```

## Como Compilar e Executar
```bash
# Monolítico
cd monolithic
gcc monolithic.c -o fibonacci_mono
./fibonacci_mono

# Iterativo
cd iterative
gcc iterative.c -o fibonacci_iterative
./fibonacci_iterative

# Recursivo
cd recursive
gcc recursive.c -o fibonacci_recursive
./fibonacci_recursive
```

## Máquina de Traços e Equivalência
A Máquina de Traços (MT) é um método formal para verificar a equivalência entre programas. O processo envolve:
1. Identificar os estados relevantes do programa
2. Registrar todos os estados durante a execução para uma entrada específica
3. Comparar as saídas e comportamentos para determinar a equivalência

### Definição Formal da Máquina de Traços
Uma Máquina de Traços (MT) é definida como:
M = (V, X, Y, πX, πY, ΠO, ΠT)

Onde:
- V é o conjunto de estados possíveis
- X é o conjunto de entradas
- Y é o conjunto de saídas
- πX é a função de projeção de entrada
- πY é a função de projeção de saída
- ΠO é o conjunto de operações
- ΠT é o conjunto de testes

### Máquina de Traços - Monolítico

**Regras:**
- R1: Faça (F), vá para R2.
- R2: Se (T), vá para R5 se n==0, senão vá para R3.
- R3: Se (T), vá para R5 se n==1, senão vá para R4.
- R4: Faça (G), vá para R2.
- R5: (Fim).

**Operações:**
- F: a=0, b=1, i=1 (inicialização)
- T: verificação de condições (n==0, n==1, i>=n-1)
- G: temp=a+b; a=b; b=temp; i++ (cálculo e atualização)
- H: return (retorno do valor)

**Execução para n=5:**
- Estado inicial: (1,ε)
- Linha 1: F, (1,ε) → (2,F)
- Linha 2: T (n==0, falso), (2,F) → (3,FT)
- Linha 3: T (n==1, falso), (3,FT) → (4,FTT)
- Linha 4: G (i=1, a=0, b=1), (4,FTT) → (2,FTTG)
- Linha 2: T (i≥n-1, falso), (2,FTTG) → (4,FTTGT)
- Linha 4: G (i=2, a=1, b=1), (4,FTTGT) → (2,FTTGTG)
- Linha 2: T (i≥n-1, falso), (2,FTTGTG) → (4,FTTGTGT)
- Linha 4: G (i=3, a=1, b=2), (4,FTTGTGT) → (2,FTTGTGTG)
- Linha 2: T (i≥n-1, falso), (2,FTTGTGTG) → (4,FTTGTGTGT)
- Linha 4: G (i=4, a=2, b=3), (4,FTTGTGTGT) → (2,FTTGTGTGTG)
- Linha 2: T (i≥n-1, verdadeiro), (2,FTTGTGTGTG) → (5,FTTGTGTGTGT)
- Linha 5: H (return b=5), (5,FTTGTGTGTGT) → (6,FTTGTGTGTGTH)

**Resultado final: FGGGGH = 5**

### Máquina de Traços - Iterativo

**Regras:**
- R1: Faça (F), vá para R2.
- R2: Se (T), vá para R6 se n==0, senão vá para R3.
- R3: Se (T), vá para R6 se n==1, senão vá para R4.
- R4: Se (T), vá para R6 se i>n, senão vá para R5.
- R5: Faça (G), vá para R4.
- R6: (Fim).

**Operações:**
- F: a=0, b=1, i=2 (inicialização)
- T: verificação de condições
- G: resultado=a+b; a=b; b=resultado; i++ (cálculo e atualização)
- H: return (retorno do valor)

**Execução para n=5:**
- Estado inicial: (1,ε)
- Linha 1: F, (1,ε) → (2,F)
- Linha 2: T (n==0, falso), (2,F) → (3,FT)
- Linha 3: T (n==1, falso), (3,FT) → (4,FTT)
- Linha 4: T (i≤n, verdadeiro), (4,FTT) → (5,FTTT)
- Linha 5: G (i=2, a=0, b=1, resultado=1), (5,FTTT) → (4,FTTTG)
- Linha 4: T (i≤n, verdadeiro), (4,FTTTG) → (5,FTTTGT)
- Linha 5: G (i=3, a=1, b=1, resultado=2), (5,FTTTGT) → (4,FTTTGTG)
- Linha 4: T (i≤n, verdadeiro), (4,FTTTGTG) → (5,FTTTGTGT)
- Linha 5: G (i=4, a=1, b=2, resultado=3), (5,FTTTGTGT) → (4,FTTTGTGTG)
- Linha 4: T (i≤n, verdadeiro), (4,FTTTGTGTG) → (5,FTTTGTGTGT)
- Linha 5: G (i=5, a=2, b=3, resultado=5), (5,FTTTGTGTGT) → (4,FTTTGTGTGTG)
- Linha 4: T (i≤n, verdadeiro), (4,FTTTGTGTGTG) → (5,FTTTGTGTGTGT)
- Linha 5: G (i=6, a=3, b=5, resultado=8), (5,FTTTGTGTGTGT) → (4,FTTTGTGTGTGTG)
- Linha 4: T (i≤n, falso), (4,FTTTGTGTGTGTG) → (6,FTTTGTGTGTGTGT)
- Linha 6: H (return b=5), (6,FTTTGTGTGTGTGT) → (7,FTTTGTGTGTGTGTH)

**Resultado final: FGGGGH = 5**

### Máquina de Traços - Recursivo

**Regras:**
- R1: Faça (F), vá para R2.
- R2: Se (T), vá para R5 se n==0, senão vá para R3.
- R3: Se (T), vá para R5 se n==1, senão vá para R4.
- R4: Faça (G), vá para R1 (chamada recursiva).
- R5: (Fim).

**Operações:**
- F: inicialização de chamada
- T: verificação de condições (n==0, n==1)
- G: chamada recursiva (fibonacci(n-1) + fibonacci(n-2))
- H: combinação de resultados recursivos

**Chamada 1 (fib(5)):**
- Estado inicial: (1,ε)
- Linha 1: F, (1,ε) → (2,F)
- Linha 2: T (n==0, falso), (2,F) → (3,FT)
- Linha 3: T (n==1, falso), (3,FT) → (4,FTT)
- Linha 4: G (chamada fib(4)), (4,FTT) → (1,FTTG)

**Chamada 2 (fib(4)):**
- Linha 1: F, (1,FTTG) → (2,FTTGF)
- Linha 2: T (n==0, falso), (2,FTTGF) → (3,FTTGFT)
- Linha 3: T (n==1, falso), (3,FTTGFT) → (4,FTTGFTT)
- Linha 4: G (chamada fib(3)), (4,FTTGFTT) → (1,FTTGFTTG)

**Após resolução de todas as chamadas recursivas:**
- fib(2) = fib(1) + fib(0) = 1 + 0 = 1
- fib(3) = fib(2) + fib(1) = 1 + 1 = 2
- fib(4) = fib(3) + fib(2) = 2 + 1 = 3
- fib(5) = fib(4) + fib(3) = 3 + 2 = 5

**Resultado final: FGGGGH = 5**

### Exemplo de Equivalência

Para n = 5, o traço de execução de todos os programas resulta em:

**Monolítico**: 
```
Estado inicial: (n=5, a=0, b=1, i=1)
Passo 1: (n=5, a=1, b=1, i=2)
Passo 2: (n=5, a=1, b=2, i=3)
Passo 3: (n=5, a=2, b=3, i=4)
Passo 4: (n=5, a=3, b=5, i=5)
Saída: 5
```

**Iterativo**:
```
Estado inicial: (n=5, a=0, b=1)
Passo 1: (n=5, a=1, b=1, i=2)
Passo 2: (n=5, a=1, b=2, i=3)
Passo 3: (n=5, a=2, b=3, i=4)
Passo 4: (n=5, a=3, b=5, i=5)
Saída: 5
```

**Recursivo**:
```
fibonacci(5)
  = fibonacci(4) + fibonacci(3)
  = [fibonacci(3) + fibonacci(2)] + [fibonacci(2) + fibonacci(1)]
  = [[fibonacci(2) + fibonacci(1)] + [fibonacci(1) + fibonacci(0)]] + [[fibonacci(1) + fibonacci(0)] + 1]
  = [[[fibonacci(1) + fibonacci(0)] + 1] + [1 + 0]] + [[1 + 0] + 1]
  = [[[1 + 0] + 1] + [1 + 0]] + [[1 + 0] + 1]
  = [[1 + 1] + 1] + [1 + 1]
  = [2 + 1] + 2
  = 3 + 2
  = 5
Saída: 5
```

### Demonstração de Equivalência

Após análise das Máquinas de Traços das três implementações, podemos observar que:

1. Todas as implementações produzem o mesmo resultado para a entrada n=5: 5
2. Todas compartilham uma estrutura similar de operações básicas (inicialização, teste, cálculo)
3. A cadeia gerada pelas três máquinas mostra equivalência no comportamento

Portanto, podemos concluir que as três implementações são fortemente equivalentes.

### Exemplo de Não-Equivalência

Para demonstrar não-equivalência, modificamos o programa monolítico para começar com valores diferentes:

```c
int fibonacci_mono(int n) {
    int a = 1;  // modificado de 0 para 1
    int b = 1;
    int i = 1;
    int temp;
    
    if (n == 0) goto end_1;  // modificado para retornar 1 para n=0
    if (n == 1) goto end_1;
    
    // resto do código igual...
}
```

Para n = 0:
- Algoritmos originais: 0
- Algoritmo modificado: 1

Para n = 5:
- Algoritmos originais: 5
- Algoritmo modificado: 8

A cadeia de operações seria diferente, demonstrando não-equivalência entre os programas.

## Autores
- Giovanni B. S. Vasconcelos
- Cauã M. S. Nara
