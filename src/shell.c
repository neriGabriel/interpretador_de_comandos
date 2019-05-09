#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

char *token, *array[512];

void makeTokens(char *input){
   int i = 0;
		token = strtok(input, "\n ");
			while (token != NULL) {
				array[i++] = token;
				token = strtok(NULL, "\n ");
			}
		array[i] = NULL;
}

int main (int argc, char * argv[]){
  char user [30], pass [30], comando[30];
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

      makeTokens(comando);


      argv[0] = strtok(comando, "");

      //SAIR
      if(strcmp(argv[0], "sair") == 0) {
        printf("Até mais =)\n");
        exit(0);
      }

      //LIMPAR TELA
      if(strcmp(argv[0], "limpar") == 0 || strcmp(argv[0], "clear") == 0) printf("\e[H\e[2J");

      //módulo de ajuda
      if(strcmp(argv[0], "ajuda") == 0) {
        pid=fork();
        if(pid==0) execvp("./app/ajuda", array);
        else wait(NULL);
        continue;
      }

      //módulo de apagar
      if(strcmp(argv[0], "apagar") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/apagar", "./app/apagar", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar arquivos
      if(strcmp(argv[0], "arquivo") == 0) {
        pid=fork();
        if(pid==0) execvp("./app/arquivo", array);
        //if(pid==0) execlp("./app/arquivo", "./app/arquivo", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de copiar
      if (strcmp(argv[0], "copiar") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/copiar", array);
        //if(pid == 0) execlp("./app/copiar", "./app/copiar", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar diretorios
      if(strcmp(argv[0], "criar") == 0) {
        pid=fork();
        if(pid==0) execvp("./app/criar", array);
        //if(pid==0) execlp("./app/criar", "./app/criar", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar diretorios
      if(strcmp(argv[0], "data") == 0) {
        pid=fork();
        //if(pid==0) execlp("./app/data", "./app/data", array, NULL);
        if(pid==0) execvp("./app/data", array);
        else wait(NULL);
        continue;
      }

      //módulo de creditos
      if(strcmp(argv[0], "dev") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/dev", "./app/dev", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de listar
      if (strcmp(argv[0], "listar") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/listar", array);
        //if(pid == 0) execlp("./app/listar", "./app/listar", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de listar
      if (strcmp(argv[0], "local") == 0) {
        pid = fork();
        if(pid == 0) execlp("./app/local", "./app/local", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de listar
      if (strcmp(argv[0], "mudar") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/mudar", array);
        //if(pid == 0) execlp("./app/local", "./app/mudar", argv[1], NULL);
        else wait(NULL);
        continue;
      }

      //módulo de listar
      if (strcmp(argv[0], "usuario") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/quem", array);
        else wait(NULL);
        continue;
      }


      //módulo de remover
      if(strcmp(argv[0], "remover") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/remover", "./app/remover", array, NULL);
        //if(pid==0) execvp("./app/remover", array);
        else wait(NULL);
        continue;
      }


   }
}
