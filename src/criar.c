#include <stdio.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char * argv[]){
  int status, i = 0;

  if(argc < 2){
    printf("criar [nome]\n");
    return 0;
  }


  for(i = 1; i <= argc; i++){
  status = mkdir(argv[i], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    if(status == 1) {
        printf("Erro ao criar diretorio \n");
        return 0;
    }
  }

  return status;
}
