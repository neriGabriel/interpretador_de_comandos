#!/usr/bin/env bash
chmod -R 777 ./reset.sh

echo -e "limpando CACHE de arquivos...";

arquivos=(ajuda apagar arquivo copiar criar data dev listar local mudar quem remover)

for i in "${arquivos[@]}"
do
  if [ -f ./app/$i ]
  then
    rm ./app/$i;
  fi
done

if [ -f ./shell ]
then
  rm ./shell;
fi

echo -e "CACHE de arquivos limpados com sucesso!";
