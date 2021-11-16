//
// Created by student on 16.11.21.
//

#ifndef LAB6NODE_NODE_H
#define LAB6NODE_NODE_H

#include <iostream>


class Node {
private:
    double x, y;

public:
    Node();
    Node(double x, double y);

    void display();

    void updateValue(double x, double y);

    friend double pointsDistance(Node,Node);
};

double pointsDistance(Node a, Node b);

#endif //LAB6NODE_NODE_H
