//
// Created by CQ07 on 2022-01-19.
//

#include "Stacja.h"
string Stacja::getNazwa(){
    return nazwa;
}
int Stacja::getLiczbaPeronow(){
    return liczbaPeronow;
}
void Stacja::dodajPojazd(string &poj){
    pojazdy.push_back(poj);
}
void Stacja::dodajPrzyjazd(string &poj, Czas* czas){
    przyjazdy[poj]=czas;
    pair<string, Czas*> nowyCzas;
    nowyCzas.first=poj;
    nowyCzas.second=czas;
    tablica.push(nowyCzas);
}
void Stacja::dodajOdjazd(string &poj, Czas* czas){
    odjazdy[poj]=czas;
}
ostream &operator<<(ostream &lhs, const Stacja &rhs){
    lhs << rhs.nazwa;
    return lhs;
}