#include <iostream>
#include "Figury2.h"

int main() {
    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
}