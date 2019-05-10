#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define TAM 255

int main(int argc, char *argv[])
{
    int error, counter;

    for(counter = 1; counter < argc; counter++)
    {
        error = 0;

        error = remove(argv[counter]);

        if (error != 0)
        {
            printf("Falha ao deletar arquivo %s!\n", argv[counter]);
            perror("Erro");
        }
    }

    return 0;
}
