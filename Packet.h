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
    string src;
    string dst;
    // TODO chequear bien como las necesito
    // short offset;
    // unsigned char flag;

    bool complete;


public:
    Packet(short id, string src, string dst);

    virtual ~Packet();

    const string &getData() const;

    short getLength() const;

    short getId() const;

    const string getSrc() const;

    const string getDst() const;

    const bool is_complete() const;

    void setData(const string &data);
};


#endif //TP2_PACKET_H
