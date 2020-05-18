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

tcps:
	$(g++11) tcps.cc src/shm_key.cc src/shm.cc src/aes.cc src/tcp_server.cc src/tcp_socket.cc -o build/tcps -I./include -ljson -lcrypto

tcpc:
	$(g++11) tcpc.cc src/shm_key.cc src/shm.cc src/aes.cc src/tcp_server.cc src/tcp_socket.cc -o build/tcpc -I./include -ljson -lcrypto

build/%.o:src/%.cc
	$(g++11) -c $< -o $@ $(inc)

.PHONY:clean
clean:
	rm -f build/*.o