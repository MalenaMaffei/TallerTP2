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
    vector<Packet> packets;
    explicit Sniffer(const string &filename);


    int create_packets();

    virtual ~Sniffer();

    const vector<Packet> &getPackets() const;

private:
    string filename;

};


#endif //TP2_SNIFFER_H
