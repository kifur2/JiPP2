//
// Created by student on 23.11.21.
//

#include "Figury2.h"
#include <math.h>

double Square::getArea() {
    return a*a;
}
double Square::liczObwod(){
    return 4*a;
}
double Circle::getArea() {
    return M_PI*r*r;
}
double Circle::liczObwod(){
    return 2*M_PI*r;
}
double Rectangle::getArea(){
    return a*b;
}
double Rectangle::liczObwod(){
    return a+b+a+b;
}