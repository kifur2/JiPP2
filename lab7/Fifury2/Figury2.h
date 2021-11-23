//
// Created by student on 23.11.21.
//

#ifndef FIFURY2_FIGURY2_H
#define FIFURY2_FIGURY2_H

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Figure {

public:
    virtual double getArea() = 0;
};

class Square : public Figure {
protected:
    double a; //*10

public:
    Square(double a): a(a){};
    double getArea();
    double liczObwod();
};

class Circle : public Figure {
protected:
    double r; //*10

public:
    Circle(double r): r(r){};
    double getArea();
    double liczObwod();
};

class Rectangle : public Figure {
protected:
    double a,b;
public:
    Rectangle(double a, double b):a(a), b(b){};
    double getArea();
    double liczObwod();
};

#endif //FIFURY2_FIGURY2_H
