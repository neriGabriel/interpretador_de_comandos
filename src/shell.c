#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main (int argc, char * argv[]){
  char user [30];
  char pass [30];

  printf("Entre com o usuario: ");
  gets(user);
  printf("Entre com a senha: ");
  gets(pass);

   if(strcmp(user, "root") != 0 || strcmp(pass, "fatecso") != 0 ){
     printf("Usuario ou senha invalidos \n");
     exit(0);
   }
}
