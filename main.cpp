//
// Created by male on 07/04/17.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include "Packet.h"
#include <fstream>

#define HEADER 20
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;

int main(){
    // printf("%s", "hola");



    short len;
    char buffer[100];
    short shorts[50];
    ifstream myFile;

    string file = "tests/t1/one.cap";
    myFile.open(file, ios::in | ios::binary);
    myFile.read((char*) shorts, 2);
    myFile.read((char*) shorts, 2);

    len = shorts[0];
    short conv = ntohs(len);
    myFile.seekg(HEADER);
    myFile.read(buffer, conv-HEADER);
    cout << "el buffer: " << buffer << endl;
    string str(buffer);

    Packet p = Packet(1,2,3);
    p.setData(str);
    string s = p.getData();
    cout << s << endl;


    cout << "El convertido: " << conv << " El original: " << len << endl;
    return 0;
}
