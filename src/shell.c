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

void limpaTela(){printf("\e[H\e[2J");}

int main (int argc, char * argv[]){
  char user [30], pass [30], comando[30], *name;
  int pid;

  limpaTela();

  printf("Entre com o usuario: ");
  gets(user);
  printf("Entre com a senha: ");
  gets(pass);

   if(strcmp(user, "root") != 0 || strcmp(pass, "fatecso") != 0 )
   {
     printf("Usuario ou senha invalidos \n");
     return 0;
   }
   limpaTela();

   name = getlogin();
   printf("Seja bem vindo %s!\n", name);

   for(;;)
   {
      printf("fatec> ");
      gets(comando);

      makeTokens(comando);

      argv[0] = strtok(comando, "");

      if(strcmp(argv[0], "sair") == 0) {
        printf("Até mais %s =)\n", name);
        exit(0);
      }

      else if(strcmp(argv[0], "limpar") == 0 || strcmp(argv[0], "clear") == 0) printf("\e[H\e[2J");

      else if(strcmp(argv[0], "ajuda") == 0) {
        pid=fork();
        if(pid==0) execvp("./app/ajuda", array);
        else wait(NULL);
        continue;
      }

      else if(strcmp(argv[0], "apagar") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/apagar", "./app/apagar", array, NULL);
        else wait(NULL);
        continue;
      }

      else if(strcmp(argv[0], "arquivo") == 0) {
        pid=fork();
        if(pid==0) execvp("./app/arquivo", array);
        else wait(NULL);
        continue;
      }

      else if (strcmp(argv[0], "copiar") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/copiar", array);
        else wait(NULL);
        continue;
      }

      else if(strcmp(argv[0], "criar") == 0) {
        pid=fork();
        if(pid==0) execvp("./app/criar", array);
        else wait(NULL);
        continue;
      }

      else if(strcmp(argv[0], "data") == 0) {
        pid=fork();
        if(pid==0) execvp("./app/data", array);
        else wait(NULL);
        continue;
      }

      else if(strcmp(argv[0], "dev") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/dev", "./app/dev", array, NULL);
        else wait(NULL);
        continue;
      }

      else if (strcmp(argv[0], "listar") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/listar", array);
        else wait(NULL);
        continue;
      }

      else if (strcmp(argv[0], "local") == 0) {
        pid = fork();
        if(pid == 0) execlp("./app/local", "./app/local", array, NULL);
        else wait(NULL);
        continue;
      }

      else if (strcmp(argv[0], "mudar") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/mudar", array);
        else wait(NULL);
        continue;
      }

      else if (strcmp(argv[0], "usuario") == 0) {
        pid = fork();
        if(pid==0) execvp("./app/quem", array);
        else wait(NULL);
        continue;
      }

      else if(strcmp(argv[0], "remover") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/remover", "./app/remover", array, NULL);
        else wait(NULL);
        continue;
      }

      else if(comando[0] == '.' && comando[1] == '/') {
        system(comando);
        continue;
      }

      else printf("comando: %s nao encontrado\n", comando);
   }
}
