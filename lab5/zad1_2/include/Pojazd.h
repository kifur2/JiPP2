//
// Created by CQ07 on 2021-11-11.
//

#ifndef ZAD1_2_POJAZD_H
#define ZAD1_2_POJAZD_H

#include <iostream>
#include <cstring>

using namespace std;

class Pojazd
{
    string numerRejestracyjny, nazwa, marka, typ;
    int liczbaMiejsc;
    static double najnowszaWersjaOprogramowania;
    double zainstalowanaWersjaOprogramowania = 1.0;
    string *listaMiejsc;
public:
    Pojazd(string regNum, string name, string mark, string type, int numOfSeats);
    Pojazd(Pojazd &pojazd);
    void printPojazd()const;
    void printWersjaOprogramowania()const;
    void zaktualizujOprogramowanie();
    static void opublikujNoweOprogramowanie(double noweOprogramowanie);
    void changePerson(const int num, const string newPerson);
    void setNumerRejestracyjny(const string newNum);
    void setNazwa(const string newName);
    string getNumerRejestracyjny()const;
    string getNazwa()const;
    string getMarka()const;
    string getTyp()const;
};

#endif //ZAD1_2_POJAZD_H
