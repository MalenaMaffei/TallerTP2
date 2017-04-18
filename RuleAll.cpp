//
// Created by male on 17/04/17.
//

#include "RuleAll.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using std::for_each;
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;
using std::for_each;

RuleAll::RuleAll(const string &src, const string &dst, size_t threshold,
        const vector<string> &words, size_t id) :
        Rule(src, dst, threshold,words,id){}


void RuleAll::checkData(string data) {
//    this->curr_data = data;

    vector<bool> matches;
    for (size_t i = 0; i < words.size(); ++i) {
        matches.push_back(data.find(words[i]) != std::string::npos);
    }

    bool is_match = matches[0];

    for (size_t i = 0; i < matches.size(); ++i) {
        is_match = is_match && matches[i];
    }
//        is_match = matches[0];
    if (is_match){
        ++occurrences;
        triggered = true;
    }
}

