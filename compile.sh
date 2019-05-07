#!/usr/bin/env bash
echo "COMPILANDO ARQUIVOS...."

chmod -R 777 ./src
chmod -R 777 ./app

gcc ./src/ajuda.c -o ./app/ajuda
# $? -> pega o resultado do ultimo comando executado [ 0 = sucesso , 1 = erro]
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de ajuda!"
fi


gcc ./src/shell.c -o ./app/shell
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo principal!"
fi


chmod -R 777 ./app
echo "ARQUIVOS COMPILADOS COM SUCESSO!"
