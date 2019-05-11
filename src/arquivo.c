#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        printf("arquivo [nome.<extensão>]\n");
        return 0;
    }

    FILE *criarArquivo;
    criarArquivo = fopen(argv[1], "a");
    fclose(criarArquivo);
    if(criarArquivo == NULL) printf("Erro ao criar arquivo!\n");

    return 0;
}