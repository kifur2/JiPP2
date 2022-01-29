#include <iostream>
#include "Czas.h"
#include "Pojazd.h"
#include "Stacja.h"
#include "MojWyjatek.h"
#include <vector>
#include <fstream>
using namespace std;
void print_help();
void czyszczenie();
bool wpiszCzas();
Stacja* szukajStacji(string &nazwa);
void wyswietlTabliceOdCzasu(Stacja* stacja, Czas<MYTYPE>* czas);
string wpiszDoStringa();
void  tworzeniePojazdu(string &typPojazdu,string &nazwa, int liczbaStacji, vector<string> *trasa, double predkoscMaks,
                       double masaNetto, int  maksLiczbaPasazerow, double maksMasaBagazy,
                       map <string, pair<Czas<MYTYPE>*,Czas<MYTYPE>*>> *czasy);
void  tworzeniePojazdu(string &typPojazdu,string &nazwa, int liczbaStacji, vector<string> *trasa, double predkoscMaks,
                       double masaNetto, double  maksMasaZaladunku, string &typZaladunku,
                       map <string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>> *czasy);
void  tworzeniePojazdu(string &typPojazdu,string &nazwa, int liczbaStacji, vector<string> *Trasa, double predkoscMaks,
                       double masaNetto, string &typUsterki, pair<string, string>* gdzie, double masaNarzedzi);


vector<Pojazd*> *pojazdy2, *tempPojazdy;
map <string, Pojazd*> pojazdy;
vector<Stacja*> *stacje2;
map<string, Stacja*> stacje;
vector<string> *tempStacje=new vector<string>;
map<string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>> *czasy;
string czas;
int godzina, minuta;
fstream file1, file2;


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout<<"ERR : Niewlasciwa liczba argumentow!"<<endl;
        exit(2);
    }
    string login=argv[1], haslo=argv[2];
    if(!(login=="admin" && haslo=="admin"))
    {
        cout<<"Nieprawidlowe login albo haslo"<<endl;
        exit(2);
    }
    string nazwa, nazwa2, typZaladunku, typUsterki, typPojazdu, plik, tempString;
    int numer = 0, wyborPociagu, liczbaPeronow, liczbaStacji,
    maksLiczbaPasazerow, tempInt, doZapisu;
    double predkoscMaks, masaNetto, masaNarzedzi, maksMasaBagazy, maksMasaZaladunku;
    pair<string, string> *gdzie;
    Stacja* nowaStacja;
    Czas<MYTYPE>* nowyCzas;
    bool petla = true, blad = false;
    stacje2 = new vector <Stacja*>;
    pojazdy2 = new vector <Pojazd*>;
    print_help();

    while(petla)
    {
        cout<<"Podaj numer opcji:"<<endl;
        cin>>numer;
        if(cin.fail()){
            numer=11;
            cin.clear();
            cin.ignore();
        }
        switch(numer)
        {
            case 1:
                for(int j=0; j<1; j++)
                {
                    cout<<"Podaj nazwe stacji:"<<endl;
                    cin>>nazwa;
                    if(!stacje[nazwa]){
                        cout<<"Podana stacja nie istnieje, sprobuj jeszcze raz"<<endl;
                        j--;
                        continue;
                    }
                    cout<<"Podaj godzine od ktorej chcesz zaczac wyswietlanie(hh:mm):"<<endl;
                    for(int i=0; i<1; i++)
                    {
                        cin>>czas;
                        if(wpiszCzas()){
                            i--;
                            continue;
                        }
                        nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                    }
                    wyswietlTabliceOdCzasu(stacje[nazwa],nowyCzas);
                }

                break;
            case 2:
                cout<<"Wybierz typ pojazdu:"<<endl;
                cout<<"1 - Pociag osobowy"<<endl;
                cout<<"2 - Pociag towarowy:"<<endl;
                cout<<"3 - Pociag techniczny:"<<endl;
                cin>>wyborPociagu;
                if(cin.fail()){
                    cout<<"Podano niewlasciwa cyfre"<<endl;
                    break;
                }
                cout<<"Podaj nazwe pociagu:"<<endl;
                cin>>nazwa;

                cout<<"Podaj maksymalna predkosc pociagu:"<<endl;
                cin>>predkoscMaks;
                if(cin.fail()){
                    cout<<"Podano niewlasciwa predkosc"<<endl;
                    break;
                }
                cout<<"Podaj mase netto pociagu:"<<endl;
                cin>>masaNetto;
                if(cin.fail()){
                    cout<<"Podano niewlasciwa mase"<<endl;
                    break;
                }
                cout<<"Podaj liczbe stacji, na ktorych pociag sie zatrzymuje:"<<endl;
                cin>>liczbaStacji;
                if(cin.fail()){
                    cout<<"Podano niewlasciwa liczbe stacji"<<endl;
                    break;
                }
                if(liczbaStacji>stacje.size()) {
                    cout<<"Nie ma tyle dostepnych stacji"<<endl;
                    break;
                }
                cout<<"Podaj nazwy stacji, na ktorych pociag sie zatrzymuje:"<<endl;
                tempStacje = new vector<string>;
                for(int i = 0; i< liczbaStacji; i++)
                {
                    cin>>nazwa2;
                    if(!(szukajStacji(nazwa2)))
                    {
                        cout<<"Niewlasciwa nazwa stacji - taka stacja nie istnieje, sprobuj jeszcze raz"<<endl;
                        i--;
                        continue;
                    }
                    tempStacje->push_back(nazwa2);
                }
                switch(wyborPociagu)
                {
                    case 1:
                        cout<<"Podaj maksymalna liczbe pasazerow:"<<endl;
                        cin>>maksLiczbaPasazerow;
                        if(cin.fail()){
                            cout<<"Podano niewlasciwa liczbe pasazerow"<<endl;
                            break;
                        }
                        cout<<"Podaj maksymalna mase bagazy:"<<endl;
                        cin>>maksMasaBagazy;
                        if(cin.fail()){
                            cout<<"Podano niewlasciwa mase bagazy"<<endl;
                            break;
                        }
                        cout<<"Podawaj czasy zatrzymania i odjazdu na konkretnej stacji:"<<endl;
                        czasy =new map <string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>>;
                        for(int i = 0; i< tempStacje->size(); i++)
                        {
                            cout<<"Podaj godzine zatrzymania na stacji "<<tempStacje->at(i)<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                            (*czasy)[(tempStacje->at(i))].first = nowyCzas;
                            cout<<"Podaj godzine odjazdu na stacji "<<tempStacje->at(i)<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                            (*czasy)[tempStacje->at(i)].second = nowyCzas;
                        }
                        typPojazdu="PociagOsobowy";
                        tworzeniePojazdu(typPojazdu, nazwa, liczbaStacji, tempStacje, predkoscMaks,
                                         masaNetto, maksLiczbaPasazerow, maksMasaBagazy, czasy);
                        break;
                    case 2:
                        cout<<"Podaj maksymalna mase zaladunku:"<<endl;
                        cin>>maksMasaZaladunku;
                        if(cin.fail()){
                            cout<<"Podano niewlasciwa mase zaladunku"<<endl;
                            break;
                        }
                        cout<<"Podaj typ zaladunku:"<<endl;
                        cin>>typZaladunku;
                        cout<<"Podawaj czasy zatrzymania i odjazdu na konkretnej stacji:"<<endl;
                        czasy =new map <string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>>;
                        for(int i = 0; i< tempStacje->size(); i++)
                        {
                            cout<<"Podaj godzine zatrzymania na stacji "<<tempStacje->at(i)<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                            (*czasy)[(tempStacje->at(i))].first = nowyCzas;
                            cout<<"Podaj godzine odjazdu na stacji "<<tempStacje->at(i)<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                            (*czasy)[tempStacje->at(i)].second = nowyCzas;
                        }
                        typPojazdu="PociagTowarowy";
                        tworzeniePojazdu(typPojazdu,nazwa, liczbaStacji, tempStacje, predkoscMaks,
                                         masaNetto, maksMasaZaladunku,typZaladunku, czasy);
                        break;
                    case 3:
                        cout<<"Podaj typ usterki:"<<endl;
                        cin>>typUsterki;
                        cout<<"Podaj mase narzedzi:"<<endl;
                        cin>>masaNarzedzi;
                        if(cin.fail()){
                            cout<<"Podano niewlasciwa mase narzedzi"<<endl;
                            break;
                        }
                        cout<<"Podaj nazwy stacji, pomiedzy ktorymi cos sie stalo:"<<endl;
                        gdzie = new pair<string, string>;
                        for(int i = 0; i<1; i++)
                        {
                            cin>>(gdzie->first)>>(gdzie->second);
                            if(!szukajStacji(gdzie->first) || !szukajStacji(gdzie->second))
                            {
                                cout<<"Podane stacje nie istnieja, sprobuj jeszcze raz:"<<endl;
                                i--;
                            }
                        }
                        typPojazdu="PociagTechniczny";
                        tworzeniePojazdu(typPojazdu, nazwa, liczbaStacji, tempStacje,
                                         predkoscMaks, masaNetto,typUsterki, gdzie, masaNarzedzi);
                        break;
                    default:
                        cout<<"Wpisales niewlasciwy numer"<<endl;
                }
                break;
            case 3:
                cout<<"Podaj nazwe stacji:"<<endl;
                cin>>nazwa;
                cout<<"Podaj liczbe peronow na stacji:"<<endl;
                cin>>liczbaPeronow;
                if(cin.fail()){
                    cout<<"Podano niewlasciwa liczbe peronow"<<endl;
                    break;
                }
                nowaStacja = new Stacja(nazwa, liczbaPeronow);
                stacje[nazwa]=nowaStacja;
                stacje2->push_back(nowaStacja);
                cout<<"Stacja zostala utworzona"<<endl;
                break;
            case 4:
                cout<<"Podaj nazwe pojazdu, ktory chcesz usunac ze spisu:"<<endl;
                cin>>nazwa;
                if(pojazdy[nazwa]==nullptr)
                    cout<<"Nie bylo takiego pojazdu"<<endl;
                else
                {
                    tempPojazdy = new vector<Pojazd*>;
                    for(int i=0; i<pojazdy2->size(); i++)
                    {
                        if(pojazdy2->at(i)->getNazwa() !=nazwa)
                        tempPojazdy->push_back(pojazdy2->at(i));
                    }
                    delete pojazdy2;
                    pojazdy2=new vector<Pojazd*>;
                    for(int i=0; i<tempPojazdy->size(); i++)
                        pojazdy2->push_back(tempPojazdy->at(i));
                    delete pojazdy[nazwa];
                    delete tempPojazdy;
                    cout << "Usuniecie pojazdu powiodlo sie" << endl;
                }
                break;
            case 5:
                cout<<"Podaj nazwe stacji, ktora chcesz usunac ze spisu:"<<endl;
                cin>>nazwa;
                if(stacje[nazwa] == nullptr)
                {
                    cout<<"Nie bylo takiej stacji"<<endl;
                }
                else
                {
                    tempStacje = new vector<string>;
                    for(int i=0; i<stacje2->size(); i++)
                    {
                        if(stacje2->at(i)->getNazwa() !=nazwa)
                            tempStacje->push_back(stacje2->at(i)->getNazwa());
                    }
                    delete stacje2;
                    stacje2=new vector<Stacja*>;
                    for(int i=0; i<tempStacje->size(); i++)
                        stacje2->push_back(stacje[tempStacje->at(i)]);
                    delete stacje[nazwa];
                    stacje[nazwa]=nullptr;
                    delete tempStacje;
                    cout << "Usuniecie Stacji powiodlo sie" << endl;
                }
                break;
            case 6:
                for(int i = 0; i<pojazdy2->size(); i++)
                    if(pojazdy[pojazdy2->at(i)->getNazwa()]!=nullptr)
                    {
                        cout<<*(pojazdy2->at(i))<<" maksMasa = ";
                        if(pojazdy2->at(i)->getTypPojazdu()=="PociagOsobowy")
                            cout<<((PociagOsobowy*)pojazdy2->at(i))->getMaksMasa()<<endl;
                        else
                        if(pojazdy2->at(i)->getTypPojazdu()=="PociagTowarowy")
                            cout<<((PociagTowarowy*)pojazdy2->at(i))->getMaksMasa()<<endl;
                        else
                            cout<<((PociagTechniczny*)pojazdy2->at(i))->getMaksMasa()<<endl;
                    }
                    else
                        delete (pojazdy2->at(i));
                break;
            case 7:
                for(int i = 0; i<stacje2->size(); i++)
                    if(stacje[stacje2->at(i)->getNazwa()]!=nullptr)
                    cout<<*(stacje2->at(i))<<endl;
                    else
                        delete (stacje2->at(i));
                break;
            case 8:
                cout<<"Podaj nazwe pliku do jakiego chcesz zapisać dane:"<<endl;
                cin>>plik;
                file1.open(plik,ios::out);
                if(file1.fail()){
                    cout<<"Blad otwierania pliku"<<endl;
                    break;
                }
                doZapisu=stacje2->size();
                for(int i=0; i<stacje2->size(); i++)
                {
                    if(stacje2->at(i)==nullptr)
                        doZapisu--;
                }
                file1 <<doZapisu<<endl;
                for(int i=0; i<stacje2->size(); i++)
                {
                    if (stacje2->at(i) != nullptr)
                    {
                        file1<< stacje2->at(i)->getNazwa()<<endl;
                        file1<< stacje2->at(i)->getLiczbaPeronow()<<endl;
                    }
                }
                doZapisu=pojazdy2->size();
                for(int i=0; i<pojazdy2->size(); i++)
                {
                    if(pojazdy2->at(i)==nullptr)
                        doZapisu--;
                }
                file1 <<doZapisu<<endl;
                for(int i=0; i<pojazdy2->size(); i++)
                {
                    if(pojazdy2->at(i)!=nullptr)
                    {
                        file1 << pojazdy2->at(i)->getTypPojazdu() << endl;
                        file1 << pojazdy2->at(i)->getNazwa() << endl;
                        doZapisu = pojazdy2->at(i)->getLiczbaStacji();
                        for(int j=0; j<pojazdy2->at(i)->getLiczbaStacji(); j++)
                        {
                            if(stacje[pojazdy2->at(i)->getTrasa()->at(j)]==nullptr)
                            {
                                doZapisu--;
                            }
                        }
                        file1 <<doZapisu<<endl;

                        for (int j = 0; j < pojazdy2->at(i)->getLiczbaStacji(); j++)
                        {
                            if(stacje[pojazdy2->at(i)->getTrasa()->at(j)]!=nullptr)
                            file1 << pojazdy2->at(i)->getTrasa()->at(j) << endl;
                        }
                        file1 << pojazdy2->at(i)->getPredkoscMaks() << endl;
                        file1 << pojazdy2->at(i)->getMasaNetto() << endl;
                        if (pojazdy2->at(i)->getTypPojazdu() == "PociagOsobowy")
                        {
                            file1 << ((PociagOsobowy *) pojazdy2->at(i))->getMaksLiczbaPasazerow() << endl;
                            file1 << ((PociagOsobowy *) pojazdy2->at(i))->getMaksMasaBagazy() << endl;

                            for (int j = 0; j < pojazdy2->at(i)->getLiczbaStacji(); j++)
                            {
                                if(stacje[pojazdy2->at(i)->getTrasa()->at(j)]==nullptr)
                                    continue;
                                nazwa = pojazdy2->at(i)->getTrasa()->at(j);
                                file1 << nazwa << endl;
                                if (((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).first->getGodzina() < 9)
                                    file1 << 0;
                                file1 << ((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).first->getGodzina() << ":";
                                if (((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).first->getMinuta() < 9)
                                    file1 << 0;
                                file1 << ((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).first->getMinuta();
                                file1 << endl;
                                if (((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).second->getGodzina() < 9)
                                    file1 << 0;
                                file1 << ((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).second->getGodzina() << ":";
                                if (((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).second->getMinuta() < 9)
                                    file1 << 0;
                                file1 << ((PociagOsobowy*)pojazdy2->at(i))->getCzasy()->at(nazwa).second->getMinuta();
                                file1 << endl;
                            }
                        } else if (pojazdy2->at(i)->getTypPojazdu() == "PociagTowarowy")
                        {
                            file1 << ((PociagTowarowy *) pojazdy2->at(i))->getMaksMasaZaladunku() << endl;
                            file1 << ((PociagTowarowy *) pojazdy2->at(i))->getTypZaladunku() << endl;
                            for (int j = 0; j < pojazdy2->at(i)->getLiczbaStacji(); j++)
                            {
                                if(stacje[pojazdy2->at(i)->getTrasa()->at(j)]==nullptr)
                                    continue;
                                nazwa = pojazdy2->at(i)->getTrasa()->at(j);
                                file1 << nazwa << endl;
                                if (((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).first->getGodzina() < 9)
                                    file1 << 0;
                                file1 << ((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).first->getGodzina() << ":";
                                if (((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).first->getMinuta() < 9)
                                    file1 << 0;
                                file1 << ((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).first->getMinuta();
                                file1 << endl;
                                if (((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).second->getGodzina() < 9)
                                    file1 << 0;
                                file1 << ((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).second->getGodzina() << ":";
                                if (((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).second->getMinuta() < 9)
                                    file1 << 0;
                                file1 << ((PociagTowarowy *) pojazdy2->at(i))->getCzasy()->at(nazwa).second->getMinuta();
                                file1 << endl;
                            }
                        } else
                        {
                            file1 << ((PociagTechniczny *) pojazdy2->at(i))->getTypUsterki() << endl;
                            file1 << ((PociagTechniczny *) pojazdy2->at(i))->getGdzie()->first << endl;
                            file1 << ((PociagTechniczny *) pojazdy2->at(i))->getGdzie()->second << endl;
                            file1 << to_string(((PociagTechniczny *) pojazdy2->at(i))->getMasaNarzedzi()) << endl;
                        }
                    }
                }
                file1.close();
                break;
            case 9:
                cout<<"Podaj nazwe pliku z jakiego chcesz pobrac dane:"<<endl;
                cin>>plik;
                //czyszczenie();
                file2.open(plik,ios::in);
                if(file1.fail()){
                    cout<<"Blad otwierania pliku"<<endl;
                    break;
                }
                tempInt = stoi(wpiszDoStringa());
                for(int i=0; i<tempInt; i++)
                {
                    nazwa = wpiszDoStringa();
                    liczbaPeronow = stoi(wpiszDoStringa());
                    nowaStacja = new Stacja(nazwa, liczbaPeronow);
                    stacje[nazwa]=nowaStacja;
                    stacje2->push_back(nowaStacja);
                }
                tempInt = stoi(wpiszDoStringa());
                for(int i=0; i<tempInt; i++)
                {
                    typPojazdu = wpiszDoStringa();
                    nazwa = wpiszDoStringa();
                    liczbaStacji = stoi(wpiszDoStringa());
                    tempStacje = new vector <string>;
                    for (int j = 0; j < liczbaStacji; j++)
                    {
                        nazwa2 = wpiszDoStringa();
                        tempStacje->push_back(nazwa2);
                    }
                    predkoscMaks = stod(wpiszDoStringa());
                    masaNetto = stod(wpiszDoStringa());
                    if(typPojazdu == "PociagOsobowy")
                    {
                        maksLiczbaPasazerow=stoi(wpiszDoStringa());
                        maksMasaBagazy=stod(wpiszDoStringa());
                        czasy =new map <string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>>;
                        for(int j=0; j<liczbaStacji; j++)
                        {
                            wpiszDoStringa();
                            czas = wpiszDoStringa();
                            if(wpiszCzas()){
                                j--;
                                continue;
                            }
                            nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                            (*czasy)[tempStacje->at(j)].first = nowyCzas;

                            czas = wpiszDoStringa();
                            if(wpiszCzas()){
                                j--;
                                continue;
                            }
                            nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                            (*czasy)[tempStacje->at(j)].second = nowyCzas;
                        }
                        tworzeniePojazdu(typPojazdu,nazwa, liczbaStacji, tempStacje, predkoscMaks,
                                         masaNetto, maksLiczbaPasazerow, maksMasaBagazy, czasy);
                    }
                    else
                        if(typPojazdu == "PociagTowarowy")
                        {
                            maksMasaZaladunku = stod(wpiszDoStringa());
                            typZaladunku = wpiszDoStringa();
                            czasy =new map <string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>>;
                            for(int j=0; j<liczbaStacji; j++)
                            {
                                wpiszDoStringa();
                                czas = wpiszDoStringa();
                                if(wpiszCzas()){
                                    j--;
                                    continue;
                                }
                                nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                                (*czasy)[tempStacje->at(j)].first = nowyCzas;

                                czas = wpiszDoStringa();
                                if(wpiszCzas()){
                                    j--;
                                    continue;
                                }
                                nowyCzas = new Czas<MYTYPE>(godzina,minuta);
                                (*czasy)[tempStacje->at(j)].second = nowyCzas;
                            }
                            tworzeniePojazdu(typPojazdu,nazwa, liczbaStacji, tempStacje, predkoscMaks,
                                             masaNetto, maksMasaZaladunku,typZaladunku, czasy);
                        }
                        else
                        {
                            typUsterki = wpiszDoStringa();
                            gdzie = new pair<string, string>;
                            gdzie->first = wpiszDoStringa();
                            gdzie->second = wpiszDoStringa();
                            masaNarzedzi = stod(wpiszDoStringa());
                            tworzeniePojazdu(typPojazdu, nazwa, liczbaStacji, tempStacje,
                                             predkoscMaks, masaNetto,typUsterki, gdzie, masaNarzedzi);
                        }
                }
                file2.close();
                break;
            case 10:
                cout<<"Koniec programu:"<<endl;
                petla = false;
                break;
            default:
                cout<<"Wpisales niewlasciwy numer, sprobuj jeszcze raz:"<<endl;
        }
    }
    czyszczenie();
    if(file1.good())
    file1.close();
    if(file2.good())
    file2.close();
}

Stacja* szukajStacji(string &nazwa)
{
    return stacje[nazwa];
}

Pojazd* szukajPojazdu(string &nazwa){
    return pojazdy[nazwa];
}

bool wpiszCzas(){
    godzina=0;
    minuta=0;
    try
    {
        if (czas[0] - '0' >= 0 && czas[0] - '0' <= 9)
        {
            godzina += 10 * (czas[0] - '0');
        } else
            throw(MojWyjatek("Niewlasciwie wpisany czas, powtorz:"));
        if (czas[1] - '0' >= 0 && czas[1] - '0' <= 9)
        {
            godzina += (czas[1] - '0');
        } else
            throw(MojWyjatek("Niewlasciwie wpisany czas, powtorz:"));
        if (czas[3] - '0' >= 0 && czas[3] - '0' <= 9)
        {
            minuta += 10 * (czas[3] - '0');
        } else
            throw(MojWyjatek("Niewlasciwie wpisany czas, powtorz:"));
        if (czas[4] - '0' >= 0 && czas[4] - '0' <= 9)
        {
            minuta += (czas[4] - '0');
        } else
            throw(MojWyjatek("Niewlasciwie wpisany czas, powtorz:"));
        if (godzina < 0 || godzina > 23 || minuta < 0 || minuta >= 60)
            throw(MojWyjatek("Niewlasciwie wpisany czas, powtorz:"));
    }
    catch (MojWyjatek wyjatek)
    {
        cout<<wyjatek.what()<<endl;
        return true ;
    }
    return false;
}
void wyswietlTabliceOdCzasu(Stacja* stacja, Czas<MYTYPE>* czas){
    int i=0;
    while(!stacja->tablicapom.empty()){
        stacja->tablica.push(stacja->tablica.top());
        stacja->tablica.pop();
    }
    while(!stacja->tablica.empty())
    {
        if (i<5 && stacja->tablica.top().second<czas)
        {
            cout<<*(pojazdy[stacja->tablica.top().first])<<" ";
            Czas<MYTYPE> rhs = *(stacja->tablica.top().second);
            if(rhs.getGodzina()>9)
                cout<<rhs.getGodzina();
            else
                cout<<"0"<<rhs.getGodzina();
            cout<<":";
            if(rhs.getMinuta()>9)
                cout<<rhs.getMinuta()<<endl;
            else
                cout<<"0"<<rhs.getMinuta()<<endl;
        }
        stacja->tablicapom.push(stacja->tablica.top());
        stacja->tablica.pop();
    }
}

void czyszczenie()
{
    if(!(stacje.empty()))
    stacje.clear();
    if(!(pojazdy.empty()))
    pojazdy.clear();
    if(!(pojazdy2->empty()))
    pojazdy2->clear();
    if(!(stacje2->empty()))
    stacje2->clear();
}

string wpiszDoStringa(){
    string nowyString;
    if(!file2.eof())
    {
        file2 >> nowyString;
    }
    return nowyString;
}
void  tworzeniePojazdu(string &typPojazdu,string &nazwa, int liczbaStacji, vector<string> *trasa, double predkoscMaks,
                       double masaNetto, int  maksLiczbaPasazerow, double maksMasaBagazy, map <string, pair<Czas<MYTYPE>*,Czas<MYTYPE>*>> *czasy)
{
    PociagOsobowy *nowyPojazd1 = new PociagOsobowy(typPojazdu,nazwa, liczbaStacji, trasa, predkoscMaks,
                                    masaNetto, maksLiczbaPasazerow, maksMasaBagazy, czasy);
    pojazdy[nazwa]=nowyPojazd1;
    pojazdy2->push_back(nowyPojazd1);
    for(int i=0; i<liczbaStacji; i++)
    {
        stacje[tempStacje->at(i)]->dodajPojazd(nazwa);
        stacje[tempStacje->at(i)]->dodajPrzyjazd(nazwa,(*czasy)[(tempStacje->at(i))].first);
        stacje[tempStacje->at(i)]->dodajOdjazd(nazwa,(*czasy)[(tempStacje->at(i))].second);
    }
}
void  tworzeniePojazdu(string &typPojazdu,string &nazwa, int liczbaStacji, vector<string> *trasa, double predkoscMaks,
                       double masaNetto, double  maksMasaZaladunku, string &typZaladunku, map <string, pair<Czas<MYTYPE>*, Czas<MYTYPE>*>> *czasy)
{
    PociagTowarowy *nowyPojazd2 = new PociagTowarowy(typPojazdu,nazwa, liczbaStacji, trasa, predkoscMaks,
                                     masaNetto, maksMasaZaladunku,typZaladunku, czasy);
    pojazdy[nazwa]=nowyPojazd2;
    pojazdy2->push_back(nowyPojazd2);
    for(int i=0; i<liczbaStacji; i++)
    {
        stacje[tempStacje->at(i)]->dodajPojazd(nazwa);
        stacje[tempStacje->at(i)]->dodajPrzyjazd(nazwa,(*czasy)[(tempStacje->at(i))].first);
        stacje[tempStacje->at(i)]->dodajOdjazd(nazwa,(*czasy)[(tempStacje->at(i))].second);
    }
}
void  tworzeniePojazdu(string &typPojazdu,string &nazwa, int liczbaStacji, vector<string> *trasa, double predkoscMaks,
                       double masaNetto, string &typUsterki, pair<string, string>* gdzie, double masaNarzedzi)
{
    PociagTechniczny *nowyPojazd3 = new PociagTechniczny(typPojazdu, nazwa, liczbaStacji, trasa,
                                       predkoscMaks, masaNetto,typUsterki, gdzie, masaNarzedzi);
    pojazdy[nazwa]=nowyPojazd3;
    pojazdy2->push_back(nowyPojazd3);
}

void print_help()
{
    cout << endl << "Menu" << endl;
    cout << "projektKoncowy.exe [login haslo]" << endl << endl;
    cout << "Dzialania w programie:" << endl;
    cout << "1 - Wyswietlania tablicy informacyjnej na stacji X od godziny Y" << endl;
    cout << "2 - Dodanie pojazdu do spisu pojazdow" << endl;
    cout << "3 - Dodanie stacji do spisu stacji" << endl;
    cout << "4 - Usuniecie rekordu pojazdu ze spisu" << endl;
    cout << "5 - Usuniecie stacji ze spisu" << endl;
    cout << "6 - Wypisz wszystkie pojazdy" << endl;
    cout << "7 - Wypisz wszystkie stacje" << endl;
    cout << "8 - Zapisanie danych programu do bazy danych" << endl;
    cout << "9 - Zapisanie danych z bazy danych do programu" << endl;
    cout << "10 - Zakonczenie programu"<< endl<<endl;
}