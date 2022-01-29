//
// Created by CQ07 on 2022-01-17.
//

#include "Pojazd.h"
#define MASA_CZLOWIEKA 100


double Pojazd::getPredkoscMaks(){
    return predkoscMaks;
}
double Pojazd::getMasaNetto(){
    return masaNetto;
}
string Pojazd::getTypPojazdu(){
    return typPojazdu;
}
int Pojazd::getLiczbaStacji(){
    return liczbaStacji;
}
vector <string>* Pojazd::getTrasa(){
    return trasa;
}
string Pojazd::getNazwa(){
    return nazwa;
}

ostream &operator<<(ostream &lhs, const Pojazd &rhs){
    string x,y;
    if(rhs.trasa->size()==0)
    {
        lhs<<rhs.nazwa;
        return lhs;
    }
    for(int i=0; i<rhs.trasa->size(); i++){
        if(stacje[rhs.trasa->at(i)]){
            x=rhs.trasa->at(i);
            break;
        }
    }
    for(int i=rhs.trasa->size()-1; i>=0; i--){
        if(stacje[rhs.trasa->at(i)]){
            y=rhs.trasa->at(i);
            break;
        }
    }
    lhs << rhs.nazwa <<" z "<<x<<" do " << y;
    return lhs;
}

double PociagOsobowy::getMaksMasa() {
    return masaNetto+(maksMasaBagazy+maksLiczbaPasazerow*MASA_CZLOWIEKA);
}
map<string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>>* PociagOsobowy::getCzasy(){
    return czasy;
}
int PociagOsobowy::getMaksLiczbaPasazerow(){
    return maksLiczbaPasazerow;
}
double PociagOsobowy::getMaksMasaBagazy(){
    return maksMasaBagazy;
}
double PociagTowarowy::getMaksMasa(){
    return masaNetto+maksMasaZaladunku+4*MASA_CZLOWIEKA;
}
map<string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>>* PociagTowarowy::getCzasy(){
    return czasy;
}
double PociagTowarowy::getMaksMasaZaladunku(){
    return maksMasaZaladunku;
}
string PociagTowarowy::getTypZaladunku(){
    return typZaladunku;
}
double PociagTechniczny::getMaksMasa(){
    return masaNetto+masaNarzedzi+2*MASA_CZLOWIEKA;
}
string PociagTechniczny::getTypUsterki(){
    return typUsterki;
}
pair<string, string>* PociagTechniczny::getGdzie(){
    return gdzie;
}
double PociagTechniczny::getMasaNarzedzi(){
    return masaNarzedzi;
}