#include <iostream>

using namespace std;

class Prostopadloscian
{
    double a,b,c;
public:
    Prostopadloscian(double A, double B, double C){a=A; b=B; c=C;}
    double getA()
    {
        return a;
    }
    double getB()
    {
        return a;
    }
    double getC()
    {
        return a;
    }
    void setabc(double a,double b,double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double polePowierzchni()
    {
        return 2*a*b+2*b*c+2*c*a;
    }
};

int main()
{
    double a,b,c;
    cout<<"Podaj a, b, c:"<<endl;
    cin>>a>>b>>c;
    Prostopadloscian siema = Prostopadloscian(a,b,c);
    cout<<"Pole powierzchni wynosi: "<<siema.polePowierzchni()<<endl;
    return 0;
}
