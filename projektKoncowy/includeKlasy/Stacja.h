//
// Created by CQ07 on 2022-01-19.
//

#ifndef PROJEKTKONCOWY_STACJA_H
#define PROJEKTKONCOWY_STACJA_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include "Czas.h"

using namespace std;

class Stacja{
private:
    string nazwa;
    int liczbaPeronow;
    vector <string> pojazdy;
    map <string, Czas<MYTYPE>*> przyjazdy;
    map <string, Czas<MYTYPE>*> odjazdy;
    priority_queue<pair<string,Czas<MYTYPE>*>,vector< pair<string,Czas<MYTYPE>*>>, porownanieCzasow<MYTYPE>> tablica;
    priority_queue<pair<string,Czas<MYTYPE>*>,vector< pair<string,Czas<MYTYPE>*>>, porownanieCzasow<MYTYPE>> tablicapom;
public:
    Stacja():nazwa("pusty"), liczbaPeronow(0){};
    Stacja(string &nazwa, int liczbaPeronow):
    nazwa(nazwa), liczbaPeronow(liczbaPeronow){}
    string getNazwa();
    int getLiczbaPeronow();
    void dodajPojazd(string &poj);
    void dodajPrzyjazd(string &poj, Czas<MYTYPE>* czas);
    void dodajOdjazd(string &poj, Czas<MYTYPE>* czas);
    friend void wyswietlTabliceOdCzasu(Stacja* stacja, Czas<MYTYPE>* czas);
    friend ostream &operator<<(ostream &lhs, const Stacja &rhs);
    Stacja(Stacja &stacja){
        nazwa = stacja.nazwa;
        liczbaPeronow=stacja.liczbaPeronow;
        pojazdy.clear();
        for(int i=0; i<stacja.pojazdy.size(); i++)
        {
            dodajPojazd(stacja.pojazdy[i]);
            dodajPrzyjazd(stacja.pojazdy[i], stacja.przyjazdy[stacja.pojazdy[i]]);
            dodajOdjazd(stacja.pojazdy[i], stacja.odjazdy[stacja.pojazdy[i]]);
        }

    }
    ~Stacja(){
        for(int i=0; i<pojazdy.size(); i++){
            delete przyjazdy[pojazdy[i]];
            delete odjazdy[pojazdy[i]];
        }
        pojazdy.clear();
    }
};


#endif //PROJEKTKONCOWY_STACJA_H
