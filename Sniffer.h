#ifndef TP2_SNIFFER_H
#define TP2_SNIFFER_H
#include <string>
#include <vector>
#include "Packet.h"

using std::string;
using std::vector;


class Sniffer {
public:
    Sniffer(const string &file, vector<Packet> &pkts);

    int create_packets();

    virtual ~Sniffer();

private:
    string file;
    vector<Packet> & packets;
};


#endif //TP2_SNIFFER_H
