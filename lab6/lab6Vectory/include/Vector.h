//
// Created by student on 16.11.21.
//

#ifndef LAB6_VECTOR_H
#define LAB6_VECTOR_H
#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x, y;

public:
    Vector(): x(0), y(0) {};

    Vector(double x, double y) : x(x), y(y) {}

    double length();

    Vector operator+(const Vector &rhs) const;

    Vector &operator+=(const Vector &rhs);

    Vector operator-() const;

    Vector operator-(const Vector &rhs) const;

    double operator|(const Vector &rhs) const;

    Vector operator*(const double &lhs) const;

    bool operator==(const Vector &rhs)const;

    friend Vector operator*(const double &lhs, const Vector &rhs);

    friend ostream &operator<<(ostream &lhs, const Vector &rhs);

    void print();
};
Vector operator*(const double &lhs, const Vector &rhs);

ostream &operator<<(ostream &lhs, const Vector &rhs);

#endif //LAB6_VECTOR_H
