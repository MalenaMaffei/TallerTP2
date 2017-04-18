#ifndef TP2_READER_H
#define TP2_READER_H
#include <string>
#include <vector>
#include "Packet.h"
#include <iostream>
#include "PacketContainer.h"
#include "Thread.h"

using std::string;
using std::vector;
using std::ifstream;

class Reader : public Thread {
public:
    Reader(const string &file, PacketContainer &pkts);

    int create_packets();

    virtual ~Reader();
    void run();

private:
    string filename;
    PacketContainer & packets;
};


#endif //TP2_READER_H
