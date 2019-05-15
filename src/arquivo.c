#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int counter;
    if(argc < 2)
    {
        printf("arquivo [nome.<extensão>]\n");
        return 0;
    }

    for (counter = 1; counter < argc; counter++)
    {
        FILE *criarArquivo;
        criarArquivo = fopen(argv[counter], "a");
        fclose(criarArquivo);
        if(criarArquivo == NULL) { printf("Erro ao criar arquivo!\n"); return 0;}
    }

    return 0;
}
