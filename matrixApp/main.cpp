#include <iostream>

using namespace std;

int main()
{
    int m,n;
    cout<<"Podaj liczbe kolumn macierzy:"<<endl;
    cin>>m;
    cout<<"Podaj liczbe wierszy macierzy:"<<endl;
    cin>>n;
    int** A_matrix = new int* [n];
    for(int i=0; i<n; i++)
    {
        A_matrix[i] = new int[m];
    }
    cout<<"Podaj liczby z macierzy:"<<endl;
    int x;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>x;
            A_matrix[i][j]=x;
        }
    cout<< "Twoja macierz to:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<A_matrix[i][j]<<'\t';
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++)
    {
        delete [] A_matrix[i];
    }
    delete [] A_matrix;
    return 0;
}
