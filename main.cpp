//
// Created by male on 07/04/17.
//

#include <cstdio>
#include <string>
#include <iostream>
#include "Packet.h"

using namespace std;
int main(){
    // printf("%s", "hola");
    Packet p = Packet(1,2,3);
    p.setData("Hola soy un paquetito");
    string s = p.getData();
    cout << s << endl;

    return 0;
}
