//
// Created by CQ07 on 2022-01-17.
//

#ifndef PROJEKTKONCOWY_POJAZD_H
#define PROJEKTKONCOWY_POJAZD_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Czas.h"
#include "Stacja.h"
using namespace std;

class Pojazd {
protected:
    string typPojazdu;
    string nazwa;
    int liczbaStacji;
    vector <Stacja*> *trasa;
    double predkoscMaks, masaNetto;
public:
    Pojazd(string &typPojazdu,string &nazwa, int liczbaStacji, vector<Stacja*> *trasa, double predkoscMaks, double masaNetto):
    typPojazdu(typPojazdu),nazwa(nazwa), liczbaStacji(liczbaStacji), trasa(trasa), predkoscMaks(predkoscMaks), masaNetto(masaNetto){};
    virtual double getMaksMasa() = 0;
    double getPredkoscMaks();
    double getMasaNetto();
    string getTypPojazdu();
    int getLiczbaStacji();
    vector <Stacja*>* getTrasa();
    string getNazwa();
    friend ostream &operator<<(ostream &lhs, const Pojazd &rhs);
    virtual ~Pojazd(){
        trasa->clear();
    }
};

class PociagOsobowy:public Pojazd{
private:
    int  maksLiczbaPasazerow;
    double maksMasaBagazy;
    map <string, pair<Czas*,Czas*>> *czasy;
public:
    PociagOsobowy(string &typPojazdu,string &nazwa, int liczbaStacji, vector<Stacja*> *trasa, double predkoscMaks,
                  double masaNetto, int  maksLiczbaPasazerow, double maksMasaBagazy,
                  map <string, pair<Czas*,Czas*>> *czasy):
                  Pojazd(typPojazdu,nazwa, liczbaStacji, trasa, predkoscMaks, masaNetto),
                  maksLiczbaPasazerow(maksLiczbaPasazerow), maksMasaBagazy(maksMasaBagazy),
                  czasy(czasy){};
    double getMaksMasa();
    map<string, pair<Czas*, Czas*>>* getCzasy();
    int getMaksLiczbaPasazerow();
    double getMaksMasaBagazy();
    ~PociagOsobowy(){
        for(int i=0; i<trasa->size(); i++)
        {
            delete (*czasy)[trasa->at(i)->getNazwa()].first;
            delete (*czasy)[trasa->at(i)->getNazwa()].second;
        }
    }
};
class PociagTowarowy:public Pojazd{
private:
    double  maksMasaZaladunku;//w kg
    string typZaladunku;
    map <string, pair<Czas*,Czas*>> *czasy;
public:
    PociagTowarowy(string &typPojazdu,string &nazwa, int liczbaStacji, vector<Stacja*> *trasa, double predkoscMaks,
    double masaNetto, double  maksMasaZaladunku, string &typZaladunku,
            map <string, pair<Czas*, Czas*>> *czasy):
    Pojazd(typPojazdu,nazwa, liczbaStacji, trasa, predkoscMaks, masaNetto),
    maksMasaZaladunku(maksMasaZaladunku), typZaladunku(typZaladunku),czasy(czasy){};
    map<string, pair<Czas*, Czas*>>* getCzasy();
    double getMaksMasa();
    double getMaksMasaZaladunku();
    string getTypZaladunku();
    ~PociagTowarowy(){
        for(int i=0; i<trasa->size(); i++)
        {
            delete (*czasy)[trasa->at(i)->getNazwa()].first;
            delete (*czasy)[trasa->at(i)->getNazwa()].second;
        }
    }
};
class PociagTechniczny:public Pojazd{
private:
    string typUsterki;
    pair <string, string>* gdzie; // pomiedzy ktorymi stacjami
    double masaNarzedzi;
public:
    PociagTechniczny(string &typPojazdu,string &nazwa, int liczbaStacji, vector<Stacja*> *Trasa, double predkoscMaks,
    double masaNetto, string &typUsterki, pair<string, string>* gdzie, double masaNarzedzi):
    Pojazd(typPojazdu,nazwa, liczbaStacji, Trasa, predkoscMaks, masaNetto),
    typUsterki(typUsterki), gdzie(gdzie), masaNarzedzi(masaNarzedzi){};
    double getMaksMasa();
    string getTypUsterki();
    pair<string, string>* getGdzie();
    double getMasaNarzedzi();
    ~PociagTechniczny(){
        delete gdzie;
    }
};
#endif //PROJEKTKONCOWY_POJAZD_H
