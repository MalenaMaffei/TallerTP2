#include <cstdio>
#include <string>
#include <iostream>
//#include "Packet.h"
//#include "Sniffer.h"
#include "Reader.h"
#include "Detector.h"
//#include "Rule.h"
#include <fstream>
#include <vector>
#include "Assembler.h"
#include <algorithm>
#include "PacketContainer.h"
#include "Thread.h"

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;


int main(int argc, char ** argv){
    if (argc < 3)
        return 1;



    vector<string> captures;
    vector<Reader> sniffers;
    string conf = argv[1];

    for (int i = 2; i < argc; ++i) {
        string parametro = argv[i];
        captures.push_back(parametro);
    }
    Detector d(conf);

    PacketContainer packetC(d);

//    Assembler a(packetC);

//    packetC.setAssembler(a);
//    packetC.setDetector(d);
//    std::vector<Thread*> threads;
    std::vector<Reader*> threads;


    for (size_t i = 0; i < captures.size(); ++i) {
        threads.push_back(new Reader(captures[i], packetC));
    }

//    cout << "threads: " << threads.size() << endl;
//
    for (size_t i = 0; i < captures.size(); ++i) {
        threads[i]->start();
//        threads[i]->run();
    }
//
    for (size_t i = 0; i < captures.size(); ++i) {
        threads[i]->join();
        delete threads[i];
    }

//    cout << "quedaron" << packetC.getLen() <<endl;

//    std::for_each(captures.begin(), captures.end(), [&](string filename){
//        sniffers.push_back(Reader(filename, packetC, a, d));
//    });
//
//
//    std::for_each(sniffers.begin(), sniffers.end(), [&](Reader sniffer) {
//        while (!sniffer.is_file_done()) {
//            sniffer.create_packets();
//            a.assemble();
//            d.detect();
//        }
//    });


























//    cout << "se generaron: " << packets.size() << "paquetes" << endl;

//    for (int j = 0; j < packets.size(); ++j) {
//        cout << "id: " << packets[j].getId() << endl;
//        cout << "src: " << packets[j].getSrc() << endl;
//        cout << "dst: " << packets[j].getDst() << endl;
//        cout << "flag: " << (int)packets[j].getFlag() << endl;
//        cout << "offset: " << packets[j].getOffset() << endl;
//        cout << "len: " << packets[j].getLength() << endl;
////        std::cout << "data: " << packets[j].getData() << std::endl;
//        cout << endl;
//    }



//    cout << "quedaron: " << packets.size() << endl;
//    for (int j = 0; j < packets.size(); ++j) {
//        cout << "id: " << packets[j].getId() << endl;
//        cout << "src: " << packets[j].getSrc() << endl;
//        cout << "dst: " << packets[j].getDst() << endl;
//        cout << "flag: " << (int)packets[j].getFlag() << endl;
//        cout << "offset: " << packets[j].getOffset() << endl;
//        cout << "len: " << packets[j].getLength() << endl;
//        cout << endl;
//    }

//    int i = packets.size();
//    for (int k = 0; k < i; ++k) {
//        d.detect();
//    }
//    cout << "quedaron: " << packets.size() << endl;

//    d.detect();

//    // Reader sniffB = Reader(file, packets);

//    sniff.create_packets();

//    // sniffB.create_packets();
//    int i = packets.size();
//    cout << "elementos: " << i << endl;
//    for (size_t j = 0; j < i; j++) {
//        Packet p = packets[j];
//        string s = p.getData();
//        cout << "data sacada del p"<< j<<": " << s << "\n\n";
//    }

//

//    Packet p1 = Packet("0", "1", "2", 0x1, 0, 1);
//    Packet p2 = Packet("0", "1", "2", 0x1, 1, 1);
//    Packet p3 = Packet("0", "1", "2", 0x1, 2, 1);
//    Packet p4 = Packet("0", "1", "2", 0x0, 3, 1);
//
//    p1.setData("hola");
//    p2.setData("que");
//    p3.setData("tal");
//    p4.setData("?");
//
//
//    Packet diff = Packet("0", "1", "3", 0x0, 0, 4);
//    diff.setData("diff");
//
//    vector<Packet> packets;
//    packets.push_back(p1);
//    packets.push_back(p2);
//    packets.push_back(p3);
//    packets.push_back(diff);
//    packets.push_back(p4);






//    cout << "p2 next de p1: " << p1.is_next(p2) << endl;
//    cout << "p3 next de p2: " << p2.is_next(p3) << endl;
//    cout << "p4 next de p3: " << p3.is_next(p4) << endl;

//    for (int j = 0; j < packets.size(); ++j) {
//        std::cout << " quedaron data: " << packets[j].getData() << std::endl;
//    }
//
//    cout << "data ultimo: " << packets.back().getData() << endl;

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

//    cout << "p1 data: " << p1.getData() << endl;
//    p1.mergePacket(p2);
//    cout << "p1 + p2 data: " << p1.getData() << endl;
//    cout << "p1 completo?: " << p1.is_complete() << endl;
//
//    p3.mergePacket(p4);
//    cout << "p3 + p4 data: " << p3.getData() << endl;
//    cout << "p3 completo?: " << p3.is_complete() << endl;
//
//    p1.mergePacket(p3);
//    cout << "p1 + p2 + p3 + p4 data: " << p1.getData() << endl;
//    cout << "p1 completo?: " << p1.is_complete() << endl;
//    cout << "p1 len: " << p1.getLength() << endl;

    return 0;
}
