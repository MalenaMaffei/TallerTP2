#include <iostream>
#include "Assembler.h"
#include <algorithm>

using std::sort;
using std::cout;

Assembler::Assembler(vector<Packet> &packets) : packets(packets) {
    this->packets = packets;
}
void Assembler::assemble(){
    Packet last = packets.back();

    if (last.is_complete()) { return; }
    vector<Packet> fragments;

    std::copy_if(packets.begin(), packets.end(), std::back_inserter(fragments),
                 [&](Packet p) { return p == last; });


    sort(fragments.begin(), fragments.end());
    for (size_t i = 1; i < fragments.size(); ++i) 
        if (!fragments[i-1].is_next(fragments[i])){ return; }


//    esto solo si estaba completo el paquete
    packets.erase(std::remove_if(packets.begin(), packets.end(),
                  [&](Packet p) { return p == last; }), packets.end());


//    std::cout << "cant frag: " << fragments.size() << std::endl;
//    for (int j = 0; j < fragments.size(); ++j) {
//        std::cout << "data: " << fragments[j].getData() << std::endl;
//    }

    Packet first = fragments.front();
    std::for_each(fragments.begin()+1, fragments.end(), [&](Packet p){
       first.mergePacket(p);
    });

//    cout << "me quedo: " << first.getData() << std::endl;

    packets.push_back(first);

}
