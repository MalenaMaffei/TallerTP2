//
// Created by male on 18/04/17.
//

#ifndef TP2_HEXCONVERTER_H
#define TP2_HEXCONVERTER_H
#include <string>
#define HEADER 20

using std::string;




class HexConverter {
public:
    string convertChars(unsigned char* buffer, size_t len);

    void convertString(string & str);

    string convertNum(unsigned char* buffer, size_t len);
};


#endif //TP2_HEXCONVERTER_H
