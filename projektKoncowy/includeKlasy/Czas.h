//
// Created by CQ07 on 2022-01-19.
//

#ifndef PROJEKTKONCOWY_CZAS_H
#define PROJEKTKONCOWY_CZAS_H
#include <iostream>
#include <string>
using namespace std;
class Czas{
private:
    int godzina, minuta;
public:
    Czas():godzina(0), minuta(0){};
    Czas(int godzina, int minuta):
    godzina(godzina), minuta(minuta){};
    int getGodzina() const;
    int getMinuta() const;
    void setGodzina(int nowaGodzina);
    void setMinuta(int nowaMinuta);
    friend ostream &operator<<(ostream &lhs, const Czas &rhs);
    bool operator<(const Czas* &czas)const{
        if(godzina<czas->getGodzina())
            return true;
        else
            if(godzina == czas->getGodzina())
                return minuta<czas->getMinuta();
            else
                return false;
    }
};
struct porownanieCzasow
{
    bool operator() (const pair<string,Czas*> &czas1, const pair<string,Czas*> &czas2)const{
        return czas1.second<czas2.second;
    }
};

#endif //PROJEKTKONCOWY_CZAS_H
