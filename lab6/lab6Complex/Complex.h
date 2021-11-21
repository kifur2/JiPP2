//
// Created by CQ07 on 2021-11-21.
//

#ifndef LAB6COMPLEX_COMPLEX_H
#define LAB6COMPLEX_COMPLEX_H

#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double a, b;

public:
    Complex(): a(0), b(0) {};

    Complex(double a, double b) : a(a), b(b) {}

    Complex operator+(const Complex &rhs) const;

    Complex &operator+=(const Complex &rhs);

    Complex operator-() const;

    Complex operator-(const Complex &rhs) const;

    Complex operator*(const double &lhs) const;

    bool operator==(const Complex &rhs)const;

    friend Complex operator*(const double &lhs, const Complex &rhs);

    friend ostream &operator<<(ostream &lhs, const Complex &rhs);

    void print();
};
Complex operator*(const double &lhs, const Complex &rhs);

ostream &operator<<(ostream &lhs, const Complex &rhs);

#endif //LAB6COMPLEX_COMPLEX_H
