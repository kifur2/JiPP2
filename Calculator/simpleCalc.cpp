//
// Created by CQ07 on 2021-10-14.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char * pKoniec;
bool blad = false;

long to_long(const char * num)
{
    long x =strtol(num, &pKoniec,0);
    if(*pKoniec) blad = true;
    return x;

}

void print_help()
{
    cout<<endl<< "Simple calculator" << endl;
    cout<<"simpleCalc [nazwa dzialania]"<<endl<<endl;
    cout<<"Dzialania:"<<endl;
    cout<<"add [a] [b]"<<endl;
    cout<<"\tDodawanie dwoch liczb ([a] i [b]) calkowitych."<<endl;
    cout<<"substract [a] [b]"<<endl;
    cout<<"\tOdejmowanie dwoch liczb ([a] i [b]) calkowitych."<<endl;
    cout<<"volume [a] [b] [h] [H]"<<endl;
    cout<<"\tObliczanie objetosci graniastoslupa prostego o podstawie trapezu: pierwsza podstawa ([a]), "<<endl;
    cout<<"\tdruga podstawa ([b]), wysokosc trapezu ([h]) i graniastoslupa ([H]) musza byc calkowite."<<endl;
    cout<<"help"<<endl;
    cout<<"\tWyswietlenie okna pomocy."<<endl;
}
void zle()
{
    cout<< "Niewlasciwe parametry"<<endl;
    print_help();
}

int main(int argc, char *argv[])
{

    if(strcmp( argv[1], "add")==0)
    {
        if(argc!=4) zle();
        else
        {
            long x = to_long(argv[2]);
            long y = to_long(argv[3]);
            if(!blad)
            cout<< argv[2] << " + "<<argv[3] <<" = "<< x + y <<endl;
            else zle();
        }
    }
    else
        if(strcmp( argv[1], "substract")==0)
        {
            if(argc!=4) zle();
            else
            {
                long x = to_long(argv[2]);
                long y = to_long(argv[3]);
                if(!blad)
                    cout<< argv[2] << " - "<<argv[3] <<" = "<< x - y <<endl;
                else
                    zle();
            }
        }
        else
            if(strcmp( argv[1], "volume")==0)
            {
                if(argc!=6) zle();
                else
                {
                    long x = to_long(argv[2]);
                    long y = to_long(argv[3]);
                    long h = to_long(argv[4]);
                    long H = to_long(argv[5]);
                    if(!blad)
                    {
                        cout<< "volume for a = "<< x<<", b = "<<y<<", h = "<<h<<", H = "<<H<<" equals ";
                        cout<< (double)(x+y)* h*H/2<<endl;
                    }
                    else
                        zle();
                }
            }
            else
                if(strcmp( argv[1], "help")==0)
                {
                    print_help();
                }
                else
                {
                    cout<<"Brak pasujacej funkcji"<<endl;
                    print_help();
                }

   /* for(int i = 0; i < argc ; ++i) {
        cout << argv[i] <<endl;
    }*/

    return 0;
}