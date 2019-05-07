#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main (int argc, char * argv[]){
  char user [30], pass [30], comando[30], *arg[3];
  int pid;

  printf("Entre com o usuario: ");
  gets(user);
  printf("Entre com a senha: ");
  gets(pass);

   if(strcmp(user, "root") != 0 || strcmp(pass, "fatecso") != 0 )
   {
     printf("Usuario ou senha invalidos \n");
     exit(0);
   }

   for(;;)
   {
      printf("fatec> ");
      gets(comando);
      argv[0] = strtok(comando, "");
      argv[1] = strtok(NULL, "");
      argv[2] = NULL;

      //módulo de sair
      if(strcmp(argv[0], "sair") == 0) exit(0);

      //módulo de ajuda
      if(strcmp(argv[0], "ajuda") == 0) {
        pid=fork();
        if(pid==0) {
          execlp("./ajuda", "./ajuda", argv[1], NULL);
        }
        else wait(NULL);
        continue;
      }
   }
}
