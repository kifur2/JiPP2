#include <iostream>

using namespace std;

class Klasa
{
public:
    int *tab = new int[1024];
    Klasa(){cout<<"konstruktor nie zostal wywolany"<<endl;}
    static void pause()
    {
        system("pause");
    }
    ~Klasa(){cout<<"Dowolny tekst"<<endl; delete[]tab;}
};

int main()
{
    Klasa();
    Klasa::pause();
    return 0;
}
