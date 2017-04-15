#include "Rule.h"
#include <algorithm>

using std::for_each;

Rule::Rule(const string &src, const string &dst, size_t threshold,
             const string &keyword, const vector<string> &words):
src (src), dst(dst), threshold(threshold), keyword(keyword), words(words) {
    this->dst = dst;
    this->src = src;
    this->keyword = keyword;
    this->threshold = threshold;
    this->words = words;
    this->curr_data = "";
//    this->occurrences = 0;
}

//bool Rule::findWord(string word) const {
//    return curr_data.find(word) != std::string::npos;
//}

void Rule::checkWords(string data) {
    this->curr_data = data;
//    for_each(words.begin(), words.end(), findWord);
    for (int i = 0; i < words.size(); ++i) {
        matches.push_back(data.find(words[i]) != std::string::npos);
    }
}

const vector<bool> &Rule::getMatches() const {
    return matches;
}
