
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Detector.h"

#define KEYWORD 3
#define THRESHOLD 2

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;
using std::vector;
using std::for_each;
//
//string hex_conv(string & str){
//    std::ostringstream dst;
//    dst << std::hex << std::setfill('0');
//
//    for (string::size_type i = 0; i < str.length(); ++i) {
//        dst << std::setw(2) << static_cast<int>(str[i]);
//        if (i<str.length()-1){ dst << " ";}
//    }
//
//    str = dst.str();
//    std::cout << "\nhex obtenido: " << str << "\n";
//    return str;
//}

void hex_conv(string & str){
    std::ostringstream dst;
    dst << std::hex << std::setfill('0');

    for (string::size_type i = 0; i < str.length(); ++i) {
        dst << std::setw(2) << static_cast<int>(str[i]);
        if (i<str.length()-1){ dst << " ";}
    }

    str = dst.str();
//    std::cout << "\nhex obtenido: " << str << "\n";
//    return str;
}

void print(string s){
    cout << s << endl;
}

void Detector::createRule(vector<string> &params){
    string src, dst, keyword;
    size_t threshold;
    keyword = params[KEYWORD];
    params.erase (params.begin() + KEYWORD);
    threshold = std::stoi(params[THRESHOLD]);
    params.erase (params.begin() + THRESHOLD);


    for_each(params.begin(), params.end(), hex_conv);

    src = params.front();
    params.erase(params.begin());

    dst = params.front();
    params.erase(params.begin());

//    cout << "print lo que me quedo: " << endl;
//    for_each(params.begin(), params.end(), print);
//    for (int i = 0; i < params.size(); ++i) {
//        params.[0] =
//    }

//    src = hex_conv(params[0]);
//    dst = hex_conv(params[1]);



    Rule r = Rule(src,dst,threshold,keyword,params);

    rules.push_back(r);
}

Detector::Detector(const string &conf, vector<Packet> &pkts) :
        conf(conf), packets(pkts) {
    this->conf = conf;
    this->packets = packets;
    string str;                      // This will store your tokens
    ifstream file(conf);

    std::ostringstream dst;
    while (file.peek() != EOF){
        getline(file, str, ';');
        if (str == "\n" || str == ""){ continue;}
//        cout << "leido: " << str << endl;
        std::istringstream iss(str);
        vector<string> params;

        while (iss) {
            std::string sub;
            iss >> sub;
            if (sub == ""){ continue;}
//            std::cout << "Substring: " << sub << std::endl;
//            params.push_back(hex_conv(sub));
            params.push_back(sub);
        }

//        for_each(params.begin(), params.end(), print);
//        string keyword = params[KEYWORD];
//        params.erase (params.begin() + KEYWORD);
//        for_each(params.begin(), params.end(), print);
//        cout << "key: " << keyword << endl;


//        rules.push_back(Rule())
        createRule(params);
        getline(file, str);
    }

    cout << "reglas: " << rules.size() << endl;

}


