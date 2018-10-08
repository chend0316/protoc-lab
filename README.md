
Recomend do this lab on Ubuntu 18.04

## quick start

### setup environment dependences

```
apt-get install libtool g++
sh ./env_setup.sh  # this will take a long time
```

### start lab1

```
cd ./lab1
make
```

### test

```
./protoc-hi --hi_out=./ ./test/person.proto
cat ./test/person.txt
```
