//
// Created by student on 16.11.21.
//

#ifndef LAB6_VECTOR_H
#define LAB6_VECTOR_H
#include <iostream>
#include <cmath>

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
    void print();
};

#endif //LAB6_VECTOR_H
