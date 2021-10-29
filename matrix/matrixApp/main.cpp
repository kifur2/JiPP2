#include <iostream>
#include <map>
#include "../matrixLib/Library/include/library.h"

using namespace std;

map<string, int> funkcje;

void map_init()
{
    funkcje["addMatrix"] = 1;
    funkcje["subtractMatrix"] = 2;
    funkcje["multiplyMatrix"] = 3;
    funkcje["multiplyByScalar"] = 4;
    funkcje["transpozeMatrix"] = 5;
    funkcje["powerMatrix"] = 6;
    funkcje["determinantMatrix"] = 7;
    funkcje["matrixIsDiagonal"] = 8;
    funkcje["swap"] = 9;
    funkcje["sortRow"] = 10;
    funkcje["sortRowsInMatrix"] = 11;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        print_help();
    else
    {
        map_init();
        int m_A = 0, n_A = 0, m_B = 0, n_B = 0, h = 0;
        int *WK;
        cout << "Jesli bedziesz uzywac w macierzach liczb calkowitych napisz 0, a jesli rzeczywistych napisz 1" << endl;
        bool f;
        cin >> f;
        if (cin.fail())
        {
            cout << "***Blad wczytywania zmiennej***" << endl << endl;
            print_help();
            exit(EXIT_FAILURE);
        }
        if (f)
        {
            double **A_matrix, **B_matrix;
            double k = 0;
            switch (funkcje[argv[1]])
            {
                case 1:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Macierz B: " << endl;
                    B_matrix = makeMatrix(&m_B, &n_B, k);
                    A_matrix = addMatrix(A_matrix, B_matrix, n_A, m_A);
                    cout << "Suma podanych macierzy to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 2:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Macierz B: " << endl;
                    B_matrix = makeMatrix(&m_B, &n_B, k);
                    A_matrix = subtractMatrix(A_matrix, B_matrix, n_A, m_A);
                    cout << "Roznica podanych macierzy to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 3:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Macierz B: " << endl;
                    B_matrix = makeMatrix(&m_B, &n_B, k);
                    cout << "Iloczyn podanych macierzy to: " << endl;
                    printMatrix(multiplyMatrix(A_matrix, B_matrix, n_A, m_A, m_B), n_A, m_B);
                    break;
                case 4:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Podaj skalar: " << endl;
                    cin >> k;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    A_matrix = multiplyByScalar(A_matrix, n_A, m_A, k);
                    cout << "Iloczyn podanej macierzy i skalara to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 5:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Transpozycja podanej macierzy to: " << endl;
                    printMatrix(transpozeMatrix(A_matrix, n_A, m_A), m_A, n_A);
                    break;
                case 6:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Podaj wykladnik potegi(k): " << endl;
                    cin >> h;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    A_matrix = powerMatrix(A_matrix, n_A, h);
                    cout << "k-ta potega podanej macierzy to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 7:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    WK = new int[n_A];
                    for (int i = 0; i < n_A; i++)
                        WK[i] = i;
                    cout << "Wyznacznik tej macierzy to: " << determinantMatrix(A_matrix, n_A, 0, WK) << endl;
                    break;
                case 8:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    if (matrixIsDiagonal(A_matrix, n_A, m_A))
                        cout << "Podana macierz jest diagonalna" << endl;
                    else
                        cout << "Podana macierz nie jest diagonalna" << endl;
                    break;
                case 9:
                    cout << "Podaj dwie liczby:" << endl;
                    double a, b;
                    cin >> a >> b;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    swap(&a, &b);
                    cout << "Te liczby odwrotnie to: " << a << ' ' << b << endl;
                    swap(&a, &b);
                    break;
                case 10:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Podaj numer wiersza macierzy ktory chcesz posortowac(liczac od 0): " << endl;
                    cin >> h;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    sortRow(A_matrix[h], m_A);
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 11:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    sortRowsInMatrix(A_matrix, n_A, m_A);
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                default:
                    print_help();
                    break;
            }
            for (int i = 0; i < n_A; i++)
            {
                delete[] A_matrix[i];
            }
            for (int i = 0; i < n_B; i++)
            {
                delete[] B_matrix[i];
            }
            delete[] A_matrix;
        } else
        {
            int **A_matrix, **B_matrix;
            int k = 0;
            switch (funkcje[argv[1]])
            {
                case 1:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Macierz B: " << endl;
                    B_matrix = makeMatrix(&m_B, &n_B, k);
                    A_matrix = addMatrix(A_matrix, B_matrix, n_A, m_A);
                    cout << "Suma podanych macierzy to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 2:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Macierz B: " << endl;
                    B_matrix = makeMatrix(&m_B, &n_B, k);
                    A_matrix = subtractMatrix(A_matrix, B_matrix, n_A, m_A);
                    cout << "Roznica podanych macierzy to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 3:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Macierz B: " << endl;
                    B_matrix = makeMatrix(&m_B, &n_B, k);
                    cout << "Iloczyn podanych macierzy to: " << endl;
                    printMatrix(multiplyMatrix(A_matrix, B_matrix, n_A, m_A, m_B), n_A, m_B);
                    break;
                case 4:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Podaj skalar: " << endl;
                    cin >> k;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    A_matrix = multiplyByScalar(A_matrix, n_A, m_A, k);
                    cout << "Iloczyn podanej macierzy i skalara to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 5:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Transpozycja podanej macierzy to: " << endl;
                    printMatrix(transpozeMatrix(A_matrix, n_A, m_A), m_A, n_A);
                    break;
                case 6:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Podaj wykladnik potegi(k): " << endl;
                    cin >> h;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    A_matrix = powerMatrix(A_matrix, n_A, h);
                    cout << "k-ta potega podanej macierzy to: " << endl;
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 7:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    WK = new int[n_A];
                    for (int i = 0; i < n_A; i++)
                        WK[i] = i;
                    cout << "Wyznacznik tej macierzy to: " << determinantMatrix(A_matrix, n_A, 0, WK) << endl;
                    break;
                case 8:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    if (matrixIsDiagonal(A_matrix, n_A, m_A))
                        cout << "Podana macierz jest diagonalna" << endl;
                    else
                        cout << "Podana macierz nie jest diagonalna" << endl;
                    break;
                case 9:
                    cout << "Podaj dwie liczby:" << endl;
                    int a, b;
                    cin >> a >> b;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    swap(&a, &b);
                    cout << "Te liczby odwrotnie to: " << a << ' ' << b << endl;
                    swap(&a, &b);
                    break;
                case 10:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    cout << "Podaj numer wiersza macierzy ktory chcesz posortowac(liczac od 0): " << endl;
                    cin >> h;
                    if (cin.fail())
                    {
                        cout << "***Blad wczytywania zmiennej***" << endl << endl;
                        print_help();
                        exit(EXIT_FAILURE);
                    }
                    sortRow(A_matrix[h], m_A);
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                case 11:
                    cout << "Macierz A: " << endl;
                    A_matrix = makeMatrix(&m_A, &n_A, k);
                    sortRowsInMatrix(A_matrix, n_A, m_A);
                    printMatrix(A_matrix, n_A, m_A);
                    break;
                default:
                    print_help();
                    break;
            }
            for (int i = 0; i < n_A; i++)
            {
                delete[] A_matrix[i];
            }
            for (int i = 0; i < n_B; i++)
            {
                delete[] B_matrix[i];
            }
            delete[] A_matrix;
        }


    }
    return 0;
}
