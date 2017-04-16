#include <cstdio>
#include <string>
#include <iostream>
//#include "Packet.h"
#include "Sniffer.h"
#include "Detector.h"
//#include "Rule.h"
#include <fstream>
#include <vector>
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;

int main(int argc, char ** argv){
//    if (argc < 3)
//        return 1;

//    vector<string> words = {"hello", "world", "caca"};
//    Rule r = Rule("0", "1",0,"always",words,0);
//    r.checkData("hola ld");
//    cout << "primer palabra: " << r.getMatches()[0]<<endl;
//    cout << "segunda: " << r.getMatches()[1] << endl;
//    cout << "tercera: " << r.getMatches()[2] << endl;
//    cout << "ocurrencia? " << r.getOccurrences() << endl;



//    vector<Packet> packets;
//    string conf = argv[1];
//    string file = argv[2];
//    Detector d = Detector(conf, packets);




//    Sniffer sniff = Sniffer(file, packets);

//    // Sniffer sniffB = Sniffer(file, packets);

//    sniff.create_packets();

//    // sniffB.create_packets();
//    int i = packets.size();
//    cout << "elementos: " << i << endl;
//    for (size_t j = 0; j < i; j++) {
//        Packet p = packets[j];
//        string s = p.getData();
//        cout << "data sacada del p"<< j<<": " << s << "\n\n";
//    }

//    d.detect();

    Packet p1 = Packet("0", "1", "2", 0x1, 0, 1);
    Packet p2 = Packet("0", "1", "2", 0x1, 2, 1);
    Packet p3 = Packet("0", "1", "2", 0x1, 3, 1);
    Packet p4 = Packet("0", "1", "2", 0x0, 4, 1);

    p1.setData("hola");
    p2.setData("que");
    p3.setData("tal");
    p4.setData("?");


    Packet diff = Packet("0", "1", "3", 0x0, 0, 4);

//    cout << "el p1 es completo?: " << p1.is_complete() << endl;
//    cout << "el diff es completo?: " << diff.is_complete() << endl;
//
//    cout << "p1 y p2 son iguales?: " << (p1 == p2 )<< endl;
//    cout << "p2 y p1 son iguales?: " << (p2 == p1 )<< endl;
//
//    cout << "p1 y p3 son iguales?: " << (p1 == p3 )<< endl;
//    cout << "p3 y p1 son iguales?: " << (p3 == p1 )<< endl;
//
//    cout << "p2 y p3 son iguales?: " << (p2 == p3 )<< endl;
//    cout << "p3 y p2 son iguales?: " << (p3 == p2 )<< endl;
//
//    cout << "p1 y diff son iguales?: " << (p1 == diff )<< endl;
//    cout << "diff y p1 son iguales?: " << (diff == p1 )<< endl;

//    cout << "p1 > p2?: " << (p1 > p2) << endl;
//    cout << "p1 < p2?: " << (p1 < p2) << endl;
//
//    cout << "p1 > p3?: " << (p1 > p2) << endl;
//    cout << "p1 < p3?: " << (p1 < p2) << endl;
//
//    cout << "p2 > p3?: " << (p2 > p3) << endl;
//    cout << "p2 < p3?: " << (p2 < p3) << endl;

    cout << "p1 data: " << p1.getData() << endl;
    p1.mergePacket(p2);
    cout << "p1 + p2 data: " << p1.getData() << endl;

    p3.mergePacket(p4);
    cout << "p3 + p4 data: " << p3.getData() << endl;

    p1.mergePacket(p3);
    cout << "p1 + p2 + p3 + p4 data: " << p1.getData() << endl;

    return 0;
}
