#ifndef TP2_READER_H
#define TP2_READER_H
#include <string>
#include <vector>
#include "Packet.h"
#include <iostream>
#include "PacketContainer.h"
#include "Thread.h"
#include "Assembler.h"
#include "Detector.h"
using std::string;
using std::vector;
using std::ifstream;

class Reader : public Thread {
public:
    Reader(const string &file, PacketContainer &pkts);

    int create_packets();

    virtual ~Reader();
    void run();
    bool is_file_done() const;


private:
    string filename;
//    vector<Packet> & packets;
    PacketContainer & packets;
    int file_pos;
//    Assembler & assembler;
//    Detector & detector;
//    ifstream file;
};


#endif //TP2_READER_H
