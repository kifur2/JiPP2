#include <iostream>
#include "Complex.h"
int main()
{
    Complex c1 = Complex(1,2);
    Complex c2;
    Complex c3 = c1 + c2;
    c2 = Complex(3,4);
    c3.print();
    c3+=c2;
    c3.print();
    c3 = -c3;
    cout<<c3;
    c3 = c2 - c3;
    cout<<c3;
    c3 = c2*3;
    cout<<c3;
    c3 = 4*c2;
    cout<<c3;
    if(c3==c2)
        cout<<"false"<<endl;
    if(c3==(4*c2))
        cout<<"true"<<endl;
}
