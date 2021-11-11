#include <iostream>

using namespace std;

class FunckjaKwadratowa
{
    double a,b,c;
public:
    FunckjaKwadratowa(double A, double B, double C){a=A; b=B; c=C;}
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
    void print_funkcja()
    {
        cout<<"f(x) = "<<a<<" x^2 + "<<b<<" x + "<<c<<endl;
    }
};

int main()
{
    double a,b,c;
    cout<<"Podaj a, b, c:"<<endl;
    cin>>a>>b>>c;
    FunckjaKwadratowa siema = FunckjaKwadratowa(a,b,c);
    siema.print_funkcja();
    return 0;
}