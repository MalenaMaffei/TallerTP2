#include <string>
#include <iostream>
#include "Packet.h"
// TODO implementar tema de flags y offsets
Packet::Packet(string id, string src, string dst, unsigned char flag, short offset,
               short len) {
    this->id = id;
    this->src = src;
    this->dst = dst;
    this->data = "";
    this->flag = flag;
    this->offset = offset;
    this->len = len;

    complete = (offset == 0 && flag ==0);
}

Packet::~Packet() {
//por ahora nada que hacer
}

const string &Packet::getData() const {
    return data;
}

short Packet::getLength() const {
    return len;
}

const string Packet::getId() const {
    return id;
}

const string Packet::getSrc() const {
    return src;
}

const string Packet::getDst() const {
    return dst;
}

const bool Packet::is_complete() const {
    return complete;
}

void Packet::setData(const string &data) {
    Packet::data = data;
}

bool Packet::operator==(const Packet& other) const{
    bool match_src = this->src == other.src;
    bool match_dst = this->dst == other.dst;
    bool match_id = this->id == other.id;
    return match_dst && match_src && match_id;
}

bool Packet::operator>(const Packet& other) const{
//el mayor es el ultimo
    return offset > other.offset;
}

bool Packet::operator<(const Packet& other) const{
//el mayor es el ultimo
    return offset < other.offset;
}

bool Packet::is_first() const{
    return offset == 0;
}

bool Packet::is_last() const{
    return flag == 0;
}

bool Packet::is_next(const Packet& other){
//    std::cout << "off + len: " << offset + len <<std::endl;
//    std::cout << "otro off: " << other.offset << std::endl;
    return (offset + len) == other.offset;
}

int Packet::mergePacket(const Packet& nextPacket ){
    if (!is_next(nextPacket)){ return -1; }
    string first_data = this->data;
    string next_data = nextPacket.data;
    string complete_data = first_data + next_data;
    this->data = complete_data;
    this->len += nextPacket.len;
    this->flag = nextPacket.flag;
    if (is_first() && nextPacket.is_last()){
        complete = true;
    }
    return 0;
}