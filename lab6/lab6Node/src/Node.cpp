//
// Created by student on 16.11.21.
//

#include "../include/Node.h"
#include <cmath>

using namespace std;

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

double pointsDistance(Node a, Node b)
{
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
ostream &operator<<(ostream &lhs, const Node &rhs){
    lhs<<"("<<rhs.x<<","<<rhs.y<<") ";
    return lhs;
}