#include <iostream>

using namespace std;

int main()
{
    int cVal = 314;
    const int cVal2 = 666;

    cout<<"cVal = "<<cVal<<" &cVal = "<< &cVal<<" cVal2 = "<<cVal2<<" &cVal2 = "<< &cVal2<<endl;

    const int *p = &cVal;
    cout<<"*p= "<<*p<<" p= "<<p<<endl;
    //*p = 628; //nie da się zmieniać wartości wskazywanej przez p
    p = &cVal2; // da się zmieniać na co wskazuje wskaźnik p
    cout<<"*p= "<<*p<<" p= "<<p<<endl;


    cout<<"cVal = "<<cVal<<" &cVal = "<< &cVal<<" cVal2 = "<<cVal2<<" &cVal2 = "<< &cVal2<<endl;

    int *const q = &cVal;
    cout<<"*q= "<<*q<<" q= "<<q<<endl;
    *q = 628;// da się zmienić wartość wskazywaną przez wskaźnik
    //q = &cVal2;// nie da się zmieniać na co wskazuje wskaźnik p
    cout<<"*q= "<<*q<<" q= "<<q<<endl;

    cout<<"cVal = "<<cVal<<" &cVal = "<< &cVal<<" cVal2 = "<<cVal2<<" &cVal2 = "<< &cVal2<<endl;

    const int* const youCantModifyMe = &cVal;
    //*youCantModifyMe = 628; //nie da się zmieniać wartości wskazywanej przez youCantModifyMe
    //youCantModifyMe = &cVal2;// nie da się zmieniać na co wskazuje wskaźnik youCantModifyMe

    cout<<"*youCantModifyMe= "<<*youCantModifyMe<<" youCantModifyMe= "<<youCantModifyMe<<endl;

    return 0;
}

