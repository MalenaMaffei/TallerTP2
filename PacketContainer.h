#ifndef TP2_PACKETCONTAINER_H
#define TP2_PACKETCONTAINER_H

#include "Packet.h"
#include <vector>
#include <mutex>
//#include "Assembler.h"
#include "Detector.h"
using std::vector;



class PacketContainer {
public:
    explicit PacketContainer(Detector &detector);
    void addPacket(Packet p);
    void assemble();
    Packet popPacket();
    Packet &getLatest();
    void removeFragments(Packet p);

//    const vector<Packet> &getPackets() const;
//    void setAssembler(Assembler &assembler);
//    void setDetector(Detector &detector);
    void getFragments(vector<Packet> &fragments, Packet &fragment);
    size_t getLen();

private:
    vector<Packet> packets;
    std::mutex m;
//    Assembler assembler;
    Detector &detector;
};


#endif //TP2_PACKETCONTAINER_H
