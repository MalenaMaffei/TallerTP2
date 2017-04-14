#include <cstdio>
#include <string>
#include <iostream>
#include "Packet.h"
#include "Sniffer.h"
#include <fstream>
#include <vector>
#define HEADER 20
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;

int main(int argc, char ** argv){
    if (argc < 2)
        return 0;

    vector<Packet> packets;
    string file = argv[1];
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
        cout << "data sacada del p"<< j<<": " << s << endl;
    }

    return 0;
}
