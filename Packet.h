//
// Created by male on 08/04/17.
//

#ifndef TP2_PACKET_H
#define TP2_PACKET_H
#include <string>
using std::string;

class Packet {
private:
    string data;
    short len;
    string id;
    string src;
    string dst;
    // TODO chequear bien como las necesito
    // short offset;
    // unsigned char flag;

    bool complete;


public:
    Packet(string id, string src, string dst);

    virtual ~Packet();

    const string &getData() const;

    short getLength() const;

    const string getId() const;

    const string getSrc() const;

    const string getDst() const;

    const bool is_complete() const;

    void setData(const string &data);
};


#endif //TP2_PACKET_H
