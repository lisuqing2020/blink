#include <iostream>
#include "request.h"
using namespace std;

int main(int argc, char* argv[]) {
    RequestCodec reqcc(1, "a", "b", "c", "d");
    Codec& cc = reqcc;
    string str = cc.EncodeMessage();
    cout << str << endl;

    RequestMessage* reqmes = (RequestMessage*)cc.DecodeMessage();
    cout << reqmes->type_() << " " << reqmes->client_() << " " << reqmes->server_() << " " << reqmes->sign_() << " " << reqmes->data_() << endl;
}