
CFLAGS = -std=gnu++11 -static-libstdc++ -pthread -I../protobuf-3.6.1/src/ -I./
LIB_PATH = ../protobuf-3.6.1/src/.libs/

.PHONY: build
protoc-hi: main.cc hi_generator.cc hi_generator.h
	g++ $(CFLAGS) main.cc hi_generator.cc -o protoc-hi $(LIB_PATH)/libprotoc.a $(LIB_PATH)/libprotobuf.a

.PHONY: clean
clean:
	rm protoc-hi
