#include "library.h"

#include <iostream>

int** addMatrix(int ** A, int ** B, int n, int m)
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
int** subtractMatrix(int ** A, int ** B, int n, int m)
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
int** multiplyMatrix(int ** A, int ** B, int n_A, int m_A, int m_B)
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
            for(int k =0; k<m_A; k++)
            {
                sum+=A[i][k]*B[k][j];
            }
            C[i][j]=sum;
        }
    }
    return C;
}
int** multiplyByScalar(int ** A, int n, int m, int scalar)
{
    int **C = new int *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j]*scalar;
    return C;
}
int** transpozeMatrix(int ** A, int n, int m)
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
int** powerMatrix();
int** determinantMatrix();
bool matrixIsDiagonal(int ** A, int n, int m)
{
    bool x = true;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if(i!=j && A[i][j]!=0)
                x=false;
    return x;
}
void swap(int *a, int*b)
{
    int c = *a;
    *a=*b;
    *b=*a;
}
int** sortRow(int * A, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (A[j] > A[j+1])
                swap(&A[j], &A[j+1]);
}
int** sortRowsInMatrix();
