#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <locale.h>

#define PASS_SIZE 30
#define USER_SIZE 30
#define COMANDO_SIZE 30

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

void getCredentials(char user[USER_SIZE], char pass[PASS_SIZE])
{
  int SIZE = 0;

  printf("Entre com o usuário: ");
  fgets(user, USER_SIZE, stdin);
  fflush(stdin);

  SIZE = strlen(user) - 1;

  if (user[SIZE] == '\n')
      user[SIZE] = '\0';

  printf("Entre com a senha: ");
  fgets(pass, PASS_SIZE, stdin);
  fflush(stdin);

  SIZE = strlen(pass);

  if (pass[SIZE] == '\n')
      pass[SIZE] = '\0';

}

int main (int argc, char * argv[]){
  char user [USER_SIZE], pass [PASS_SIZE], comando[COMANDO_SIZE];
  int pid, i = 0;

  setlocale (LC_ALL, "Portuguese");

  printf("\e[H\e[2J");

  for(i = 0; i <= 2; i++)
  {

    getCredentials(user, pass);

    printf("%s\n%s", user, pass);

    if(i == 2)
    {
      printf("Excedeu a quantidade de tentativas\n\n");
      exit(0);
    }
    else if (strcmp(user, "root") != 0 || strcmp(pass, "fatecso") != 0 )
    {
      printf("Usuário ou senha inválidos\n\n");
    }
    else
    {
      continue;
    }
  }

   for(;;)
   {
      printf("fatec> ");
      gets(comando);

      makeTokens(comando);


      argv[0] = strtok(comando, "");

      //SAIR
      if(strcmp(argv[0], "sair") == 0) exit(0);

      //LIMPAR TELA
      if(strcmp(argv[0], "limpar") == 0) printf("\e[H\e[2J");

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
        if(pid == 0) execlp("./app/copiar", "./app/copiar", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar diretorios
      if(strcmp(argv[0], "criar") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/criar", "./app/criar", array, NULL);
        else wait(NULL);
        continue;
      }

      //módulo de criar diretorios
      if(strcmp(argv[0], "data") == 0) {
        pid=fork();
        if(pid==0) execlp("./app/data", "./app/data", array, NULL);
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
        if(pid == 0) execlp("./app/listar", "./app/listar", array, NULL);
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
        if(pid == 0) execlp("./app/local", "./app/mudar", argv[1], NULL);
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
