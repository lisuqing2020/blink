target = blink
src    = $(wildcard src/*.cc)
obj	   = $(patsubst src/%.cc,build/%.o,$(src))
g++11  = g++ --std=c++11
inc    = -Iinclude
link   = -lprotobuf -lpthread -lcrypto -ljson
output = ./build/$(target)

$(target):$(obj)
	$(g++11) $^ -o $(output) $(inc) $(link)

build/%.o:src/%.cc
	$(g++11) -c $< -o $@ $(inc)

.PHONY:clean
clean:
	rm -f $(obj) $(output)