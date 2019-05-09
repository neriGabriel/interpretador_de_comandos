#include <stdio.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char * argv[]){

  if(argc < 2){
    printf("mudar [nome]\n");
    return 0;
  }

  int ret;
  ret = chdir(argv[1]);

  if(ret != 0){
	  perror("chdir() error()");
    printf("Erro ao acessar diretorio, verifique o caminho apontado.\n");
  }else printf("'%s'\n", argv[1]);

}
