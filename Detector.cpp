
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Detector.h"

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;

Detector::Detector(const string &conf, vector<Packet> &pkts) : conf(conf), packets(pkts) {
    this->conf = conf;
    this->packets = packets;
}
