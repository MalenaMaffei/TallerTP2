#include <iostream>
#include <sstream>
#include <iomanip>

#include <fstream>
#include "Sniffer.h"
#include <netinet/in.h>

#define HEADER 20

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;

Sniffer::Sniffer(const string &filename, vector<Packet> &packets) : filename(filename), packets(packets) {
    this->filename = filename;
    this->packets = packets;
}

Sniffer::~Sniffer() {
//nada por aca
}

string hex_converter(unsigned char* buffer, size_t len){
    std::ostringstream dst;
    dst << std::hex << std::setfill('0');
    for (size_t i = 0; i < len; ++i) {
        dst << std::setw(2) << static_cast<int>(buffer[i]);
        if (i<len-1){ dst << " ";}
    }
    string dst1 = dst.str();
//    std::cout << "\nhex obtenido: " << dst1 << "\n";
    return dst1;
}

int Sniffer::create_packets(){
    short len;
    unsigned char buffer[1026];
    short shorts[50];
    ifstream myFile;

    myFile.open(Sniffer::filename, ios::in | ios::binary);

    //ignora primeros dos
    myFile.seekg(2);
//lee length

    myFile.read((char*) shorts, 2);
    len = shorts[0];
    len = ntohs(len);

//    lee id
    unsigned char id_buff[2];
    myFile.read((char*) id_buff, 2);
    string id = hex_converter(id_buff, 2);
//    printf("id original: %x %x\n", id_buff[0], id_buff[1]);


    //    lee offset
    unsigned char fo[2];
    myFile.read((char*) fo, 2);
    // fo[0] = 0xaa;
    // fo[1] = 0xaa;
    unsigned char flag = fo[0];
    // flag parece estar bien, re chequear despues
//    printf("\nEl orig flag 0x%x\n",flag);
    flag <<= 2;
    flag >>= 7;
//    printf("El shift flag 0x%x\n",flag);
//    printf("\nEl orig off 0x%x 0x%x\n",fo[0], fo[1]);
    fo[0] <<= 3;
    fo[0] >>= 3;
//    printf("El shift off 0x%x 0x%x\n",fo[0], fo[1]);

    short* offset_ptr = (short*) fo;
    short offset = *offset_ptr;
    offset = ntohs(offset);
//    cout << "offset guardado: " << offset << endl;
        //ignora 4 bytes
    myFile.seekg(12);


    unsigned char buff[5];
    buff[4] = '\0';
    myFile.read((char*)buff, 4);
    string src1 = hex_converter(buff, 4);
//    printf("src or 0x%x 0x%x 0x%x 0x%x\n", buff[0], buff[1], buff[2], buff[3]);


    myFile.read((char*)buff, 4);
    string dst1 = hex_converter(buff, 4);
//    printf("dst or 0x%x 0x%x 0x%x 0x%x\n", buff[0], buff[1], buff[2], buff[3]);


    myFile.seekg(HEADER);
    myFile.read((char*)buffer, len-HEADER);

//    for (int i = 0; i < 10; ++i) {
//        printf("%x ", buffer[i]);
//    }
    string str = hex_converter(buffer, len-HEADER);

    Packet p = Packet(id,src1,dst1);
    p.setData(str);
    string s = p.getData();
//    cout << s << endl;
//    cout << "src paquete: " << p.getSrc() << endl;
//    cout << "dst paquete: " << p.getDst() << endl;
    this->packets.push_back(p);


    return 0;
}

