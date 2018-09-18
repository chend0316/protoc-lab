
CFLAGS = -std=gnu++11 -static-libstdc++ -pthread -I../protobuf-3.6.1/src/ -I./
LIB_PATH = ../protobuf-3.6.1/src/.libs/

.PHONY: build
build:
	g++ $(CFLAGS) main.cc c_generator.cc -o myprotoc $(LIB_PATH)/libprotoc.a $(LIB_PATH)/libprotobuf.a
