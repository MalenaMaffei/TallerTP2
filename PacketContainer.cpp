#include "PacketContainer.h"
#include <vector>
#include <algorithm>
#include <iostream>

PacketContainer::PacketContainer(Detector &detector) : detector(detector) {
}

void PacketContainer::addPacket(Packet p) {
    std::lock_guard<std::mutex> lock(m);

    packets.push_back(p);
//        llamar ensamblador
    assemble();

    if (packets.back().is_complete()){
        detector.detect(popPacket());
    }
}
void PacketContainer::assemble(){
    Packet last = packets.back();


    if (last.is_complete()) { return; }
    vector<Packet> fragments;
//
    getFragments(fragments, last);
//
    sort(fragments.begin(), fragments.end());
//
    for (size_t i = 1; i < fragments.size(); ++i)
        if (!fragments[i-1].is_next(fragments[i])){ return; }
//
//
    removeFragments(last);
//
    Packet first = fragments.front();
    std::for_each(fragments.begin()+1, fragments.end(), [&](Packet p){
       first.mergePacket(p);
    });

    packets.push_back(first);
}

Packet PacketContainer::popPacket() {
//    std::lock_guard<std::mutex> lock(m);
    Packet p = packets.back();
    packets.pop_back();
    return p;
}

Packet &PacketContainer::getLatest() {
//    std::lock_guard<std::mutex> lock(m);
    return packets.back();
}

void PacketContainer::removeFragments(Packet fragment) {
//    std::lock_guard<std::mutex> lock(m);
    packets.erase(std::remove_if(packets.begin(), packets.end(),
                  [&](Packet p) { return p == fragment; }), packets.end());
}

//const vector<Packet> &PacketContainer::getPackets() const {
//    return packets;
//}

void PacketContainer::getFragments(vector<Packet> &fragments, Packet &fragment){
//    std::lock_guard<std::mutex> lock(m);
    std::copy_if(packets.begin(), packets.end(), std::back_inserter(fragments),
                 [&](Packet p) { return p == fragment; });
}

size_t PacketContainer::getLen(){
    return packets.size();
}
