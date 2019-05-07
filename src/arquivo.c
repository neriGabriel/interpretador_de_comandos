#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  char nome[256];
  FILE *criarArquivo;
  printf("\e[H\e[2J");

  printf("Digite o nome do arquivo: ");
  gets(nome);

  criarArquivo = fopen(nome, "a");
  fclose(criarArquivo);
  if(criarArquivo == NULL) printf("Erro ao criar arquivo!\n");
  else printf("O arquivo foi criado com sucesso!\n");

  return(0);
}
