#include <iostream>
#include "Czas.h"
#include "Pojazd.h"
#include "Stacja.h"
#include <vector>
#include <fstream>
using namespace std;
void print_help();
void czyszczenie();
bool wpiszCzas();
Stacja* szukajStacji(string &nazwa);
void wyswietlTabliceOdCzasu(Stacja* stacja, Czas* czas);
void stdin_clear();
string wpiszDoStringa();

vector<Stacja*> stacje2,*tempStacje;
vector<Pojazd*> pojazdy2;
map<string, Stacja*> stacje;
map <string, Pojazd*> pojazdy;
map<string, pair<Czas*, Czas*>> *czasy;
string czas;
int godzina, minuta, iter=0;
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
    maksLiczbaPasazerow, tempInt;
    double predkoscMaks, masaNetto, masaNarzedzi, maksMasaBagazy, maksMasaZaladunku;
    pair<string, string> *gdzie;
    Stacja* nowaStacja;
    PociagOsobowy* nowyPojazd1;
    PociagTowarowy* nowyPojazd2;
    PociagTechniczny* nowyPojazd3;
    Czas* nowyCzas;
    bool petla = true, blad = false;

    print_help();

    while(petla)
    {
        cout<<"Podaj numer opcji:"<<endl;
        cin>>numer;
        if(cin.fail()){
            //cout<<"Podano niewlasciwy numer opcji"<<endl;
            numer=11;
            stdin_clear();
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
                            cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                            i--;
                            continue;
                        }
                        nowyCzas = new Czas(godzina,minuta);
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
                tempStacje = new vector<Stacja*>;
                for(int i = 0; i< liczbaStacji; i++)
                {
                    cin>>nazwa2;
                    if(!(nowaStacja = szukajStacji(nazwa2)))
                    {
                        cout<<"Niewlasciwa nazwa stacji - taka stacja nie istnieje, sprobuj jeszcze raz"<<endl;
                        i--;
                        continue;
                    }
                    tempStacje->push_back(nowaStacja);
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
                        czasy =new map <string, pair<Czas*, Czas*>>;
                        for(int i = 0; i< tempStacje->size(); i++)
                        {
                            cout<<"Podaj godzine zatrzymania na stacji "<<tempStacje->at(i)->getNazwa()<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas(godzina,minuta);
                            (*czasy)[(tempStacje->at(i)->getNazwa())].first = nowyCzas;
                            cout<<"Podaj godzine odjazdu na stacji "<<tempStacje->at(i)->getNazwa()<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas(godzina,minuta);
                            (*czasy)[tempStacje->at(i)->getNazwa()].second = nowyCzas;
                        }
                        typPojazdu="PociagOsobowy";
                        nowyPojazd1 = new PociagOsobowy(typPojazdu,nazwa, liczbaStacji, tempStacje, predkoscMaks,
                        masaNetto, maksLiczbaPasazerow, maksMasaBagazy, czasy);
                        pojazdy[nazwa]=nowyPojazd1;
                        pojazdy2.push_back(nowyPojazd1);
                        for(int i=0; i<liczbaStacji; i++)
                        {
                            tempStacje->at(i)->dodajPojazd(nazwa);
                            tempStacje->at(i)->dodajPrzyjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].first);
                            tempStacje->at(i)->dodajOdjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].second);
                        }
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
                        cout<<"Podaj liczbe stacji, na ktorych pociag sie zatrzymuje:"<<endl;
                        cin>>liczbaStacji;
                        if(cin.fail()){
                            cout<<"Podano niewlasciwa liczbe stacji"<<endl;
                            break;
                        }
                        cout<<"Podawaj czasy zatrzymania i odjazdu na konkretnej stacji:"<<endl;
                        czasy =new map <string, pair<Czas*, Czas*>>;
                        for(int i = 0; i< tempStacje->size(); i++)
                        {
                            cout<<"Podaj godzine zatrzymania na stacji "<<tempStacje->at(i)->getNazwa()<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas(godzina,minuta);
                            (*czasy)[(tempStacje->at(i)->getNazwa())].first = nowyCzas;
                            cout<<"Podaj godzine odjazdu na stacji "<<tempStacje->at(i)->getNazwa()<<"(hh:mm):"<<endl;
                            cin>>czas;
                            if(wpiszCzas()){
                                cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas(godzina,minuta);
                            (*czasy)[tempStacje->at(i)->getNazwa()].second = nowyCzas;
                        }
                        typPojazdu="PociagTowarowy";
                        nowyPojazd2 = new PociagTowarowy(typPojazdu,nazwa, liczbaStacji, tempStacje, predkoscMaks,
                        masaNetto, maksMasaZaladunku,typZaladunku, czasy);
                        pojazdy[nazwa]=nowyPojazd2;
                        pojazdy2.push_back(nowyPojazd2);
                        for(int i=0; i<liczbaStacji; i++)
                        {
                            tempStacje->at(i)->dodajPojazd(nazwa);
                            tempStacje->at(i)->dodajPrzyjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].first);
                            tempStacje->at(i)->dodajOdjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].second);
                        }
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
                        nowyPojazd3 = new PociagTechniczny(typPojazdu, nazwa, liczbaStacji, tempStacje,
                        predkoscMaks, masaNetto,typUsterki, gdzie, masaNarzedzi);
                        pojazdy[nazwa]=nowyPojazd3;
                        pojazdy2.push_back(nowyPojazd3);
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
                stacje2.push_back(nowaStacja);
                cout<<"Stacja zostala utworzona"<<endl;
                break;
            case 4:
                cout<<"Podaj nazwe pojazdu, ktory chcesz usunac ze spisu:"<<endl;
                cin>>nazwa;
                pojazdy[nazwa] = nullptr;
                cout<<"Usuniecie pojazdu powiodlo sie"<<endl;
                break;
            case 5:
                cout<<"Podaj nazwe stacji, ktora chcesz usunac ze spisu:"<<endl;
                cin>>nazwa;
                stacje[nazwa] = nullptr;
                cout<<"Usuniecie Stacji powiodlo sie"<<endl;
                break;
            case 6:
                for(int i = 0; i<pojazdy2.size(); i++)
                    if(pojazdy[pojazdy2[i]->getNazwa()]!=nullptr)
                    {
                        cout<<*(pojazdy2[i])<<" maksMasa = ";
                        if(pojazdy2[i]->getTypPojazdu()=="PociagOsobowy")
                            cout<<((PociagOsobowy*)pojazdy2[i])->getMaksMasa()<<endl;
                        else
                        if(pojazdy2[i]->getTypPojazdu()=="PociagTowarowy")
                            cout<<((PociagTowarowy*)pojazdy2[i])->getMaksMasa()<<endl;
                        else
                            cout<<((PociagTechniczny*)pojazdy2[i])->getMaksMasa()<<endl;
                    }
                    else
                        delete (pojazdy2[i]);
                break;
            case 7:
                for(int i = 0; i<stacje2.size(); i++)
                    if(stacje[stacje2[i]->getNazwa()]!=nullptr)
                    cout<<*(stacje2[i])<<endl;
                    else
                        delete (stacje2[i]);
                break;
            case 8:
                cout<<"Podaj nazwe pliku do jakiego chcesz zapisać dane:"<<endl;
                cin>>plik;
                file1.open(plik,ios::out);
                if(file1.fail()){
                    cout<<"Blad otwierania pliku"<<endl;
                    break;
                }
                file1 << stacje2.size()<<endl;
                for(int i=0; i<stacje2.size(); i++)
                {
                    file1<< stacje2[i]->getNazwa()<<endl;
                    file1<< stacje2[i]->getLiczbaPeronow()<<endl;
                }
                file1<< pojazdy2.size()<<endl;
                for(int i=0; i<pojazdy2.size(); i++)
                {
                    file1<<pojazdy2[i]->getTypPojazdu()<<endl;
                    file1<<pojazdy2[i]->getNazwa()<<endl;
                    file1<<to_string(pojazdy2[i]->getLiczbaStacji())<<endl;
                    for(int j=0; j<pojazdy2[i]->getLiczbaStacji(); j++)
                    {
                        file1<<(pojazdy2[i]->getTrasa()->at(j))->getNazwa()<<endl;
                    }
                    file1<<to_string(pojazdy2[i]->getPredkoscMaks())<<endl;
                    file1<<to_string(pojazdy2[i]->getMasaNetto())<<endl;
                    if(pojazdy2[i]->getTypPojazdu()=="PociagOsobowy")
                    {
                        file1<<((PociagOsobowy*)pojazdy2[i])->getMaksLiczbaPasazerow()<<endl;
                        file1<<((PociagOsobowy*)pojazdy2[i])->getMaksMasaBagazy()<<endl;
                        for(int j=0; j<pojazdy2[i]->getLiczbaStacji(); j++)
                        {
                            file1<<(pojazdy2[i]->getTrasa()->at(j))->getNazwa()<<endl;
                            if(((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getGodzina()<9)
                                file1<<0;
                            file1<<((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getGodzina()<<":";
                            if(((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getMinuta()<9)
                            file1<<0;
                            file1<<((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getMinuta();
                            file1<<endl;
                            if(((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getGodzina()<9)
                                file1<<0;
                            file1<<((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getGodzina()<<":";
                            if(((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getMinuta()<9)
                                file1<<0;
                            file1<<((PociagOsobowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getMinuta();
                            file1<<endl;
                        }
                    }
                    else
                        if(pojazdy2[i]->getTypPojazdu()=="PociagTowarowy")
                        {
                            file1<<((PociagTowarowy*)pojazdy2[i])->getMaksMasaZaladunku()<<endl;
                            file1<<((PociagTowarowy*)pojazdy2[i])->getTypZaladunku()<<endl;
                            for(int j=0; j<pojazdy2[i]->getLiczbaStacji(); j++)
                            {
                                file1<<(pojazdy2[i]->getTrasa()->at(j))->getNazwa()<<endl;
                                if(((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getGodzina()<9)
                                    file1<<0;
                                file1<<((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getGodzina()<<":";
                                if(((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getMinuta()<9)
                                    file1<<0;
                                file1<<((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).first->getMinuta();
                                file1<<endl;
                                if(((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getGodzina()<9)
                                    file1<<0;
                                file1<<((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getGodzina()<<":";
                                if(((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getMinuta()<9)
                                    file1<<0;
                                file1<<((PociagTowarowy*)pojazdy2[i])->getCzasy()->at((pojazdy2[i]->getTrasa()->at(j))->getNazwa()).second->getMinuta();
                                file1<<endl;
                            }
                        }
                        else
                        {
                            file1<<((PociagTechniczny*)pojazdy2[i])->getTypUsterki()<<endl;
                            file1<<((PociagTechniczny*)pojazdy2[i])->getGdzie()->first<<endl;
                            file1<<((PociagTechniczny*)pojazdy2[i])->getGdzie()->second<<endl;
                            file1<<to_string(((PociagTechniczny*)pojazdy2[i])->getMasaNarzedzi())<<endl;
                        }
                }
                file1.close();
                break;
            case 9:
                cout<<"Podaj nazwe pliku z jakiego chcesz pobrac dane:"<<endl;
                cin>>plik;
                czyszczenie();
                file2.open(plik,ios::in);
                if(file1.fail()){
                    cout<<"Blad otwierania pliku"<<endl;
                    break;
                }
                //file2>>zapis;
                //iter=0;
                tempInt = stoi(wpiszDoStringa());
                for(int i=0; i<tempInt; i++)
                {
                    nazwa = wpiszDoStringa();
                    liczbaPeronow = stoi(wpiszDoStringa());
                    nowaStacja = new Stacja(nazwa, liczbaPeronow);
                    stacje[nazwa]=nowaStacja;
                    stacje2.push_back(nowaStacja);
                }
                tempInt = stoi(wpiszDoStringa());
                for(int i=0; i<tempInt; i++)
                {
                    typPojazdu = wpiszDoStringa();
                    nazwa = wpiszDoStringa();
                    liczbaStacji = stoi(wpiszDoStringa());
                    tempStacje = new vector <Stacja*>;
                    for (int j = 0; j < liczbaStacji; j++)
                    {
                        nazwa2 = wpiszDoStringa();
                        tempStacje->push_back(szukajStacji(nazwa2));
                    }
                    predkoscMaks = stod(wpiszDoStringa());
                    masaNetto = stod(wpiszDoStringa());
                    if(typPojazdu == "PociagOsobowy")
                    {
                        maksLiczbaPasazerow=stoi(wpiszDoStringa());
                        maksMasaBagazy=stod(wpiszDoStringa());
                        czasy =new map <string, pair<Czas*, Czas*>>;
                        for(int j=0; j<liczbaStacji; j++)
                        {
                            wpiszDoStringa();
                            czas = wpiszDoStringa();
                            if(wpiszCzas()){
                                cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas(godzina,minuta);
                            (*czasy)[tempStacje->at(i)->getNazwa()].first = nowyCzas;

                            czas = wpiszDoStringa();
                            if(wpiszCzas()){
                                cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                i--;
                                continue;
                            }
                            nowyCzas = new Czas(godzina,minuta);
                            (*czasy)[tempStacje->at(i)->getNazwa()].second = nowyCzas;
                        }
                        nowyPojazd1 = new PociagOsobowy(typPojazdu,nazwa, liczbaStacji, tempStacje, predkoscMaks,
                                                        masaNetto, maksLiczbaPasazerow, maksMasaBagazy, czasy);
                        pojazdy[nazwa]=nowyPojazd1;
                        pojazdy2.push_back(nowyPojazd1);
                        for(int i=0; i<liczbaStacji; i++)
                        {
                            tempStacje->at(i)->dodajPojazd(nazwa);
                            tempStacje->at(i)->dodajPrzyjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].first);
                            tempStacje->at(i)->dodajOdjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].second);
                        }
                    }
                    else
                        if(typPojazdu == "PociagTowarowy")
                        {
                            maksMasaZaladunku = stod(wpiszDoStringa());
                            typZaladunku = wpiszDoStringa();
                            czasy =new map <string, pair<Czas*, Czas*>>;
                            for(int j=0; j<liczbaStacji; j++)
                            {
                                wpiszDoStringa();
                                czas = wpiszDoStringa();
                                if(wpiszCzas()){
                                    cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                    i--;
                                    continue;
                                }
                                nowyCzas = new Czas(godzina,minuta);
                                (*czasy)[tempStacje->at(i)->getNazwa()].first = nowyCzas;

                                czas = wpiszDoStringa();
                                if(wpiszCzas()){
                                    cout << "Niewlasciwie wpisany czas, powtorz:" << endl;
                                    i--;
                                    continue;
                                }
                                nowyCzas = new Czas(godzina,minuta);
                                (*czasy)[tempStacje->at(i)->getNazwa()].second = nowyCzas;
                            }
                            nowyPojazd2 = new PociagTowarowy(typPojazdu,nazwa, liczbaStacji, tempStacje, predkoscMaks,
                                                             masaNetto, maksMasaZaladunku,typZaladunku, czasy);
                            pojazdy[nazwa]=nowyPojazd2;
                            pojazdy2.push_back(nowyPojazd2);
                            for(int i=0; i<liczbaStacji; i++)
                            {
                                tempStacje->at(i)->dodajPojazd(nazwa);
                                tempStacje->at(i)->dodajPrzyjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].first);
                                tempStacje->at(i)->dodajOdjazd(nazwa,(*czasy)[(tempStacje->at(i)->getNazwa())].second);
                            }
                        }
                        else
                        {
                            typUsterki = wpiszDoStringa();
                            gdzie = new pair<string, string>;
                            gdzie->first = wpiszDoStringa();
                            gdzie->second = wpiszDoStringa();
                            masaNarzedzi = stod(wpiszDoStringa());
                            nowyPojazd3 = new PociagTechniczny(typPojazdu, nazwa, liczbaStacji, tempStacje,
                                                               predkoscMaks, masaNetto,typUsterki, gdzie, masaNarzedzi);
                            pojazdy[nazwa]=nowyPojazd3;
                            pojazdy2.push_back(nowyPojazd3);
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
    if(czas[0] - '0' >= 0 && czas[0] - '0'<=9)
    {
        godzina+=10*(czas[0]-'0');
    }
    else
        return true;
    if(czas[1] - '0' >= 0 && czas[1] - '0'<=9)
    {
        godzina+=(czas[1]-'0');
    }
    else
        return true;
    if(czas[3] - '0' >= 0 && czas[3] - '0'<=9)
    {
        minuta+=10*(czas[3]-'0');
    }
    else
        return true;
    if(czas[4] - '0' >= 0 && czas[4] - '0'<=9)
    {
        minuta+=(czas[4]-'0');
    }
    else
        return true;
    return false;
}
void wyswietlTabliceOdCzasu(Stacja* stacja, Czas* czas){
    int i=0;
    while(!stacja->tablicapom.empty()){
        stacja->tablica.push(stacja->tablica.top());
        stacja->tablica.pop();
    }
    while(!stacja->tablica.empty())
    {
        if (i<5 && stacja->tablica.top().second<czas)
            cout<<*(pojazdy[stacja->tablica.top().first])<<" "<< *(stacja->tablica.top().second)<<endl;
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
    if(!(pojazdy2.empty()))
    pojazdy2.clear();
    if(!(stacje2.empty()))
    stacje2.clear();
    if(tempStacje!= nullptr && !(tempStacje->empty()))
    tempStacje->clear();
    if(czasy!=nullptr && !(czasy->empty()))
    czasy->clear();
}
void stdin_clear()
{
    int ch;
    while ((ch = getchar()) != '\n')
    {
        ;
    }
}

string wpiszDoStringa(){
    //int ch;
    string nowyString;
    /*while(!file2.eof() && (ch = zapis[iter]) != ',')
    {
        nowyString +=ch;
        iter++;
    }
    iter++;*/
    if(!file2.eof())
    {
        file2 >> nowyString;
    }
    return nowyString;
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