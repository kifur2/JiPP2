#include <iostream>

using namespace std;

void dzielenie(int a, int b)
{
    if(b==0)
        throw "argument b wynosi 0.";
    else
    if(a%b!=0)
        throw "a jest niepodzielne przez b.";
    else
        cout<<"a/b = "<<a/b<<endl;
}

int main() {
    int a,b;
    cout<<"Podaj a i b:"<<endl;
    cin >>a>>b;
    try {
        dzielenie(a,b);
    }
    catch(const char *msg)
    {
        cout<<msg<<endl;
    }
    return 0;
}
