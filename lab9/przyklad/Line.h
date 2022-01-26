//
// Created by CQ07 on 2021-12-10.
//

#ifndef PRZYKLAD_LINE_H
#define PRZYKLAD_LINE_H

#include <iostream>
#include <vector>
#include "Stop.h"

using namespace std;

class Line {
private:
    string number;
    string direction;
    vector<Stop *> stops;

public:
    Line(const string &number, const string &direction);

    void addStop(Stop * stop);

    void print();

};

#endif //PRZYKLAD_LINE_H
