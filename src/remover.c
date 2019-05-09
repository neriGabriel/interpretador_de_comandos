#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <locale.h>

#define PATH_SIZE 260

void limparTela()
{
    system("cls||clear");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int cliffHanger = 1, error, tamanhoNome;
    char local[PATH_SIZE];

    getcwd(local, PATH_SIZE);

    if (local != NULL)
    {
        printf("O diretório atual é: %s\n", local);
    }
    else
    {
        perror("Erro: ");
        printf("\n");
        return 1;
    }

    do
    {
        error = 0;
        tamanhoNome = 0;
        printf("Digite exit a qualquer momento para sair...\n");
        printf("Qual pasta gostaria de apagar: ");
        fflush(stdin);
        fgets(local, PATH_SIZE, stdin);

        tamanhoNome = strlen(local) - 1;

        if (local[tamanhoNome] == '\n')
        {
            local[tamanhoNome] = '\0';
        }

        if (strcmp(local, "cls") == 0 || strcmp(local, "clear") == 0)
        {
            limparTela();
            main();
        }

        if (strcmp(local, "exit") == 0)
        {
            exit(1);
        }
        else
        {
            perror("Erro: ");
            printf("\n");
        }

    } while (cliffHanger == 1);

    return 0;
}
