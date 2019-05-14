#include <stdio.h>
#include <unistd.h>

#define PATH_SIZE 260

int main(int argc, char *argv[])
{
    int error, counter;

    if (argc < 2)
    {
        printf("remover [nome ...]\n");
        return 0;
    }

    for(counter = 1; counter < argc; counter++)
    {
        error = 0;

        error = rmdir(argv[counter]);

        if (error != 0)
        {
            printf("Falha ao deletar diretório %s!\n", argv[counter]);
            perror("Erro: ");
        }
    }

    return 0;
}
