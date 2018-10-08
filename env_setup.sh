#! /bin/sh

if [ -e ./protobuf-all-3.6.1.tar.gz ]
then
    echo ".tar.gz exists, skip download"
else
    wget https://github.com/protocolbuffers/protobuf/releases/download/v3.6.1/protobuf-all-3.6.1.tar.gz
fi

if [ -e ./protobuf-3.6.1 ]
    echo "has been extract, skip"
then
    tar xf ./protobuf-all-3.6.1.tar.gz
fi

cd ./protobuf-3.6.1
sh ./autogen.sh
./configure
make
