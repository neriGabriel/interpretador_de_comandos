#!/usr/bin/env bash
echo "COMPILANDO ARQUIVOS...."

#=Verifica se a pasta "app" existe e, se não, cria.
app=$(./app/)
if [ ! -d "$app" ]
then
    mkdir ./app
fi

./reset.sh



chmod -R 777 ./src
chmod -R 777 ./app

#= Compilando o arquivo de ajuda
gcc ./src/ajuda.c -o ./app/ajuda
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de ajuda!"
fi
##################################

#= Compilando o arquivo de apagar
gcc ./src/apagar.c -o ./app/apagar
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de apagar!"
fi
##################################

#= Compilando o arquivo de apagar
gcc ./src/quem.c -o ./app/quem
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de quem!"
fi
##################################

#= Compilando o arquivo de copiar
gcc ./src/copiar.c -o ./app/copiar
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de copiar!"
fi
##################################

#= Compilando o arquivo de files
gcc ./src/arquivo.c -o ./app/arquivo
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de files!"
fi
##################################

#= Compilando o arquivo de créditos
gcc ./src/dev.c -o ./app/dev
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de créditos!"
fi
##################################

#= Compilando o arquivo de listar
gcc ./src/listar.c -o ./app/listar
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de listar!"
fi
##################################

#= Compilando o arquivo de criar
gcc ./src/criar.c -o ./app/criar
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de criar!"
fi
###################################


#= Compilando o arquivo de data
gcc ./src/data.c -o ./app/data
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de data!"
fi
################################

#= Compilando o arquivo de local
gcc ./src/local.c -o ./app/local
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de local!"
fi
#################################

#= Compilando o arquivo de mudar
gcc ./src/mudar.c -o ./app/mudar
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de mudar!"
fi
##################################

#= Compilando o arquivo de remover
gcc ./src/remover.c -o ./app/remover
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de remover!"
fi
###################################

#= Compilando o arquivo principal
gcc ./src/shell.c -o shell
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo principal!"
fi
#####################################

chmod -R 777 ./app
echo "ARQUIVOS COMPILADOS COM SUCESSO!"

echo "EXECUTANDO ARQUIVO...."
clear
./shell