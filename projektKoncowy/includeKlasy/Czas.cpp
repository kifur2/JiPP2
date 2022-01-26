//
// Created by CQ07 on 2022-01-19.
//

#include "Czas.h"
using namespace std;
int Czas::getGodzina() const{
    return godzina;
}
int Czas::getMinuta() const{
    return minuta;
}
void Czas::setGodzina(int nowaGodzina){
    godzina = nowaGodzina;
}
void Czas::setMinuta(int nowaMinuta){
    minuta = nowaMinuta;
}
ostream &operator<<(ostream &lhs, const Czas &rhs)
{
    if(rhs.godzina>9)
        cout<<rhs.godzina;
    else
        cout<<"0"<<rhs.godzina;
    cout<<":";
    if(rhs.minuta>9)
        cout<<rhs.minuta<<endl;
    else
        cout<<"0"<<rhs.minuta<<endl;
}