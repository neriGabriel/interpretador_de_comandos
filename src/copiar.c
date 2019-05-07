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

  char ch, caminho[256], destino[256];
  FILE *ori, *dest;

  printf("\e[H\e[2J");
  printf("Entre com o nome do arquivo: ");
  gets(caminho);

  if(is_file(caminho) == false ) {
    printf("Arquivo inválido ou não encontrado.\n");
    return 0;
  }

  ori = fopen(caminho, "r");

  if(ori == NULL){
    printf("Erro ao ler arquivo.\n");
    exit(EXIT_FAILURE);
	  return 0;
  }

  printf("Entre com o nome da cópia: ");
  gets(destino);

  dest = fopen(destino, "w");

  if(dest == NULL){
    printf("Erro ao copiar arquivo.\n");
    exit(EXIT_FAILURE);
	  return 0;
  }

  while( ( ch = fgetc(ori) ) != EOF )
      fputc(ch, dest);

   printf("Arquivo Copiado com sucesso\n");

   fclose(ori);
   fclose(dest);
}
