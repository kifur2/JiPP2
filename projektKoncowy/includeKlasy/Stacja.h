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
    map <string, Czas*> przyjazdy;
    map <string, Czas*> odjazdy;
    priority_queue<pair<string,Czas*>,vector< pair<string,Czas*>>, porownanieCzasow> tablica;
    priority_queue<pair<string,Czas*>,vector< pair<string,Czas*>>, porownanieCzasow> tablicapom;
public:
    Stacja():nazwa("pusty"), liczbaPeronow(0){};
    Stacja(string &nazwa, int liczbaPeronow):
    nazwa(nazwa), liczbaPeronow(liczbaPeronow){
        /*for(int i=0; i<pojazdy.size(); i++)
        {
            for(int j =0; j<przyjazdy[pojazdy[i].getNazwa].size(); j++)
            {
                tablica.push(pair(pojazdy[i].getNazwa, przyjazdy[pojazdy[i].getNazwa][j]));
            }
        }*/
    }
    string getNazwa();
    void dodajPojazd(string &poj);
    void dodajPrzyjazd(string &poj, Czas* czas);
    void dodajOdjazd(string &poj, Czas* czas);
    int getLiczbaPeronow();
    friend void wyswietlTabliceOdCzasu(Stacja* stacja, Czas* czas);
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
