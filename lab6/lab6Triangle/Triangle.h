//
// Created by CQ07 on 2021-11-21.
//

#ifndef LAB6TRIANGLE_TRIANGLE_H
#define LAB6TRIANGLE_TRIANGLE_H
#include "../lab6Node/include/Node.h"
#include <iostream>
using namespace std;

class Triangle{
    Node tab [3];
    string name;
public:
    Triangle();

    Triangle(Node a, Node b, Node c, string name);

    void display();

    double distance(int firstPointIndex, int secondPointIndex);

    friend ostream &operator<<(ostream &lhs, const Triangle &rhs);
};
ostream &operator<<(ostream &lhs, const Triangle &rhs);
void showTriangleData(Triangle triangle);
void showTriangleData(Triangle *triangle);
void showTriangleData(Triangle &triangle);
#endif //LAB6TRIANGLE_TRIANGLE_H
