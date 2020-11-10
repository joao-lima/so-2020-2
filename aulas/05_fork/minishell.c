#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
  pid_t pid;     // PID do processo
  char *args[2]; // argumentos do comando

  args[0] = "/usr/bin/ls"; // comando cat
  args[1] = ".";  // nome do arquivo
  args[2] = NULL;       // terminou argumentos

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
      // Eu sou pai: espera qualquer filho 
      wait(NULL);
      break;
  }

  return 0;
}