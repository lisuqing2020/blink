# blink

## dependency

### [protobuf](https://github.com/protocolbuffers/protobuf/releases)
- protobuf:3.8.0
```shell
$ ./configure
$ make
$ make install
$ ldconfig #如果提示找不到动态库，尝试使用该指令
```

### [openssl](https://www.openssl.org/source/)
- openssl:1.1.1
```shell
$ ./config
$ make
$ make install
$ ldconfig #如果提示找不到动态库，尝试使用该指令
```

### [scons](https://github.com/SCons/scons/releases) -> [jsoncpp](https://github.com/open-source-parsers/jsoncpp)
- scons:3.0.5
- jsoncpp:0.10.7
```shell
[scons]$ python setup.py install
[jsoncpp]$ scons platform=linux-gcc
[jsoncpp]$ cp libs/linux-gcc-*/* /lib
[jsoncpp]$ cp include/json/ /usr/include/ -r
[jsoncpp]$ ln -s /lib/libjson_linux-gcc-*_libmt.so /lib/libjson.so
[jsoncpp]$ ldconfig
# 测试是否安装成功
[jsoncpp]$ ./bin/linux-gcc-4.8.5/test_lib_json
``` 