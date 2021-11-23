//
// Created by student on 23.11.21.
//

#include "Figury.h"

void Figura::printName() {
    cout<<"name: "<<name<<endl;
}
void Figura::printColor() {
    cout<<"color: "<<color<<endl;
}
double Kwadrat::liczPole() {
    return a*a;
}
double Kwadrat::liczObwod(){
    return 4*a;
}
double Trojkat::liczPole(){
    double s = liczObwod()/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
double Trojkat::liczObwod(){
    return a+b+c;
}