#include "../Library/include/library.h"

#include <iostream>
#include <cstring>
#include <climits>
#include <stdlib.h>

using namespace std;

int **makeMatrix(int *m, int *n, int k)
{
    cout << "Podaj liczbe kolumn macierzy:" << endl;
    cin >> *m;
    if (cin.fail())
    {
        cout << "***Blad wczytywania zmiennej***" << endl << endl;
        print_help();
        exit(EXIT_FAILURE);
    }
    cout << "Podaj liczbe wierszy macierzy:" << endl;
    cin >> *n;
    if (cin.fail())
    {
        cout << "***Blad wczytywania zmiennej***" << endl << endl;
        print_help();
        exit(EXIT_FAILURE);
    }
    int **A_matrix = new int *[*n];
    for (int i = 0; i < *n; i++)
    {
        A_matrix[i] = new int[*m];
    }
    cout << "Podaj liczby z macierzy:" << endl;
    int x;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            cin >> x;
            if (cin.fail())
            {
                cout << "***Blad wczytywania zmiennej***" << endl << endl;
                print_help();
                exit(EXIT_FAILURE);
            }
            A_matrix[i][j] = x;
        }
    }
    return A_matrix;
}

void printMatrix(int **A, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << '\t';
        }
        cout << endl;
    }
}

int **addMatrix(int **A, int **B, int n, int m)
{
    int **C = new int *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

int **subtractMatrix(int **A, int **B, int n, int m)
{
    int **C = new int *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

int **multiplyMatrix(int **A, int **B, int n_A, int m_A, int m_B)
{
    int **C = new int *[n_A];
    for (int i = 0; i < n_A; i++)
    {
        C[i] = new int[m_B];
    }

    for (int i = 0; i < n_A; i++)
    {
        for (int j = 0; j < m_B; j++)
        {
            int sum = 0;
            for (int k = 0; k < m_A; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

int **multiplyByScalar(int **A, int n, int m, int scalar)
{
    int **C = new int *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] * scalar;
    return C;
}

int **transpozeMatrix(int **A, int n, int m)
{
    int **C = new int *[m];
    for (int i = 0; i < m; i++)
    {
        C[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[j][i];
    return C;
}

void przepisz(int n, int **A, int **B)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            B[i][j] = A[i][j];
    }
}

int **powerMatrix(int **A, int n, int k)
{
    int **P = new int *[n];
    int **W = new int *[n];
    for (int i = 0; i < n; i++)
    {
        P[i] = new int[n];
        W[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            W[i][j] = 0;
        W[i][i] = 1;
    }
    while (k)
    {
        if (k & 1)
        {
            P = multiplyMatrix(A, W, n, n, n);
            przepisz(n, P, W);
        }
        k >>= 1;
        if (!k) break;
        P = multiplyMatrix(A, A, n, n, n);
        przepisz(n, P, A);
    }
    przepisz(n, W, A);
    for (int i = 0; i < n; i++)
    {
        delete[] W[i];
        delete[] P[i];
    }
    delete[] W;
    delete[] P;
    return A;
}

int determinantMatrix(int **A, int n, int w, int *WK)
{
    int *NK;
    int s;
    if (n == 1)
        return A[w][WK[0]];
    else
    {
        NK = new int[n - 1];
        s = 0;
        int m = 1;
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            for (int j = 0; j < n - 1; j++)
            {
                if (k == i)
                    k++;
                NK[j] = WK[k++];
            }
            s += m * A[w][WK[i]] * determinantMatrix(A, n - 1, w + 1, NK);
            m = -m;
        }
        delete[] NK;
        return s;
    }
}

bool matrixIsDiagonal(int **A, int n, int m)
{
    bool x = true;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i != j && A[i][j] != 0)
                x = false;
    return x;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void sortRow(int *A, int m)
{
    for (int i = 0; i < m; i++)
        for (int j = 1; j < m - i; j++)
            if (A[j - 1] > A[j])
                swap(&A[j - 1], &A[j]);
}

void sortRowsInMatrix(int **A, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        sortRow(A[i], n);
    }
}

void print_help()
{
    cout << endl << "Matrix Calculator" << endl;
    cout << "matrixLibApp.exe [nazwa dzialania]" << endl << endl;
    cout << "Dzialania:" << endl;
    cout << "addMatrix" << endl;
    cout << "\tDodawanie dwoch macierzy (A i B) - takie same rozmiary" << endl;
    cout << "subtractMatrix " << endl;
    cout << "\tOdejmowanie dwoch macierzy (A i B) - takie same rozmiary" << endl;
    cout << "multiplyMatrix" << endl;
    cout << "\tWymnozenie dwoch macierzy (A i B) - liczba kolumn w A = liczba wierszy w B" << endl;
    cout << "multiplyByScalar" << endl;
    cout << "\tWymnozenie macierzy (A) przez skalar" << endl;
    cout << "transpozeMatrix" << endl;
    cout << "\tTransponowanie macierzy" << endl;
    cout << "powerMatrix" << endl;
    cout << "\tPodniesienie macierzy kwadratowej do k-tej potegi" << endl;
    cout << "determinantMatrix" << endl;
    cout << "\tObliczenie wyznacznika macierzy kwadratowej" << endl;
    cout << "matrixIsDiagonal" << endl;
    cout << "\tSprawdzenie czy macierz jest diagonalna" << endl;
    cout << "swap" << endl;
    cout << "\tZamiana dwoch liczb (a i b) miejscami w pamieci komputera" << endl;
    cout << "sortRow" << endl;
    cout << "\tPosortowanie k-tego rzedu w macierzy(rosnaco)" << endl;
    cout << "sortRowsInMatrix" << endl;
    cout << "\tPosortowanie wszystkich rzedow macierzy(rosnaco)" << endl;
    cout << "help" << endl;
    cout << "\tWyswietlenie okna pomocy." << endl << endl;
    cout<<  "*****Zanim rozpoczniesz wpisywanie wpisz 0 jesli chcesz wpisywac liczby typu int i 1 jesli double*****"<<endl;
    cout << "                 ***Wczytywanie macierzy wyswietla sie podczas wykonywania programu***                 " << endl;
    cout << "                 ***Najpierw wpisuje sie liczbe kolumn, pozniej wierszy, a na koncu***                 " << endl;
    cout << "                          ***liczby wpisywane wierszami od lewej do prawej***                          " << endl;
}

// dla double
void printMatrix(double **A, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << '\t';
        }
        cout << endl;
    }
}

double **makeMatrix(int *m, int *n, double k)
{
    cout << "Podaj liczbe kolumn macierzy:" << endl;
    cin >> *m;
    if (cin.fail())
    {
        cout << "***Blad wczytywania zmiennej***" << endl << endl;
        print_help();
        exit(EXIT_FAILURE);
    }
    cout << "Podaj liczbe wierszy macierzy:" << endl;
    cin >> *n;
    if (cin.fail())
    {
        cout << "***Blad wczytywania zmiennej***" << endl << endl;
        print_help();
        exit(EXIT_FAILURE);
    }
    double **A_matrix = new double *[*n];
    for (int i = 0; i < *n; i++)
    {
        A_matrix[i] = new double[*m];
    }
    cout << "Podaj liczby z macierzy:" << endl;
    double x;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            cin >> x;
            if (cin.fail())
            {
                cout << "***Blad wczytywania zmiennej***" << endl << endl;
                print_help();
                exit(EXIT_FAILURE);
            }
            A_matrix[i][j] = x;
        }
    }
    return A_matrix;
}

double **addMatrix(double **A, double **B, int n, int m)
{
    double **C = new double *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new double[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double **subtractMatrix(double **A, double **B, int n, int m)
{
    double **C = new double *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new double[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double **multiplyMatrix(double **A, double **B, int n_A, int m_A, int m_B)
{
    double **C = new double *[n_A];
    for (int i = 0; i < n_A; i++)
    {
        C[i] = new double[m_B];
    }

    for (int i = 0; i < n_A; i++)
    {
        for (int j = 0; j < m_B; j++)
        {
            double sum = 0;
            for (int k = 0; k < m_A; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

double **multiplyByScalar(double **A, int n, int m, double scalar)
{
    double **C = new double *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new double[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] * scalar;
    return C;
}

double **transpozeMatrix(double **A, int n, int m)
{
    double **C = new double *[m];
    for (int i = 0; i < m; i++)
    {
        C[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[j][i];
    return C;
}

void przepisz(int n, double **A, double **B)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            B[i][j] = A[i][j];
    }
}

double **powerMatrix(double **A, int n, int k)
{
    double **P = new double *[n];
    double **W = new double *[n];
    for (int i = 0; i < n; i++)
    {
        P[i] = new double[n];
        W[i] = new double[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            W[i][j] = 0;
        W[i][i] = 1;
    }
    while (k)
    {
        if (k & 1)
        {
            P = multiplyMatrix(A, W, n, n, n);
            przepisz(n, P, W);
        }
        k >>= 1;
        if (!k) break;
        P = multiplyMatrix(A, A, n, n, n);
        przepisz(n, P, A);
    }
    przepisz(n, W, A);
    for (int i = 0; i < n; i++)
    {
        delete[] W[i];
        delete[] P[i];
    }
    delete[] W;
    delete[] P;
    return A;
}

double determinantMatrix(double **A, int n, int w, int *WK)
{
    int *NK;
    double s;
    if (n == 1)
        return A[w][WK[0]];
    else
    {
        NK = new int[n - 1];
        s = 0;
        int m = 1;
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            for (int j = 0; j < n - 1; j++)
            {
                if (k == i)
                    k++;
                NK[j] = WK[k++];
            }
            s += m * A[w][WK[i]] * determinantMatrix(A, n - 1, w + 1, NK);
            m = -m;
        }
        delete[] NK;
        return s;
    }
}

bool matrixIsDiagonal(double **A, int n, int m)
{
    bool x = true;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i != j && A[i][j] != 0)
                x = false;
    return x;
}

void swap(double *a, double *b)
{
    double c = *a;
    *a = *b;
    *b = c;
}

void sortRow(double *A, int m)
{
    for (int i = 0; i < m; i++)
        for (int j = 1; j < m - i; j++)
            if (A[j - 1] > A[j])
                swap(&A[j - 1], &A[j]);
}

void sortRowsInMatrix(double **A, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        sortRow(A[i], n);
    }
}