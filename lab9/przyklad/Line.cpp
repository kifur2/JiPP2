//
// Created by CQ07 on 2021-12-10.
//

#include "Line.h"

Line::Line(const string &number, const string &direction) : number(number), direction(direction) {}

void Line::addStop(Stop *stop) {
    stops.push_back(stop);

}

void Line::print() {
    cout << "Line: " << number << " " << direction << endl;
    cout << "Stops:" <<endl;

    vector<Stop *>::iterator i;

    for( i = stops.begin(); i != stops.end(); i++) {
        (*i)->print();
    }
}
