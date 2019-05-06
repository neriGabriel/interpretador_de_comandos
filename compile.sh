#!/usr/bin/env bash
echo "COMPILANDO ARQUIVOS...."

gcc ajuda.c -o ajuda
if [ $? -eq 1 ]
then
    exit "Erro ao compilar o arquivo de ajuda!"
fi


gcc main.c -o main
if [ $? -eq 1 ]
then
    echo "Erro ao compilar o arquivo principal!"
fi

echo "ARQUIVOS COMPILADOS COM SUCESSO!"
