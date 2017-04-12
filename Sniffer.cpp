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

    //    lee flags
    myFile.read((char*) shorts, 2);
    short flag = shorts[2];
    cout << " El original flag: " << flag << endl;

    //ignora 4 bytes
    myFile.seekg(12);


    std::ostringstream src;
    src << std::hex << std::setfill('0') << std::uppercase;
    unsigned char buff[5];
    buff[4] = '\0';
    myFile.read((char*)buff, 4);
    for (int i = 0; i < 4; ++i) {
        src << std::setw(2) << static_cast<int>(buff[i]);
    }
    std::cout << "la src obtenida: " << src.str() << "\n";
    printf("src or 0x%x 0x%x 0x%x 0x%x\n", buff[0], buff[1], buff[2], buff[3]);

    int src1 = 0;


    myFile.read((char*)buff, 4);
    std::ostringstream dst;
    dst << std::hex << std::setfill('0') << std::uppercase;

    for (int i = 0; i < 4; ++i) {
        dst << std::setw(2) << static_cast<int>(buff[i]);
    }
    std::cout << "la dst obtenida: " << dst.str() << "\n";
    printf("dst or 0x%x 0x%x 0x%x 0x%x\n", buff[0], buff[1], buff[2], buff[3]);
    int dst1 = 0;




//    TODO malloc del char pointer y hacer destructor en packet
    myFile.seekg(HEADER);
    myFile.read(buffer, len-HEADER);
    cout << "el largo: " << len << endl;
    printf("buffer C: %s salteo el null y el resto: %s\n", buffer, buffer+5);
    cout << "el buffer: " << buffer << endl;
    string str(buffer);


    Packet p = Packet(id,src1,dst1);
    p.setData(str);
    string s = p.getData();
    cout << s << endl;
    this->packets.push_back(p);


    return 0;
}
