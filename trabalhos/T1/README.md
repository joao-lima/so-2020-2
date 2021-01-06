
# T1 - Micro Shell

## Deadline

Prazo: **12/02/2021** pelo link do Google Forms (https://forms.gle/3M4dH3hKWpk5CktE7).


## Descrição

O objetivo deste trabalho é implementar um micro shell para sistemas Linux chamado `msh`. O shell deve pedir comandos do usuário com o caracter:
```
msh>
```
O Micro Shell deve suportar apenas comandos. Os comandos a ser desenvolvimentos:
- **dir**: chama o comando listar (`/bin/ls`). 
- **pausa**: tem como argumento um número que é o tempo segundos que deve esperar antes de continuar. Deve-se utilizar a função `sleep()`.
- **executa**: recebe como argumento o caminho *completo* do programa a ser executado. Os comandos serão simples, ou seja, eles não tem argumentos adicionais.
- **sair**: termina o programa com a função `exit()`.


As principais funções de sistema necessárias são `fork()`, `execve()` e `wait()`. A chamada `fork()`
simplesmente cria um clone do processo atual e ambos (pai e filho) contiuam a execução a partir da chamada de sistema. `execve()` carrega um novo programa no espaço de memória do processo, e `wait()` espera o término de um processo filho previamente criado.

Veja o código abaixo para a criação de processo do comando `cat`:
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
  pid_t pid;     // PID do processo
  char *args[2]; // argumentos do comando

  args[0] = "/bin/cat"; // comando cat
  args[1] = "ola.txt";  // nome do arquivo
  args[2] = NULL;       // ultimo argumento tem que ser NULL

  pid = fork();
  switch(pid)
  {
    case -1:
      printf("Erro!\n");
      exit(EXIT_FAILURE);
    case 0:
      // Sou o filho
      execve(args[0], args, NULL);
      break;
    default:
      // Eu sou pai: espera o filho 
      wait(NULL);
      break;
  }

  return 0;
}
```

## Exemplos

Veja abaixo alguns exemplos de comandos do Micro Shell e resultados esperados:
```
msh> dir
a.txt b.txt msh msh.c
msh> pausa 2
dormindo 2 segundos ...
msh> executa /usr/bin/date
qua jan  6 09:41:41 -03 2021
msh> pausa 1
dormindo 1 segundos ...
msh> executa /usr/bin/pwd
/home/jvlima/so2020-2
msh> sair
```

## Regras

- Pode ser usado C ou C++!
- Não compila, zero.
- Plágio, zero.