#include <string>
#include <vector>
#include "Packet.h"
using std::string;
using std::vector;

class Rule {
public:
    Rule(const string &src, const string &dst, size_t threshold,
         const string &keyword, const vector<string> &words, size_t id);

//    bool Rule::findWord(string word) const;
    void checkPacket(Packet packet);
    void checkData(string data);

    const vector<bool> &getMatches() const;

    size_t getId() const;

    size_t getOccurrences() const;

private:
    size_t id;
    string src;
    string dst;
    size_t threshold;
    string keyword;
    std::vector<string> words;
    string curr_data;
    vector<bool> matches;
    size_t occurrences;
    bool triggered;

};
