//
// Created by male on 07/04/17.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include "Packet.h"
#include "Sniffer.h"
#include <fstream>

#define HEADER 20
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;

int main(int argc, char ** argv){
    string file = argv[1];
    Sniffer sniff = Sniffer(file);
    sniff.create_packets();
    Packet p = sniff.getPackets().front();

    string s = p.getData();
    cout << "data sacada del main: " << s << endl;
//
//
    return 0;
}
