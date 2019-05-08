@ECHO off

echo "COMPILANDO ARQUIVOS..."

::Compilando o arquivo de ajuda
gcc ./src/ajuda.c -o ./app/ajuda
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar ajuda"
    exit
)
::#############################

::Compilando o arquivo de apagar
gcc ./src/apagar.c -o ./app/apagar
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar apagar"
    exit
)
::#############################

::Compilando o arquivo de arquivo
gcc ./src/arquivo.c -o ./app/arquivo
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar arquivo"
    exit
)
::#############################

::Compilando o arquivo de copiar
gcc ./src/copiar.c -o ./app/copiar
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar copiar"
    exit
)
::#############################

::Compilando o arquivo de criar
gcc ./src/criar.c -o ./app/criar
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar criar"
    exit
)
::#############################

::Compilando o arquivo de data
gcc ./src/data.c -o ./app/data
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar data"
    exit
)
::#############################

::Compilando o arquivo de dev
gcc ./src/dev.c -o ./app/dev
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar dev"
    exit
)
::#############################

::Compilando o arquivo de listar
gcc ./src/listar.c -o ./app/listar
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar listar"
    exit
)
::#############################

::Compilando o arquivo de local
gcc ./src/local.c -o ./app/local
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar local"
    exit
)
::#############################

::Compilando o arquivo de mudar
gcc ./src/mudar.c -o ./app/mudar
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar mudar"
    exit
)
::#############################

::Compilando o arquivo de remover
gcc ./src/remover.c -o ./app/remover
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar remover"
    exit
)
::#############################

::Compilando o arquivo de shell
gcc ./src/shell.c -o ./app/shell
if %ERRORLEVEL%==1 (
    echo "Falha ao compilar shell"
    exit
)
::#############################

echo ("Arquivo compilado com sucesso.")