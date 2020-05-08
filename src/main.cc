#include <iostream>
#include "rsa.h"
#include "aes.h"
using namespace std;

int main(int argc, char* argv[]) {
    Aes aes("1596321785412369");

    string str = aes.Encrypt("lizhan");
    cout << str << endl;

    cout << "???\n";

    string s = aes.Decrypt(str);
    cout << s << endl;
}