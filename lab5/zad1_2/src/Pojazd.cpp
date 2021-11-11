//
// Created by CQ07 on 2021-11-11.
//

#include "..\include\Pojazd.h"

using namespace std;

double Pojazd::najnowszaWersjaOprogramowania = 1.1;

Pojazd::Pojazd(string regNum, string name, string mark, string type, int numOfSeats):
numerRejestracyjny(regNum), nazwa(name), marka(mark), typ(type), liczbaMiejsc(numOfSeats){
    listaMiejsc = new string[numOfSeats+1];
    for(int i=1; i<=numOfSeats; i++)
    {
        listaMiejsc[i] = "puste";
    }
    zainstalowanaWersjaOprogramowania = 1.0;
    najnowszaWersjaOprogramowania = 1.1;
}
Pojazd::Pojazd(Pojazd &pojazd)
{
    numerRejestracyjny=pojazd.numerRejestracyjny;
    nazwa = pojazd.nazwa;
    marka = pojazd.marka;
    typ = pojazd.typ;
    liczbaMiejsc = pojazd.liczbaMiejsc;
    listaMiejsc = new string[liczbaMiejsc+1];
    for(int i=1; i<=liczbaMiejsc; i++)
    {
        listaMiejsc[i]=pojazd.listaMiejsc[i];
    }
}
void Pojazd::printPojazd()const
{
    cout<<endl;
    cout<<"nazwa: "<<nazwa<<", numer rejestracyjny: "<< numerRejestracyjny<<", marka: "<<marka<<", typ: "<<typ<<endl;
    cout<<"Pasazerowie: "<<endl;
    for(int i=1; i<=liczbaMiejsc; i++)
    {
        cout<<i<<": "<<listaMiejsc[i]<<", ";
    }
    cout<<endl;
}
void Pojazd::printWersjaOprogramowania() const
{
    cout<<endl<<"Zainstalowana wersja oprogramowania: "<< zainstalowanaWersjaOprogramowania<<endl;
}
void Pojazd::zaktualizujOprogramowanie()
{
    zainstalowanaWersjaOprogramowania=najnowszaWersjaOprogramowania;
}
void Pojazd::opublikujNoweOprogramowanie(double noweOprogramowanie)
{
    najnowszaWersjaOprogramowania=noweOprogramowanie;
}
void Pojazd::changePerson(const int num, const string newPerson)
{
    listaMiejsc[num]=newPerson;
}
void Pojazd::setNumerRejestracyjny(const string newNum)
{
    numerRejestracyjny = newNum;
}
void Pojazd::setNazwa(const string newName)
{
    nazwa=newName;
}

string Pojazd::getNumerRejestracyjny()const
{
    return numerRejestracyjny;
}
string Pojazd::getNazwa()const
{
    return nazwa;
}
string Pojazd::getMarka()const
{
    return marka;
}
string Pojazd::getTyp()const
{
    return typ;
}
