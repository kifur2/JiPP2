//
// Created by student on 23.11.21.
//

#include "Figury.h"

void Figure::printName() {
    cout<<"name: "<<name<<endl;
}
void Figure::printColor() {
    cout<<"color: "<<color<<endl;
}
double Square::liczPole() {
    return a*a;
}
double Square::liczObwod(){
    return 4*a;
}
double Rectangle::liczPole(){
    double s = liczObwod()/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
double Rectangle::liczObwod(){
    return a+b+c;
}