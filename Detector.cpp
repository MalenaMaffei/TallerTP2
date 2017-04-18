
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Detector.h"
#include "RuleAll.h"
#include "RuleAny.h"
#include "RuleAlways.h"
#include "HexConverter.h"
#define KEYWORD 3
#define THRESHOLD 2

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;
using std::for_each;

void format_string(string & str){
    HexConverter converter;
    converter.convertString(str);
}

Detector::~Detector() {
    for (size_t i = 0; i < rules.size(); ++i) {
        delete rules[i];
    }
}

void Detector::createRule(vector<string> &params, int id) {
    string src, dst, keyword;
    size_t threshold;


    keyword = params[KEYWORD];
    params.erase(params.begin() + KEYWORD);
    threshold = std::stoi(params[THRESHOLD]);
    params.erase(params.begin() + THRESHOLD);


    src = params.front();
    params.erase(params.begin());

    dst = params.front();
    params.erase(params.begin());

    for_each(params.begin(), params.end(), format_string);

    src.erase(0, std::min(src.find_first_not_of('0'), src.size()-1));
    dst.erase(0, std::min(dst.find_first_not_of('0'), dst.size()-1));


    Rule *ptr;
    if (keyword == "all"){
        ptr = new RuleAll(src,dst,threshold,params,id);
    } else if (keyword == "any"){
        ptr = new RuleAny(src,dst,threshold,params,id);
    } else {
        ptr = new RuleAlways(src, dst, threshold, params, id);
    }
    rules.push_back(ptr);
}

Detector::Detector(const string &conf) :
        conf(conf) {
    string str;
    ifstream file(conf);


    std::ostringstream dst;
    int id = 0;
    while (file.peek() != EOF){
        getline(file, str, ';');
        if (str == "\n" || str == ""){ continue;}
        std::istringstream iss(str);
        vector<string> params;

        while (iss) {
            std::string sub;
            iss >> sub;
            if (sub == ""){ continue;}
            params.push_back(sub);
        }

        createRule(params, id);
        getline(file, str);
        ++id;
    }
}

void Detector::detect(Packet packet){
    for (size_t j = 0; j < rules.size(); ++j) {
            rules[j]->checkPacket(packet);
    }
}
