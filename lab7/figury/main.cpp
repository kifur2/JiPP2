#include <iostream>
#include "Figury.h"

int main() {
    Kwadrat kwa("kwadrat1", "czerwony", 4);
    Trojkat tra("Trojkat1", "niebieski", 3, 4, 5);
    kwa.printName();
    kwa.printColor();
    cout<<"OBW kwa = "<<kwa.liczObwod()<<endl;
    cout<<"P kwa= "<<kwa.liczPole()<<endl;
    tra.printName();
    tra.printColor();
    cout<<"OBW tra= "<<tra.liczObwod()<<endl;
    cout<<"P tra = "<<tra.liczPole()<<endl;
}