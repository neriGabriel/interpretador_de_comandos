#include <stdio.h>
#include <unistd.h>

#define TAM 255

int main(int argc, char *argv[])
{
    int error, counter;

    if (argc < 2)
    {
        printf("apagar [nome ...]\n");
        return 0;
    }

    for(counter = 1; counter < argc; counter++)
    {
        error = 0;

        error = remove(argv[counter]);

        if (error != 0)
        {
            printf("Falha ao deletar arquivo %s!\n", argv[counter]);
            perror("Erro: ");
        }
    }

    return 0;
}
