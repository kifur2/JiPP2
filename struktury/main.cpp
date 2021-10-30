#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;
string tablica_marek[2137];
int licz = 0;

struct samochod{
    string marka, model, kolor;
    int rok_produkcji, pojemnosc_baku;

};
map <string, int> my_fun(samochod *tab, int n)
{
    map <string, int> liczby;
    for(int i=0; i<n; i++)
    {
        if(liczby[tab[i].marka]==0)
        {
            tablica_marek[licz]=tab[i].marka;
            licz++;
        }
        liczby[tab[i].marka]++;
    }
    return liczby;
}

int lowestYear(samochod *tab, int n)
{
    int mini=2147483647;
    for(int i=0; i<n; i++)
    {
        if(tab[i].rok_produkcji<mini)
            mini=tab[i].rok_produkcji;
    }
    return mini;
}

int main()
{
    int n;
    cin>>n;
    samochod tab[n];
    tab[0]= {"Opel", "Astra", "srebrny", 2002, 20};
    tab[1]= {"Peugeot", "Vectra", "bialy", 2012,10};
    tab[2]= {"BMW", "Beta", "zolty", 2007,36};
    tab[3]= {"Reno", "Bordo", "rozowy", 2009,11};
    for(int i=4; i<n; i++)
    {
        cout<<"Podaj marke, nazwe modelu, kolor, rok produkcji i pojemnosc baku:"<<endl;
        cin>>tab[i].marka;
        cin>>tab[i].model;
        cin>>tab[i].kolor;
        cin>>tab[i].rok_produkcji;
        cin>>tab[i].pojemnosc_baku;
    }
    map<string, int> marki = my_fun(tab,n);
    cout<<"ile czego jest:"<<endl;
    for(int i=0; i<licz; i++)
        cout<<setw(10)<<tablica_marek[i]<<setw(10)<<marki[tablica_marek[i]]<<endl<<endl;
    cout<<"najmniejszy rok: "<<lowestYear(tab,n)<<endl<<endl;
    cout<<setw(10)<<"marka"<<setw(15)<<"model"<<setw(15)<<"kolor"<<setw(15)<<"rok produkcji"<<setw(20)<<"pojemnosc baku"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<setw(10)<<tab[i].marka<<setw(15)<<tab[i].model<<setw(15)<<tab[i].kolor<<setw(15)<<tab[i].rok_produkcji;
        cout<<setw(20)<<tab[i].pojemnosc_baku<<endl;
    }
    return 0;
}
