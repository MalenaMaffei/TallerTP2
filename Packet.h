//
// Created by male on 08/04/17.
//

#ifndef TP2_PACKET_H
#define TP2_PACKET_H
#include <string>
using std::string;
//TODO no se puede usar la puta string http://stackoverflow.com/questions/11181251/saving-hex-values-to-a-c-string
//http://stackoverflow.com/questions/30423469/store-hex-value-in-string-c
class Packet {
private:
    string data;
    short len;
    short id;
    int src;
    int dst;

public:
    Packet(short id, int src, int dst);

    virtual ~Packet();

    const string &getData() const;

    short getLength() const;

    short getId() const;

    int getSrc() const;

    int getDst() const;

    void setData(const string &data);
};


#endif //TP2_PACKET_H
