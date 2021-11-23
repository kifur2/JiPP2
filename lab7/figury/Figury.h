//
// Created by student on 23.11.21.
//

#ifndef FIGURY_FIGURY_H
#define FIGURY_FIGURY_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Figura {
protected:
    string name, color;

public:
    Figura(string name, string color):name(name), color(color){};
    void printName();
    void printColor();
};

class Kwadrat : public Figura {
protected:
    double a; //*10

public:
    Kwadrat(string name, string color, double a):Figura(name, color), a(a){};
    double liczPole();
    double liczObwod();
};

class Trojkat : public Figura {
protected:
    double a,b,c;
public:
    Trojkat(string name, string color, double a, double b, double c):Figura(name, color), a(a), b(b), c(c){};
    double liczPole();
    double liczObwod();
};

#endif //FIGURY_FIGURY_H
