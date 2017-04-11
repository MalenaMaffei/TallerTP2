//
// Created by male on 08/04/17.
//

#ifndef TP2_SNIFFER_H
#define TP2_SNIFFER_H
#include <string>
#include <vector>
#include "Packet.h"

using std::string;
using std::vector;


class Sniffer {
public:
    const vector<Packet> &getPackets() const;

private:
    string filename;
    vector<Packet> packets;
};


#endif //TP2_SNIFFER_H
