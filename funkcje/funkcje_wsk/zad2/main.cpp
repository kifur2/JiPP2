#include <iostream>

using namespace std;

int main() {
    int n;
    cout<<"Ile elementow ma miec tablica? "<<endl;
    cin>>n;
    int tab[n];
    cout<<"Podaj "<<n<<" elementow: "<<endl;
    for (int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        *(tab + i) = x;
    }
    cout<<"Elementy tablicy wieksze od 0 to:"<<endl;
    for (int *i = tab; i<tab+n; i++)
    {
        if(*i>0)
            cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
