#include <iostream>

using namespace std;

double srednia(int *x, int *y)
{
    return ((double)*x+*y)/2;
}

int main()
{
    int a,b;
    cout<<"Podaj 2 liczby typu int (a i b):"<<endl;
    cin>> a >> b;
    int *wsk_a = &a;
    int *wsk_b = &b;
    cout<<"srednia to: "<<srednia(wsk_a,wsk_b)<<endl;
    return 0;
}