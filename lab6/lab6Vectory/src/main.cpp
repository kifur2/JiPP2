#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector v1, v2(5,10);
    Vector v3 = v1 + v2;
    v1.print();
    v3.print();
    v3 = v1.operator+(v2);
    v3.print();
    v3 = -v2;
    v3.print();
    v3 = v2 - v3;
    v3.print();
    cout<< (v2|v3) <<endl;
    v3 = v2*3;
    v3.print();
    v3 = 4*v2;
    v3.print();
    if(v3==v2)
        cout<<"false"<<endl;
    if(v3==(4*v2))
        cout<<"true"<<endl;
    cout<<v3;
}