#include <iostream>
#include "rsa.h"
using namespace std;

int main(int argc, char* argv[]) {
    Rsa rsa(2048);

    string ret = rsa.PriEncrypt("hello world!");
    cout << ret << endl;

    string data = rsa.PubDecrypt(ret);
    cout << data << endl;
}