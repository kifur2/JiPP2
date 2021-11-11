#include <iostream>

using namespace std;

void insert_fun(int x, int *w)
{
    *w = x;
}

int main() {
    int a = 7;
    int b = 5;
    insert_fun(a,&b);
    cout<<"a = "<<a<<" b = "<<b<<endl;
    return 0;
}
