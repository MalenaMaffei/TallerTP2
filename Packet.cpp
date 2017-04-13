#include <string>
#include "Packet.h"
// TODO implementar tema de flags y offsets
Packet::Packet(short id, int src, int dst) {
    this->id = id;
    this->src = src;
    this->dst = dst;
}

Packet::~Packet() {
//por ahora nada que hacer
//    TODO proximamente desalocar el char pointer
// seguramente no haga falta
}

const string &Packet::getData() const {
    return data;
}

short Packet::getLength() const {
    return len;
}

short Packet::getId() const {
    return id;
}

int Packet::getSrc() const {
    return src;
}

int Packet::getDst() const {
    return dst;
}

void Packet::setData(const string &data) {
    Packet::data = data;
}
