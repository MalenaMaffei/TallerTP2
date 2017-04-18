#ifndef TP2_DETECTOR_H
#define TP2_DETECTOR_H

#include <string>
#include <vector>
#include "Packet.h"
#include "Rule.h"
//#include "PacketContainer.h"

using std::string;
using std::vector;

class PacketContainer;

class Detector {
public:
    explicit Detector(const string &conf);
    void createRule(vector<string> &params, int id);
    void detect(Packet packet);

private:
    string conf;
//    PacketContainer &packets;
//    vector<Packet> & packets;
    vector<Rule> rules;
//    std::mutex m;
};




#endif // TP2_DETECTOR_H
