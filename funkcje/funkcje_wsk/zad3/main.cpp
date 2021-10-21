#include <iostream>

using namespace std;

void sortuj(int *x, int *y, int *z)
{
    if(*y<*x)
        swap(*x,*y);
    if(*z<*y)
        swap(*z,*y);
    if(*y<*x)
        swap(*x,*y);
}

int main()
{
    int a = 7;
    int b = 2;
    int c = 5;

    sortuj(&a,&b,&c);

    cout<<"W rosnacej kolejnosci: "<< a <<' '<<b<<' '<<c<<endl;

    return 0;
}
