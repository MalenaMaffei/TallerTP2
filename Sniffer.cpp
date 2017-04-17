#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Sniffer.h"
#include <netinet/in.h>
#include <algorithm>
#define HEADER 20

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;

Sniffer::Sniffer(const string &file, vector<Packet> &pkts) :
        filename(file), packets(pkts) {
    this->filename = file;
    this->packets = packets;
    this->file_pos = 0;
}

Sniffer::~Sniffer() {
//nada por aca
}

string hex_data_converter(unsigned char* buffer, size_t len){
    std::ostringstream dst;
//    dst << std::hex << std::setfill('0');
    dst << std::hex;
//    dst << std::hex;

    for (size_t i = 0; i < len; ++i) {
//        dst << std::setw(2) << static_cast<int>(buffer[i]);
        dst << static_cast<int>(buffer[i]);

        if (i<len-1){ dst << " ";}
    }
    string dst1 = dst.str();
//    std::cout << "\nhex obtenido: " << dst1 << "\n";
    return dst1;
}

string hex_num_converter(unsigned char* buffer, size_t len){
    std::ostringstream dst;
    dst << std::hex << std::setfill('0');

    for (size_t i = 0; i < len; ++i) {
        dst << std::setw(2) << static_cast<int>(buffer[i]);
    }
    string dst1 = dst.str();
    dst1.erase(0, std::min(dst1.find_first_not_of('0'), dst1.size()-1));
//    int i_num = std::stoi(dst1);
//
//    std::ostringstream final;
//    final << std::hex;
//    final << std::setw(2) << (i_num);
//
//    string num = final.str();


//    std::cout << "\nhex obtenido: " << dst1 << "\n";
    return dst1;
}

bool Sniffer::is_file_done(){
    ifstream file;
    
    return
}

int Sniffer::create_packets(){
    ifstream file;

    file.open(Sniffer::filename, ios::in | ios::binary);
    file.seekg(file_pos);

    while (file.peek() != EOF){
        short len;
        short data_len;
        unsigned char buffer[1050];
        short shorts[3];

        file.seekg(2, ios::cur);
        //lee length

        file.read((char*) shorts, 2);
        len = shorts[0];
        // cout << "len antes de cambiar: " << len << endl;
        len = ntohs(len);
        // cout << "len dsp de cambiar: " << len << endl;
        data_len = len - HEADER;
        //    lee id
        unsigned char id_buff[2];
        file.read((char*) id_buff, 2);
        string id = hex_num_converter(id_buff, 2);
    //    printf("id original: %x %x\n", id_buff[0], id_buff[1]);


        //    lee offset
        unsigned char fo[2];
        file.read((char*) fo, 2);
        // fo[0] = 0xaa;
        // fo[1] = 0xaa;
        unsigned char flag = fo[0];
        // flag parece estar bien, re chequear despues
//        printf("\nEl orig flag 0x%x\n",flag);
        flag <<= 2;
        flag >>= 7;
//        printf("El shift flag 0x%x\n",flag);
//        printf("El int flag %i\n",flag);

        //    printf("\nEl orig off 0x%x 0x%x\n",fo[0], fo[1]);
        fo[0] <<= 3;
        fo[0] >>= 3;
//        printf("El shift off 0x%x 0x%x\n",fo[0], fo[1]);
        short* offset_ptr = (short*) fo;
        short offset = *offset_ptr;
        offset = ntohs(offset);
    //    cout << "offset guardado: " << offset << endl;
            //ignora 4 bytes
        // myFile.seekg(12);
        file.seekg(4, ios::cur);


        unsigned char buff[5];
        buff[4] = '\0';
        file.read((char*)buff, 4);
        string src = hex_num_converter(buff, 4);

        file.read((char*)buff, 4);
        string dst = hex_num_converter(buff, 4);


        //        TODO MALLOC Y CHEQUEAR SI HAY DATA
        file.read((char*)buffer, data_len);

    //    for (int i = 0; i < 10; ++i) {
    //        printf("%x ", buffer[i]);
    //    }
        string data = hex_data_converter(buffer, data_len);

        Packet p = Packet(id, src, dst, flag, offset, data_len);
        p.setData(data);

        this->packets.push_back(p);

        this->file_pos += len;
    }

    file.close();

    return 0;
}
