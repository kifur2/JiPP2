//
// Created by student on 23.11.21.
//

#ifndef FIGURY_FIGURY_H
#define FIGURY_FIGURY_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Figure {
protected:
    string name, color;

public:
    Figure(string name, string color):name(name), color(color){};
    void printName();
    void printColor();
};

class Square : public Figure {
protected:
    double a; //*10

public:
    Square(string name, string color, double a):Figure(name, color), a(a){};
    double liczPole();
    double liczObwod();
};

class Rectangle : public Figure {
protected:
    double a,b,c;
public:
    Rectangle(string name, string color, double a, double b, double c):Figure(name, color), a(a), b(b), c(c){};
    double liczPole();
    double liczObwod();
};

#endif //FIGURY_FIGURY_H
