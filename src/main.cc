#include <iostream>
#include "factory.h"
using namespace std;

int main(int argc, char* argv[]) {
    RequestMessage reqmes;
    reqmes.set_type_(1);
    reqmes.set_client_("a");
    reqmes.set_server_("b");
    reqmes.set_sign_("c");
    reqmes.set_data_("d");

    Factory* fac = new RequestFactory(reqmes);
    Codec* cc = fac->CreateCodec();
    
    string str = cc->EncodeMessage();
    cout << str << endl;

    RequestMessage* reqmes1 = (RequestMessage*)cc->DecodeMessage();
    cout << reqmes1->type_() << " " << reqmes1->client_() << " " << reqmes1->server_() << " " << reqmes1->sign_() << " " << reqmes1->data_() << endl;
}