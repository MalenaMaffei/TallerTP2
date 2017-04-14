#include <cstdio>
#include <string>
#include <iostream>
#include "Packet.h"
#include "Sniffer.h"
#include "Detector.h"
#include <fstream>
#include <vector>
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;

int main(int argc, char ** argv){
    if (argc < 3)
        return 0;

    vector<Packet> packets;
    string conf = argv[1];
    string file = argv[2];
    Detector d = Detector(conf, packets);
    Sniffer sniff = Sniffer(file, packets);
    // Sniffer sniffB = Sniffer(file, packets);
    sniff.create_packets();
    // sniffB.create_packets();
    int i = packets.size();
    cout << "elementos: " << i << endl;
    for (size_t j = 0; j < i; j++) {
        Packet p = packets[j];
        string s = p.getData();
        cout << "id: " << p.getId() << " src: " << p.getSrc() << " dst: " << p.getDst() << endl;
        cout << "data sacada del p"<< j<<": " << s << "\n\n";
    }

    return 0;
}
