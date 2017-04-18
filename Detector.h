#ifndef TP2_DETECTOR_H
#define TP2_DETECTOR_H

#include <string>
#include <vector>
#include "Packet.h"
#include "Rule.h"
//
using std::string;
using std::vector;

//class PacketContainer;

class Detector {
public:
    explicit Detector(const string &conf);
    void createRule(vector<string> &params, int id);
    void detect(Packet packet);
    ~Detector();

private:
    string conf;
//    vector<Rule> rules;
    std::vector<Rule*> rules;
};




#endif // TP2_DETECTOR_H
