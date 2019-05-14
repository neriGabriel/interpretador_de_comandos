#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <locale.h>

#define PASS_SIZE 30
#define USER_SIZE 30
#define COMANDO_SIZE 30
#define HOST_SIZE 1024
#define PATH_SIZE 260

char *token, *array[512];

void limpaTela()
{
    printf("\e[H\e[2J");
}

void makeTokens(char *input)
{
    int i = 0;
    token = strtok(input, "\n ");
    while (token != NULL)
    {
        array[i++] = token;
        token = strtok(NULL, "\n ");
    }
    array[i] = NULL;
}

char getCredentials(char user[USER_SIZE], char pass[PASS_SIZE])
{
    int SIZE = 0, i = 0;

    for(i = 0; i <= 2; i++)
    {

        printf("Entre com o usuário: ");
        fgets(user, USER_SIZE, stdin);
        fflush(stdin);

        SIZE = strlen(user) - 1;

        if (user[SIZE] == '\n')
        {
            user[SIZE] = '\0';
        }

        printf("Entre com a senha: ");
        fgets(pass, PASS_SIZE, stdin);
        fflush(stdin);

        SIZE = strlen(pass) - 1;

        if (pass[SIZE] == '\n')
        {
            pass[SIZE] = '\0';
        }

        if(i == 2)
        {
            printf("Excedeu a quantidade de tentativas\n\n");
            exit(0);
        }
        if (strcmp(user, "root") != 0 || strcmp(pass, "fatecso") != 0)
        {
            printf("Usuário ou senha inválidos\n\n");
        }
        else
        {
            break;
        }
    }

    return user, pass;
}

int main (int argc, char * argv[])
{

    char user [USER_SIZE], pass [PASS_SIZE], comando[COMANDO_SIZE], hostName[HOST_SIZE];
    int pid, i = 0;

    setlocale (LC_ALL, "Portuguese");

    limpaTela();

    getCredentials(user, pass);

    limpaTela();

    printf("Seja bem vindo %s!\n", user);

    fflush(stdin);

    for(;;)
    {
        printf("FATEC>");
        fgets(comando, COMANDO_SIZE, stdin);
        fflush(stdin);

        argv[0] = strtok(comando, "");

        printf("%s", comando);

        makeTokens(comando);

        if(strcmp(argv[0], "sair") == 0)
        {
            printf("Até mais %s =)\n", user);
            exit(0);
        }

        else if(strcmp(argv[0], "limpar") == 0 || strcmp(argv[0], "clear") == 0) limpaTela();

        else if(strcmp(argv[0], "ajuda") == 0)
        {
            pid=fork();
            if(pid==0) execvp("./app/ajuda", array);
            else wait(NULL);
            continue;
        }

        else if(strcmp(argv[0], "apagar") == 0)
        {
            pid=fork();
            if(pid==0) execvp("./app/apagar", array);
            else wait(NULL);
            continue;
        }

        //TODO Corrigir bug que, apesar de criar mais de um arquivo conforme solicitado, mostra "comando: '\n' não encontrado" onde '\n' é um enter entre os nomes dos arquivos por criar. 
        else if(strcmp(argv[0], "arquivo") == 0)
        {
            pid=fork();
            if(pid==0) execvp("./app/arquivo", array);
            else wait(NULL);
            continue;
        }

        else if (strcmp(argv[0], "copiar") == 0)
        {
            pid = fork();
            if(pid==0) execvp("./app/copiar", array);
            else wait(NULL);
            continue;
        }

        else if(strcmp(argv[0], "criar") == 0)
        {
            pid=fork();
            if(pid==0) execvp("./app/criar", array);
            else wait(NULL);
            continue;
        }

        else if(strcmp(argv[0], "data") == 0)
        {
            pid=fork();
            if(pid==0) execvp("./app/data", array);
            else wait(NULL);
            continue;
        }

        else if(strcmp(argv[0], "dev") == 0)
        {
            pid=fork();
            if(pid==0) execlp("./app/dev", "./app/dev", array, NULL);
            else wait(NULL);
            continue;
        }

        else if (strcmp(argv[0], "listar") == 0)
        {
            pid = fork();
            if(pid==0) execvp("./app/listar", array);
            else wait(NULL);
            continue;
        }

        else if (strcmp(argv[0], "local") == 0)
        {
            pid = fork();
            if(pid == 0) execlp("./app/local", "./app/local", array, NULL);
            else wait(NULL);
            continue;
        }

        else if (strcmp(argv[0], "mudar") == 0)
        {
            pid = fork();
            if(pid==0) execvp("./app/mudar", array);
            else wait(NULL);
            continue;
        }

        else if (strcmp(argv[0], "usuario") == 0)
        {
            pid = fork();
            if(pid==0) execvp("./app/quem", array);
            else wait(NULL);
            continue;
        }

        else if(strcmp(argv[0], "remover") == 0)
        {
            pid=fork();
            if(pid==0) execvp("./app/remover", array);
            else wait(NULL);
            continue;
        }

        else if(comando[0] == '.' && comando[1] == '/')
        {
            system(comando);
            continue;
        }

        else printf("comando: %s nao encontrado\n", comando);
    }
}
