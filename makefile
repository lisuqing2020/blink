target = blink
src    = $(wildcard src/*.cc)
obj	   = $(patsubst src/%.cc,build/%.o,$(src))
g++11  = g++ --std=c++11
inc    = -Iinclude
link   = -lprotobuf -lpthread -lcrypto -ljson -lmysqlclient -L./lib
output = ./build/$(target)

$(target):$(obj)
	$(g++11) $^ -o $(output) $(inc) $(link)

client:
	$(g++11) $(src) client.cc -o build/client $(inc) $(link)

server:
	$(g++11) $(src) server.cc -o build/server $(inc) $(link)

build/%.o:src/%.cc
	$(g++11) -c $< -o $@ $(inc)

.PHONY:clean
clean:
	rm -f build/*.o