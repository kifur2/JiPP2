//
// Created by CQ07 on 2021-12-10.
//

#ifndef PRZYKLAD_STOP_H
#define PRZYKLAD_STOP_H

#include <iostream>

using namespace std;

class Stop {
private:
    long id;
    string name;
    double latitude;
    double longitude;

public:
    Stop(long id, const string &name, double latitude, double longitude);

    Stop() {};

    void print();
};

#endif //PRZYKLAD_STOP_H
