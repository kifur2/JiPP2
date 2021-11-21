//
// Created by student on 16.11.21.
//

#ifndef LAB6NODE_NODE_H
#define LAB6NODE_NODE_H

#include <iostream>
using namespace std;

class Node {
private:
    double x, y;

public:
    Node();
    Node(double x, double y);

    void display();

    void updateValue(double x, double y);

    friend double pointsDistance(Node,Node);
    friend ostream &operator<<(ostream &lhs, const Node &rhs);
};

double pointsDistance(Node a, Node b);

ostream &operator<<(ostream &lhs, const Node &rhs);

#endif //LAB6NODE_NODE_H
