#include <string>
#include <vector>
#include "Packet.h"
using std::string;
using std::vector;

class Rule {
public:
    Rule(const string &src, const string &dst, size_t threshold,
          const string &keyword, const vector<string> &words);

//    bool Rule::findWord(string word) const;
    void checkWords(string data);

    const vector<bool> &getMatches() const;

private:
    string src;
    string dst;
    size_t threshold;
    string keyword;
    std::vector<string> words;
    string curr_data;
    vector<bool> matches;
//    string occurrences;

};
