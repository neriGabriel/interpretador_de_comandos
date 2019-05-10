#!/usr/bin/env bash
echo "COMPILANDO ARQUIVOS...."

[[ -d ./app ]] && echo "DIRETORIO APP JA CRIADO" ||   mkdir ./app

./reset.sh

[[ -d ./src ]] && chmod -R 777 ./src
[[ -d ./app ]] && chmod -R 777 ./app

gcc ./src/ajuda.c -o ./app/ajuda
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de ajuda!"

gcc ./src/apagar.c -o ./app/apagar
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de apagar!"

gcc ./src/quem.c -o ./app/quem
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de usuario!"

gcc ./src/copiar.c -o ./app/copiar
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de copiar!"

gcc ./src/arquivo.c -o ./app/arquivo
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de arquivo!"

gcc ./src/dev.c -o ./app/dev
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de creditos!"

gcc ./src/listar.c -o ./app/listar
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de listar!"

gcc ./src/criar.c -o ./app/criar
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de criar!"

gcc ./src/data.c -o ./app/data
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de data!"

gcc ./src/local.c -o ./app/local
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de local!"

gcc ./src/mudar.c -o ./app/mudar
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de mudar!"

gcc ./src/remover.c -o ./app/remover
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo de remover!"

gcc ./src/shell.c -o ./shell
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo principal!"

chmod -R 777 ./app
echo "ARQUIVOS COMPILADOS COM SUCESSO!"

echo "EXECUTANDO ARQUIVO...."
clear
./shell
