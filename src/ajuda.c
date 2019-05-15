#include <stdio.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL,"Portuguese");
  printf("\t\t ============================================ AJUDA SHELL FATEC ============================================ \n");
  printf("\t\t ==== apagar  = rm    > Remove ARQUIVOS, apagar [arquivo1 arquivo2 ...] --------------------------------==== \n");
  printf("\t\t ==== arquivo = touch > Cria um arquivo, arquivo [nome.<extensão>] -------------------------------------==== \n");
  printf("\t\t ==== copiar  = cp    > Copia arquivo(s), copiar [<nomeFonte nomeDestino> <nomeFonte nomeDestino> ...] -==== \n");
  printf("\t\t ==== criar   = mkdir > Cria diretório(s) caso não existam, criar [pasta1 pasta2 ...] ------------------==== \n");
  printf("\t\t ==== data    = date  > Mostra a data, [data {-s, -v, -a}]  --------------------------------------------==== \n");
  printf("\t\t ==== dev     = devs  > Créditos da equipe, [dev] ------------------------------------------------------==== \n");
  printf("\t\t ==== listar  = ls    > Lista os conteúdos da pasta atual, [listar] ------------------------------------==== \n");
  printf("\t\t ==== local   = pwd   > Exibe o diretório atual, [local] -----------------------------------------------==== \n");
  printf("\t\t ==== mudar   = cd    > Muda o diretório atual para o escolhido, [mudar] -------------------------------==== \n");
  printf("\t\t ==== usuario = who   > Exibe o(s) usuários logados, [usuario] -----------------------------------------==== \n");
  printf("\t\t ==== remover = rmdir > Remove diretórios VAZIOS, remover [pasta1 pasta2 ...] --------------------------==== \n");
  printf("\t\t ==== ./      = ./ -------------------------------------------------------------------------------------==== \n");
  printf("\t\t =========================================================================================================== \n");
  return 0;
}
