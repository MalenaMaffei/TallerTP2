//
// Created by male on 08/04/17.
//

#include <fstream>
#include "Sniffer.h"
#include <string>
#include <vector>

const vector<Packet> &Sniffer::getPackets() const {
    return packets;
}
