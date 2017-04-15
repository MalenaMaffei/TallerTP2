#include "Rule.h"
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

Rule::Rule(const string &src, const string &dst, size_t threshold,
           const string &keyword, const vector<string> &words, size_t id):
src (src), dst(dst), threshold(threshold), keyword(keyword), words(words) {
    this->dst = dst;
    this->src = src;
    this->keyword = keyword;
    this->threshold = threshold;
    this->words = words;
    this->curr_data = "";
    this->occurrences = 0;
    this->id = id;
    this->triggered = false;

//    cout << "regla creada con words: " << words.size() << endl;
}

//bool Rule::findWord(string word) const {
//    return curr_data.find(word) != std::string::npos;
//}


void Rule::checkPacket(Packet packet){
//    cout << "REGLA: " << id <<endl;
    bool match_src = false;
    bool match_dst = false;
//    bool match_src = true;
//    bool match_dst = true;
    if (src != "0"){
        match_src = (src == packet.getSrc());
    } else {
        match_src = true;
    }

    if (src != "0"){
        match_dst = (dst == packet.getDst());
    } else {
        match_dst = true;
    }

//    cout << "mi src: " << src << " la del paq: " << packet.getSrc() << endl;
//    cout << "son iguales?: " << (src == packet.getSrc()) << "matched dice:" << match_src << endl;
//    cout << "mi dst: " << dst << " la del paq: " << packet.getDst() << endl;
//    cout << "son iguales?: " << (dst == packet.getDst()) << "matched dice:" << match_dst << endl;
//    cout << endl;

    if (match_dst && match_src){
//        cout << "they matched" << endl;
        if (keyword == "always"){
            ++occurrences;
            triggered = true;
        } else {
//            cout << "Entreo al else" <<endl;
            checkData(packet.getData());
        }

//        cout << "triggered: "<< triggered <<endl;
//        cout << "occurr: " << occurrences <<endl;

        if (occurrences >= threshold && triggered){
            cout << "Rule " << id << ": ALERT! " << packet.getSrc() << " -> ";
            cout  << packet.getDst() << ": " << packet.getData() << endl;
//            cout  << packet.getDst() << ": " << endl;
            triggered = false;
        }

        return;

    } else {
        return;
    }
}


void print(bool s){
    cout << s;
}


void Rule::checkData(string data) {
//    cout << "hola" << endl;
    this->curr_data = data;
//    for_each(words.begin(), words.end(), findWord);

    vector<bool> matches;
    for (int i = 0; i < words.size(); ++i) {
//        cout << "comparando: " <<endl;
//        cout << "data de paquete: " << data <<endl;
//        cout << "palabra : " << words[i] << endl;
        matches.push_back(data.find(words[i]) != std::string::npos);
    }

    bool is_match = matches[0];
    if (keyword == "all"){

        for (int i = 0; i < matches.size(); ++i) {
            is_match = is_match && matches[i];
        }
//        is_match = matches[0];
        if (is_match){
            ++occurrences;
            triggered = true;
        }
    } else if (keyword == "any"){

        for (int i = 0; i < matches.size(); ++i) {
            is_match = is_match || matches[i];
        }
//        is_match = matches[0];
        if (is_match){
            ++occurrences;
            triggered = true;
        }
    }

//    cout << "ocurencias: " << occurrences << endl;
//    cout << "tengo: " << words.size() << " palabras y " << matches.size() << " matches" << endl;
//    for_each(matches.begin(), matches.end(), print);
//    cout <<endl;
}




//const vector<bool> &Rule::getMatches() const {
//    return matches;
//}

size_t Rule::getId() const {
    return id;
}

size_t Rule::getOccurrences() const {
    return occurrences;
}
