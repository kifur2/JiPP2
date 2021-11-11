#include <iostream>

using namespace std;

int randint(int a, int b)
{
    return a+rand()%(b-a+1);
}

int ret_max(int tab[100])
{
    int tab_max=tab[0];
    for (int i=0; i<100; i++)
    {
        if(tab_max<tab[i])
            tab_max = tab[i];
    }
    return tab_max;
}

void obrot(int tab[100])
{
    for (int i=0; i<50; i++)
        swap(tab[i], tab[99-i]);
}

int main() {
    cout<<randint(3,7)<<endl;
    int *tab;
    tab = new int[100];
    for(int i=0; i<100; i++)
        tab[i]=randint(1,100);
    cout<<"max z tab: "<< ret_max(tab)<<endl;
    obrot(tab);
    delete[] tab;
    return 0;
}
