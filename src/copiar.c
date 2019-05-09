#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

//função que valida se e um arquivo válido e se foi encontrado
bool is_file(const char* path){
  struct stat buf;
  stat(path, &buf);
  return S_ISREG(buf.st_mode);
}

int main (int argc, char * argv[]) {
  if(argc < 3){
    printf("copiar [arquivo] [novo arquivo]\n");
    return 0;
  }

  char ch;
  FILE *ori, *dest;

  if(is_file(argv[1]) == false ) {
    printf("Arquivo inválido ou não encontrado.\n");
    return 0;
  }

  ori = fopen(argv[1], "r");

  if(ori == NULL){
    printf("Erro ao ler arquivo.\n");
    exit(EXIT_FAILURE);
	  return 0;
  }

  dest = fopen(argv[2], "w");

  if(dest == NULL){
    printf("Erro ao copiar arquivo.\n");
    exit(EXIT_FAILURE);
	  return 0;
  }

  while( ( ch = fgetc(ori) ) != EOF )
      fputc(ch, dest);
      
   fclose(ori);
   fclose(dest);
}
