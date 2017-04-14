#include <string>
#include "Packet.h"
// TODO implementar tema de flags y offsets
Packet::Packet(string id, string src, string dst) {
    this->id = id;
    this->src = src;
    this->dst = dst;
    this->data = "";
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
