#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Reader.h"
#include <netinet/in.h>
#include <algorithm>
#include "HexConverter.h"
#define HEADER 20

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;

Reader::Reader(const string &file, PacketContainer &pkts) :
        filename(file), packets(pkts) {}

Reader::~Reader() {}

void Reader::run() {
            create_packets();
}

int Reader::create_packets(){
    ifstream file;

    file.open(Reader::filename, ios::in | ios::binary);
    HexConverter converter;
    while (file.peek() != EOF){
        short len;
        short data_len;
        short shorts[3];
//        HexConverter converter;

        file.seekg(2, ios::cur);
        //lee length

        file.read((char*) shorts, 2);
        len = shorts[0];
        len = ntohs(len);
        data_len = len - HEADER;
        //    lee id
        unsigned char id_buff[2];
        file.read((char*) id_buff, 2);
        string id = converter.convertNum(id_buff, 2);


        //    lee offset
        unsigned char fo[2];
        file.read((char*) fo, 2);

        unsigned char flag = fo[0];

        flag <<= 2;
        flag >>= 7;

        fo[0] <<= 3;
        fo[0] >>= 3;
        short* offset_ptr = (short*) fo;
        short offset = *offset_ptr;
        offset = ntohs(offset);

        file.seekg(4, ios::cur);

        unsigned char fo_buff[5];
        fo_buff[4] = '\0';
        file.read((char*)fo_buff, 4);

        string src = converter.convertNum(fo_buff, 4);

        file.read((char*)fo_buff, 4);
        string dst = converter.convertNum(fo_buff, 4);

        unsigned char *buffer = (unsigned char*) malloc(data_len);

        file.read((char*)buffer, data_len);

        string data = converter.convertChars(buffer, data_len);
        free(buffer);

        Packet p = Packet(id, src, dst, flag, offset, data_len);
        p.setData(data);

        this->packets.addPacket(p);
    }

    file.close();

    return 0;
}
