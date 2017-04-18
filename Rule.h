
#ifndef TP2_RULE_H
#define TP2_RULE_H

#include <string>
#include <vector>
#include "Packet.h"
using std::string;
using std::vector;

class Rule {
public:
    Rule(const string &src, const string &dst, size_t threshold,
         const vector<string> &words, size_t id);

    void checkPacket(Packet packet);
    virtual void checkData(string data);

    const vector<bool> &getMatches() const;
    virtual ~Rule();
    size_t getId() const;
    bool doIpsMatch(Packet p);
    void printAlert(Packet packet) const;
    size_t getOccurrences() const;

protected:
    size_t id;
    string src;
    string dst;
    size_t threshold;
    std::vector<string> words;
    vector<bool> matches;
    size_t occurrences;
    bool triggered;
};
#endif //TP2_RULE_H
