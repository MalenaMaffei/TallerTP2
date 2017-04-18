//
// Created by male on 18/04/17.
//

#ifndef TP2_RULEALWAYS_H
#define TP2_RULEALWAYS_H
#include <string>
#include <vector>
#include "Packet.h"
#include "Rule.h"
using std::string;
using std::vector;

class RuleAlways : public Rule {
public:
    RuleAlways(const string &src, const string &dst, size_t threshold,
               const vector <string> &words, size_t id);

    void checkData(string data);

    const vector<bool> &getMatches() const;

    size_t getId() const;

    size_t getOccurrences() const;
};
#endif //TP2_RULEALWAYS_H
