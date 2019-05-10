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
        if ((error = rmdir(argv[counter])) != 0)
        {
            perror("Erro: ");
            printf("\n");
        }
    }

    return 0;
}
