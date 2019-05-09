chmod -R 777 ./reset.sh

echo -e "limpando CACHE de arquivos...";

if [ -f ./app/ajuda ]
then
  rm ./app/ajuda;
fi

if [ -f ./app/arquivo ]
then
  rm ./app/arquivo;
fi

if [ -f ./app/copiar ]
then
  rm ./app/copiar;
fi

if [ -f ./app/criar ]
then
  rm ./app/criar;
fi

if [ -f ./app/data ]
then
  rm ./app/data;
fi

if [ -f ./app/listar ]
then
  rm ./app/listar;
fi

if [ -f ./app/local ]
then
  rm ./app/local;
fi

if [ -f ./app/mudar ]
then
  rm ./app/mudar;
fi

if [ -f ./app/remover ]
then
  rm ./app/remover;
fi

if [ -f ./app/dev ]
then
  rm ./app/dev;
fi

if [ -f ./app/apagar ]
then
  rm ./app/apagar;
fi

if [ -f ./app/quem ]
then
  rm ./app/quem;
fi

if [ -f ./shell ]
then
  rm ./shell;
fi

echo -e "CACHE de arquivos limpados com sucesso!";
