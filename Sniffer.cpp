//
// Created by male on 08/04/17.
//
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <string>

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
    char buffer[1026];
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

    //    lee offset
    unsigned char fo[2];
    myFile.read((char*) fo, 2);
    unsigned char flag = fo[0];
    // flag parece estar bien, re chequear despues
    printf("\nEl orig flag 0x%x\n",flag);
    flag <<= 2;
    flag >>= 7;
    printf("El shift flag 0x%x\n",flag);
    printf("\nEl orig off 0x%x 0x%x\n",fo[0], fo[1]);
    fo[0] <<= 3;
    fo[0] >>= 3;
    printf("El shift off 0x%x 0x%x\n",fo[0], fo[1]);
    //ignora 4 bytes
    myFile.seekg(12);


    std::ostringstream src;
    src << std::hex << std::setfill('0');
    unsigned char buff[5];
    buff[4] = '\0';
    myFile.read((char*)buff, 4);
    for (int i = 0; i < 4; ++i) {
        src << std::setw(2) << static_cast<int>(buff[i]);
    }
    std::cout << "\nla src obtenida: " << src.str() << "\n";
    printf("src or 0x%x 0x%x 0x%x 0x%x\n", buff[0], buff[1], buff[2], buff[3]);

    int src1 = 0;


    myFile.read((char*)buff, 4);
    std::ostringstream dst;
    dst << std::hex << std::setfill('0');

    for (int i = 0; i < 4; ++i) {
        dst << std::setw(2) << static_cast<int>(buff[i]);
    }
    std::cout << "\nla dst obtenida: " << dst.str() << "\n";
    printf("dst or 0x%x 0x%x 0x%x 0x%x\n", buff[0], buff[1], buff[2], buff[3]);
    int dst1 = 0;


    myFile.seekg(HEADER);
    myFile.read(buffer, len-HEADER);
    cout << "\nel largo: " << len << endl;
    printf("\nbuffer C: %s salteo el null y el resto: %s\n", buffer, buffer+5);
    cout << "el buffer: " << buffer << endl;

    std::ostringstream data;
    data << std::hex << std::setfill('0');
    for (int i = 0; i < len-HEADER; ++i) {
        data << std::setw(2) << static_cast<int>(buffer[i]);
    }
    string str = data.str();
    cout << "\ndata leida: " << str <<endl;

    Packet p = Packet(id,src1,dst1);
    p.setData(str);
    string s = p.getData();
    cout << s << endl;
    this->packets.push_back(p);


    return 0;
}
