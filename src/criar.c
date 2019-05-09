#include <stdio.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char * argv[]){
  int status;

  if(argc < 2){
    printf("criar [nome]\n");
    return 0;
  }
  status = mkdir(argv[1], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  if(status == 1) printf("Erro ao criar diretorio \n");

  return status;
}
