#include <iostream>
#include "Pojazd.h"

int main()
{
    Pojazd pojazd1("KR 683KV", "pojazd1", "VolksWagen", "Mily", 7);
    pojazd1.printPojazd();
    Pojazd pojazd2 = pojazd1;
    pojazd2.setNazwa("pojazd2");
    pojazd1.setNumerRejestracyjny("KS 444SJ");
    pojazd1.changePerson(1, "Madzia");
    pojazd1.changePerson(2, "Tata");
    cout<<endl<<"***ZMIANA***"<<endl<<endl;
    pojazd1.printPojazd();
    pojazd2.printPojazd();

    pojazd1.printWersjaOprogramowania();
    pojazd1.zaktualizujOprogramowanie();
    pojazd1.printWersjaOprogramowania();
    pojazd1.opublikujNoweOprogramowanie(2.0);
    pojazd1.zaktualizujOprogramowanie();
    pojazd1.printWersjaOprogramowania();

    return 0;
}
