//
// Created by CQ07 on 2022-01-28.
//

#ifndef PROJEKTKONCOWY_MOJWYJATEK_H
#define PROJEKTKONCOWY_MOJWYJATEK_H
#include <exception>
class MojWyjatek:public exception{
private:
    string tekstWyjatku;
public:
    MojWyjatek(string tekstWyjatku):tekstWyjatku(tekstWyjatku){}
    const string what(){
        return tekstWyjatku;
    }
};
#endif //PROJEKTKONCOWY_MOJWYJATEK_H
