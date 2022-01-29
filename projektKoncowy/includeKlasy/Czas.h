//
// Created by CQ07 on 2022-01-19.
//

#ifndef PROJEKTKONCOWY_CZAS_H
#define PROJEKTKONCOWY_CZAS_H
#include <iostream>
#include <string>
#define MYTYPE int
using namespace std;
template<typename T>
class Czas{
private:
    T godzina, minuta;
public:
    Czas():godzina(0), minuta(0){};
    Czas(T godzina, T minuta):
    godzina(godzina), minuta(minuta){};
    T getGodzina() const{
        return godzina;
    }
    T getMinuta() const{
        return minuta;
    }
    bool operator<(const Czas<T>* &czas)const{
        if(godzina<czas->getGodzina())
            return true;
        else
            if(godzina == czas->getGodzina())
                return minuta<czas->getMinuta();
            else
                return false;
    }
};
template <typename T>
struct porownanieCzasow
{
    bool operator() (const pair<string,Czas<T>*> &czas1, const pair<string,Czas<T>*> &czas2)const{
        return czas1.second<czas2.second;
    }
};

#endif //PROJEKTKONCOWY_CZAS_H
