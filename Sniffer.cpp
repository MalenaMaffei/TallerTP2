//
// Created by male on 08/04/17.
//

#include <fstream>
#include <iostream>
#include "Sniffer.h"
#include <string>
#include <vector>
#include <netinet/in.h>
#include "Packet.h"

#define HEADER 20

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;



Sniffer::Sniffer(const string &filename) : filename(filename) {
    this->filename = filename;
//    this->packets = std::vector<Packet>();
}

Sniffer::~Sniffer() {
//nada por aca
}

const vector<Packet> &Sniffer::getPackets() const {
    return packets;
}


int Sniffer::create_packets(){
    short len;
    char buffer[1000];
    short shorts[50];
    ifstream myFile;

//    string file = "tests/t1/one.cap";
//    Sniffer sniff = Sniffer(file);
    myFile.open(Sniffer::filename, ios::in | ios::binary);

    //ignora primeros dos
    myFile.seekg(2);
//lee length
    myFile.read((char*) shorts, 2);
    len = shorts[0];
    len = ntohs(len);

//    lee id
    myFile.read((char*) shorts, 2);
    short id = shorts[1];
    cout << " El original id: " << id << endl;
    id = ntohs(id);
    cout << " El convertido id : " << id << endl;

    //    lee flags
    myFile.read((char*) shorts, 2);
    short flag = shorts[2];
    cout << " El original flag: " << flag << endl;

    //ignora 4 bytes
    myFile.seekg(12);



    char buff[5];
    buff[4] = '\0';
    myFile.read(buff, 4);
    for (int i = 0; i < 4; ++i) {
        buff[i] += 48;
    }

    int src = std::stoi(buff);
    printf("src: %s y el num: %i \n", buff, src);


    myFile.read(buff, 4);
    for (int i = 0; i < 4; ++i) {
        buff[i] += 48;
    }
//    int dst = std::stoi(buff);
    int dst = 0;

    printf("dst: %s y el num: %i \n", buff, dst );


    myFile.seekg(HEADER);
    myFile.read(buffer, len-HEADER);
    cout << "el largo: " << len << endl;
    printf("buffer C: %s salteo el null y el resto: %s\n", buffer, buffer+5);
    cout << "el buffer: " << buffer << endl;
    string str(buffer);


    Packet p = Packet(id,src,dst);
    p.setData(str);
    string s = p.getData();
    cout << s << endl;
    this->packets.push_back(p);


    return 0;
}