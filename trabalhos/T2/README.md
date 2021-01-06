
# T2 - Números com Threads POSIX

## Deadline

Prazo: **12/02/2021** pelo link do Google Forms (https://forms.gle/aopePU3ZwfXZbo8r9).


## Descrição

O objetivo deste trabalho é implementar um programa multithread que imprime informações estatísticas sobre uma lista de números. O programa deve ler da entrada padrão uma lista de números (máx. 100) e em seguida criar 3 threads concorrentes.

Cada uma das 3 threads tem uma função bem definida, em qualquer ordem:
- Uma thread deve calcular a média dos números
- Uma thread deve encontrar o valor máximo 
- Uma thread deve encontrar o valor mínimo

Por exemplo, digamos que os números de entrada são: `23 13 24 9 91 78`. A saída deve ser:
```
A media e: 39.6
O minimo e: 9
O maximo e: 91
```

Use variáveis globais para representar os valores de média, mínimo e máximo. Os passos que o programa deve seguir são:
- Antes de criar as threads, o programa deve ler a lista de valores digitados pelo usuário da entrada padrão (`stdin` em C ou `std::cin` em C++).
- Somente após ler os valores as threads podem ser criadas. 
- Quando as threads terminarem de calcular os valores, a thread principal pode imprimir os valores calculados.

A aula 8 descreve uma introdução sobre Threads POSIX (ver [vídeo](https://youtu.be/GAckKe92lUA) e [slides](../../aulas/08_pthreads/08_pthreads.pdf)).

## Regras

- Pode ser usado C ou C++!
- Não compila, zero.
- Plágio, zero.