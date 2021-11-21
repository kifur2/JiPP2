//
// Created by CQ07 on 2021-11-21.
//

#include "Complex.h"

using namespace std;

Complex Complex::operator+(const Complex &rhs) const {
    return {a + rhs.a, b + rhs.b};
}

Complex &Complex::operator+=(const Complex &rhs) {
    this->a = this->a + rhs.a;
    this->b = this->b + rhs.b;
    return *this;
}

Complex Complex::operator-()const{
    double c,d;
    if(a!=0)
        c = -a;
    else
        c = a;
    if(b!=0)
        d = -b;
    else
        d = b;
    return {c,d};
}

Complex Complex::operator-(const Complex &rhs) const{
    return {a - rhs.a, b - rhs.b};
}

bool Complex::operator==(const Complex &rhs)const{
    if(a == rhs.a && b == rhs.b) return true;
    return false;
}

Complex Complex::operator*(const double &lhs)const{
    return {a*lhs, b*lhs};
}

Complex operator*(const double &lhs, const Complex &rhs){
    return {rhs.a*lhs, rhs.b*lhs};
}

ostream &operator<<(ostream &lhs, const Complex &rhs){
    lhs << "a = "<< rhs.a << " b = " << rhs.b << endl;
    return lhs;
}

void Complex::print()
{
    cout<<a<<"+"<<b<<"i"<<endl;
}