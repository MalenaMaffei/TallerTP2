#ifndef TP2_DETECTOR_H
#define TP2_DETECTOR_H

#include <string>
#include <vector>
#include "Packet.h"
#include "Rule.h"

using std::string;
using std::vector;

class Detector {
public:
    Detector(const string &conf, vector<Packet> &pkts);
    void createRule(vector<string> &params);

private:
    string conf;
    vector<Packet> & packets;
    vector<Rule> rules;
};




#endif // TP2_DETECTOR_H
