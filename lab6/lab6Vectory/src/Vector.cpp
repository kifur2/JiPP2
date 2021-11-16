//
// Created by student on 16.11.21.
//

#include "../include/Vector.h"

using namespace std;

double Vector::length() {
    return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector &rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Vector &Vector::operator+=(const Vector &rhs) {
    this->x = this->x + rhs.x;
    this->y = this->y + rhs.y;
    return *this;
}

Vector Vector::operator-()const{
    double c,d;
    if(x!=0)
        c = -x;
    else
        c = x;
    if(y!=0)
        d = -y;
    else
        d = y;
    return {c,d};
}

Vector Vector::operator-(const Vector &rhs) const{
    return {x - rhs.x, y - rhs.y};
}
double Vector::operator|(const Vector &rhs) const{
    return x*rhs.x + y*rhs.y;
}

void Vector::print()
{
    cout<<"("<<x<<", "<<y<<")"<<endl;
}