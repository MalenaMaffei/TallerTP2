//
// Created by male on 18/04/17.
//

#include "HexConverter.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#define HEADER 20

using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::cout;

string HexConverter::convertChars(unsigned char* buffer, size_t len){
    std::ostringstream dst;
    dst << std::hex;

    for (size_t i = 0; i < len; ++i) {
        dst << static_cast<int>(buffer[i]);

        if (i<len-1){ dst << " ";}
    }
    string dst1 = dst.str();
    return dst1;
}

void HexConverter::convertString(string & str){
    std::ostringstream dst;
    dst << std::hex;

    for (string::size_type i = 0; i < str.length(); ++i) {
        dst << static_cast<int>(str[i]);
        if (i<str.length()-1){ dst << " ";}
    }

    str = dst.str();
}


string HexConverter::convertNum(unsigned char* buffer, size_t len){
    std::ostringstream dst;
    dst << std::hex << std::setfill('0');

    for (size_t i = 0; i < len; ++i) {
        dst << std::setw(2) << static_cast<int>(buffer[i]);
    }
    string dst1 = dst.str();
    dst1.erase(0, std::min(dst1.find_first_not_of('0'), dst1.size()-1));
    return dst1;
}
