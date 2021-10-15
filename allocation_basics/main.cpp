#include <iostream>

using namespace std;
int main() {

    //wypisanie 5 razy JiPP2
    for(int i=0; i<5; i++)
    {
        cout<<"JiPP2"<<endl;
    }

    // dowolna tablica dwuwymiarowa alokowana dynamicznie
    int **tablica = new int*[3];
    for (int i=0; i<3; i++)
    tablica[i] = new int[3];
    int q=1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            tablica[i][j]=q++;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<tablica[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i=0; i<3; i++)
    delete [] tablica[i];
    delete [] tablica;

}
