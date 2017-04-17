#ifndef TP2_SNIFFER_H
#define TP2_SNIFFER_H
#include <string>
#include <vector>
#include "Packet.h"
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;

class Sniffer {
public:
    Sniffer(const string &file, vector<Packet> &pkts);

    int create_packets();

    virtual ~Sniffer();

private:
    string filename;
    vector<Packet> & packets;
    int file_pos;
};


#endif //TP2_SNIFFER_H
