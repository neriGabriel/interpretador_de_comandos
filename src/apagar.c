#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 255

void limparTela()
{

    system("cls||clear");
}

int main()
{
    int error, tamanhoNome, cliffHanger = 1;
    char nomeArquivo[TAM];

    setlocale(LC_ALL, "Portuguese");

    do
    {
        tamanhoNome = 0;
        error = 0;
        printf("Digite exit a qualquer momento para sair...\n");
        printf("Qual o nome do arquivo (Com extensão) que gostaria de deletar? ");
        fflush(stdin);
        fgets(nomeArquivo, TAM, stdin);
        tamanhoNome = strlen(nomeArquivo) - 1;

        if (nomeArquivo[tamanhoNome] == '\n')
        {
            nomeArquivo[tamanhoNome] = '\0';
        }

        if (strcmp(nomeArquivo, "cls") == 0 || strcmp(nomeArquivo, "clear") == 0)
        {
            limparTela();
            main();
        }
        else if (strcmp(nomeArquivo, "exit") == 0)
        {
            exit(1);
        }

        error = remove(nomeArquivo);

        else
        {
            printf("Falha ao deletar arquivo!\n");
            perror("Erro");
        }

        printf("\n");

    } while (cliffHanger == 1);

    return 0;
}
