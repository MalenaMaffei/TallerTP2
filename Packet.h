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
