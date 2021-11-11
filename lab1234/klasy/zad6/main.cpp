#include <iostream>

using namespace std;

class Figura
{
public:
    int n;
    pair<int,int> *tab = new pair<int,int>[n];
    Figura(int N){
        n = N;
        cout<<"Podaj wspolrzedne wierzcholkow: "<<endl;
        for(int i=0; i<n; i++)
        {
            pair <int,int> nowa;
            int x,y;
            cin>>x>>y;
            nowa.first = x;
            nowa.second = y;
            tab[i]=nowa;
        }
    }
};

int main()
{
    int n;
    cout<<"Podaj n:"<<endl;
    cin>>n;
    Figura siema = Figura(n);
    return 0;
}

