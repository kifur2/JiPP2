//
// Created by CQ07 on 2021-11-21.
//

#include "Triangle.h"
#include <cmath>
using namespace std;

Triangle::Triangle(): name("brak") {
    tab[0]=Node(0,0);
    tab[1]=Node(0,0);
    tab[2]=Node(0,0);
}
Triangle:: Triangle(Node a, Node b, Node c, string name) :name(name) {
    tab[0]=a;
    tab[1]=b;
    tab[2]=c;
}

void Triangle::display(){
    cout<<name<<": "<<tab[0]<<", "<<tab[1]<<", "<<tab[2]<<endl;
}

double Triangle::distance(int firstPointIndex, int secondPointIndex){
    return pointsDistance(tab[firstPointIndex], tab[secondPointIndex]);
}

void showTriangleData(Triangle triangle){
    triangle.display();
}
void showTriangleData(Triangle *triangle){
    triangle->display();
}
void showTriangleData(Triangle &triangle){
    triangle.display();
}

ostream &operator<<(ostream &lhs, const Triangle &rhs){
    lhs<<rhs.name<<": "<<rhs.tab[0]<<", "<<rhs.tab[1]<<", "<<rhs.tab[2]<<endl;
    return lhs;
}