#ifndef TALLERTP2_ASSEMBLER_H
#define TALLERTP2_ASSEMBLER_H


#include "Packet.h"
#include <vector>

using std::vector;

class Assembler {
public:
    Assembler(vector<Packet> &packets);
    void assemble();

private:
    vector<Packet> & packets;

};


#endif //TALLERTP2_ASSEMBLER_H
