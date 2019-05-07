#include <stdio.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){
  char diretorio[4020];
  int status;
  printf("\e[H\e[2J");
  printf("Entre com o diretorio que deseja criar: ");
  gets(diretorio);

  status = mkdir(diretorio, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  if(status == 0) printf("Diretorio criado com sucesso! \n");
  else printf("Erro ao criar diretorio \n");

  return status;
}
