#!/usr/bin/env bash
echo "COMPILANDO ARQUIVOS...."

[[ -d ./app ]] && echo "DIRETORIO APP JA CRIADO" ||   mkdir ./app

./reset.sh

[[ -d ./src ]] && chmod -R 777 ./src
[[ -d ./app ]] && chmod -R 777 ./app

arquivos=(ajuda apagar arquivo copiar criar data dev listar local mudar quem remover)

for i in "${arquivos[@]}"
do
  gcc ./src/$i.c -o ./app/$i
  [[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo $i!"
done

gcc ./src/shell.c -o ./shell
[[ $? -eq 1 ]] && exit "Erro ao compilar o arquivo shell!"

chmod -R 777 ./app

echo -e "ARQUIVOS COMPILADOS COM SUCESSO!\nEXECUTANDO ARQUIVO..."
clear
./shell
