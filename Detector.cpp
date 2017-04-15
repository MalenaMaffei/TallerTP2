
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
#define DUMMY_ID 0
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
//    std::ostringstream dst;
//    dst << std::hex << std::setfill('0');
//
//    for (string::size_type i = 0; i < str.length(); ++i) {
//        dst << std::setw(2) << static_cast<int>(str[i]);
//        if (i<str.length()-1){ dst << " ";}
//    }
//
//    str = dst.str();

    std::ostringstream dst;
    dst << std::hex;

    for (string::size_type i = 0; i < str.length(); ++i) {
        dst << static_cast<int>(str[i]);
        if (i<str.length()-1){ dst << " ";}
    }

    str = dst.str();

}

void print(string s){
    cout << s << endl;
}

void Detector::createRule(vector<string> &params, int id) {
    string src, dst, keyword;
//    int i_src, i_dst;
    size_t threshold;
    keyword = params[KEYWORD];
    params.erase (params.begin() + KEYWORD);
    threshold = std::stoi(params[THRESHOLD]);
    params.erase (params.begin() + THRESHOLD);


    src = params.front();
    params.erase(params.begin());

    dst = params.front();
    params.erase(params.begin());

    for_each(params.begin(), params.end(), hex_conv);


//    i_src = std::stoi(src, nullptr, 16);
//    i_dst = std::stoi(dst, nullptr, 16);

//    if (i_src == 0){
//        src = "0";
//    }
//
//    if (i_dst == 0){
//        dst = "0";
//    }

    src.erase(0, std::min(src.find_first_not_of('0'), src.size()-1));
    dst.erase(0, std::min(dst.find_first_not_of('0'), dst.size()-1));

//    cout << "Src: " << src <<endl;
//    cout << "Src: " << dst <<endl;
//    cout << "print lo que me quedo: " << endl;
//    for_each(params.begin(), params.end(), print);
//    for (int i = 0; i < params.size(); ++i) {
//        params.[0] =
//    }

//    src = hex_conv(params[0]);
//    dst = hex_conv(params[1]);



    Rule r = Rule(src,dst,threshold,keyword,params,id);

    rules.push_back(r);
}

Detector::Detector(const string &conf, vector<Packet> &pkts) :
        conf(conf), packets(pkts) {
    this->conf = conf;
    this->packets = packets;
    string str;                      // This will store your tokens
    ifstream file(conf);

    std::ostringstream dst;
    int id = 0;
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
        createRule(params, id);
        getline(file, str);
        ++id;
    }

//    cout << "reglas: " << rules.size() << endl;

}

void Detector::detect(){
    for (int i = 0; i < packets.size(); ++i) {
        Packet p = packets[i];
        for (int j = 0; j < rules.size(); ++j) {
            rules[j].checkPacket(p);
        }
    }
}