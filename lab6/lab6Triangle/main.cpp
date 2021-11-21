#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
    Node a, b(5,8), c(1, 16);
    Triangle triangle(a, b, c, "First Triangle");

    triangle.display();
    cout << triangle << endl;

    cout << "Distance between first and second point is " << triangle.distance(0,1) << endl;

    Triangle tri2(b,a,c, "Third");
    Triangle* p_tri2 = &tri2;
    Triangle tri3(c,a,b, "Fourth");

    showTriangleData(Triangle(c,b,a, "Second"));
    showTriangleData(p_tri2);
    showTriangleData(&tri3);

}
