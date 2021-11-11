#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

void txt_to_num(char * tekst)
{
    long x = strtol(tekst, NULL, 0);
    if(tekst[0]=='0' && strlen(tekst)==1)
    {
        cout<<"Ta liczba to "<< x <<endl;
    }
    else
    {
        if(x==0L )
        {
            throw "Wprowadzony ciag zawiera nieprawidlowe znaki";
        }
        else
        if(x==LONG_MAX || x==LONG_MIN)
            throw "Wprowadzona liczba jest za duza lub zbyt mala";
        else
            cout<<"Ta liczba to "<< x <<endl;
    }
}

int main()
{
    char *  txt = new char[100];
    cout<<"Podaj liczbe: "<<endl;
    cin>> txt;
    try
    {
        txt_to_num(txt);
    }
    catch(const char * msg)
    {
        cout<<msg<<endl;
    }

    delete [] txt;
    return 0;
}
