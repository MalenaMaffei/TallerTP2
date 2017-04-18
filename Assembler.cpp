//#include <iostream>
//#include "Assembler.h"
//#include <algorithm>
//#include <vector>
//
//using std::sort;
//using std::cout;
//using std::endl;
//
//Assembler::Assembler() {
//}
//
//void Assembler::assemble(PacketContainer &packets){
////    std::lock_guard<std::mutex> lock(m);
//    Packet last = packets.getLatest();
//
//    if (last.is_complete()) { return; }
//    vector<Packet> fragments;
//
//    packets.getFragments(fragments, last);
//
//    sort(fragments.begin(), fragments.end());
//
//    for (size_t i = 1; i < fragments.size(); ++i)
//        if (!fragments[i-1].is_next(fragments[i])){ return; }
//
//
//    packets.removeFragments(last);
//
//
//    Packet first = fragments.front();
//    std::for_each(fragments.begin()+1, fragments.end(), [&](Packet p){
//       first.mergePacket(p);
//    });
//
//    packets.addPacket(first);
//}
