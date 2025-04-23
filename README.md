# Atividade Prática: Programas, Máquinas e Equivalência

Este repositório contém a implementação de um mesmo programa (sequência de Fibonacci) em três paradigmas diferentes, para demonstrar a equivalência de programas através da Máquina de Traços (MT), para a matéria de Teoria da Computabilidade, ministrada pelo Prof. Daniel Souza, do curso de Ciência de Computação no Centro Universitário do Estado do Pará (CESUPA).

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

### Fibonacci Iterativo

O arquivo `iterative/iterative.c` contém a implementação iterativa da sequência de Fibonacci utilizando estruturas de repetição convencionais (for/while).

### Fibonacci Recursivo

O arquivo `recursive/recursive.c` contém a implementação recursiva da sequência de Fibonacci utilizando chamadas recursivas.

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
- Algoritmos originais: 3
- Algoritmo modificado: 5

Isto demonstra que os programas não são equivalentes.

## Autores

- Giovanni B. S. Vasconcelos
- Cauã M. S. Nara
