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

  printf("\e[H\e[2J");
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

      //SAIR
      if(strcmp(argv[0], "sair") == 0) exit(0);

      //LIMPAR TELA
      if(strcmp(argv[0], "limpar") == 0) printf("\e[H\e[2J");

      //módulo de ajuda
      if(strcmp(argv[0], "ajuda") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/ajuda", "./app/ajuda", argv[1], NULL);
        else wait(NULL);
        continue;
      }

      //módulo de creditos
      if(strcmp(argv[0], "dev") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/dev", "./app/dev", argv[1], NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar diretorios
      if(strcmp(argv[0], "dev") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/dev", "./app/dev", argv[1], NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar arquivos
      if(strcmp(argv[0], "arquivo") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/arquivo", "./app/arquivo", argv[1], NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar diretorios
      if(strcmp(argv[0], "criar") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/criar", "./app/criar", argv[1], NULL);
        else wait(NULL);
        continue;
      }

      //módulo de copiar
      if (strcmp(argv[0], "copiar") == 0) {
        pid = fork();
        if(pid == 0) execlp("./app/copiar", "./app/copiar", argv[1], NULL);
        else wait(NULL);
        continue;
      }

      //módulo de listar
      if (strcmp(argv[0], "listar") == 0) {
        pid = fork();
        if(pid == 0) execlp("./app/listar", "./app/listar", argv[1], NULL);
        else wait(NULL);
        continue;
      }
   }
}
