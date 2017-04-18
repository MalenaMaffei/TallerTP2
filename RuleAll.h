#ifndef TP2_RULEALL_H
#define TP2_RULEALL_H
#include <string>
#include <vector>
#include "Packet.h"
#include "Rule.h"
using std::string;
using std::vector;

class RuleAll : public Rule {
public:
    RuleAll(const string &src, const string &dst, size_t threshold,
            const vector<string> &words, size_t id);

    void checkData(string data);

    const vector<bool> &getMatches() const;

    size_t getId() const;

    size_t getOccurrences() const;
};


#endif //TP2_RULEALL_H
