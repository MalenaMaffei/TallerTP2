#include "Rule.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using std::for_each;
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;
using std::for_each;

Rule::Rule(const string &src, const string &dst, size_t threshold,
           const vector<string> &words, size_t id):
src(src), dst(dst), threshold(threshold), words(words) {
    this->dst = dst;
    this->src = src;
    this->threshold = threshold;
    this->words = words;
    this->occurrences = 0;
    this->id = id;
    this->triggered = false;
}

Rule::~Rule(){}

bool Rule::doIpsMatch(Packet packet){
    bool match_src, match_dst;
    if (src != "0"){
        match_src = (src == packet.getSrc());
    } else {
        match_src = true;
    }

    if (dst != "0"){
        match_dst = (dst == packet.getDst());
    } else {
        match_dst = true;
    }

    return match_dst && match_src;
}

void Rule::checkPacket(Packet packet){
    bool matching_ips = doIpsMatch(packet);

    if (matching_ips){
        checkData(packet.getData());

        if (occurrences >= threshold && triggered){
            printAlert(packet);
            triggered = false;
        }
    }
}

void Rule::printAlert(Packet packet) const {
    cout << "Rule " << id << ": ALERT! " << packet.getSrc() << " -> ";
    cout  << packet.getDst() << ": " << packet.getData() << endl;
}

void Rule::checkData(string data) {}



size_t Rule::getId() const {
    return id;
}

size_t Rule::getOccurrences() const {
    return occurrences;
}
