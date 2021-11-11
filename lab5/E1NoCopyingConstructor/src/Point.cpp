//
// Created by CQ07 on 2021-11-11.
//

#include "../include/Point.h"

Point::Point(double x, double y, string name) : name(name) {
    *this->x = x;
    *this->y = y;
}

Point::Point(string name) : name(name) {
    *x = *y = 0;
}

double Point::getX() {
    return *x;
}

void Point::setX(double x) {
    *this->x = x;
}

double Point::getY() {
    return *y;
}

void Point::setY(double y) {
    *this->y = y;
}

void Point::printData() const {
    cout << "Point " << name << " (x = " << *x << ", y = " << *y << ")\n";
}

void Point::setName(string name) {
    this->name = name;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           name == rhs.name;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

const string &Point::getName() const {
    return name;
}