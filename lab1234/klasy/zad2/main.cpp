#include <iostream>
#include <math.h>

using namespace std;

class Kula
{
    double r;
public:
    Kula(double r0){r=r0;}
    double getR()
    {
        return r;
    }
    void setabc(double r) {
        this->r = r;
    }
    double Objetosc_kuli()
    {
        return 4.0/3*M_PI*r*r*r;
    }
};

int main()
{
    double r;
    cout<<"Podaj r:"<<endl;
    cin>>r;
    Kula siema = Kula(r);
    cout<<"Objetosc kuli wynosi: "<<siema.Objetosc_kuli()<<endl;
    return 0;
}
