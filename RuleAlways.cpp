#include "RuleAlways.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

RuleAlways::RuleAlways(const string &src, const string &dst, size_t threshold,
               const vector<string> &words, size_t id) :
        Rule(src, dst, threshold,words,id){}


void RuleAlways::checkData(string data) {
    ++occurrences;
    triggered = true;
}
