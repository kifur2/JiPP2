#include <iostream>

using namespace std;

void add(int a, int b, int &c) {
    c = a + b;
}
void add(double a, double b, double &c) {
    c = a + b;
}

int main()
{
    int k;
    double x;
    add(5, 5, k);
    add(5.6, 6.3,x);
    cout << k <<endl<< x << endl;
    return 0;
}
