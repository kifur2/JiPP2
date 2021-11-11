#include <iostream>
#include <math.h>

using namespace std;

double pole_figury(double a, double b)
{
    return a*b;
}
double pole_figury(double a, double b, double h)
{
    return (a+b)*h/2;
}
double pole_figury(double r)
{
    return M_PI*r*r;
}

int main() {
    cout<<"Prostokat: "<<pole_figury(4,5)<<endl;
    cout<<"Trapez: "<<pole_figury(4,5,3)<<endl;
    cout<<"Kolo: "<<pole_figury(4)<<endl;
}
