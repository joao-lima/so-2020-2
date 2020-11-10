
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
  pid_t pid;     // PID do processo
  
  pid = fork();

  // testa erros
  if( pid == -1 ){
    printf("Erro!\n");
    exit(EXIT_FAILURE);
  }

  if( pid == 0 ){
    // Sou o filho
    printf( "Sou o filho!! Meu PID: %d\n", (int)getpid() );
  } else {
    // Eu sou pai: espera o filho 
    printf( "Eu sou seu pai %d !! Meu PID: %d\n", (int)pid, (int)getpid() );
    waitpid( pid, NULL, 0 );
  }

  return 0;
}