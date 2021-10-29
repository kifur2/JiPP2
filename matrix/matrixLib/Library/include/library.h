#ifndef MATRIXLIB_LIBRARY_H
#define MATRIXLIB_LIBRARY_H

void print_help();

int **makeMatrix(int *m, int *n, int k);

void printMatrix(int **A, int n, int m);

int **addMatrix(int **A, int **B, int n, int m);

int **subtractMatrix(int **A, int **B, int n, int m);

int **multiplyMatrix(int **A, int **B, int n_A, int m_A, int m_B);

int **multiplyByScalar(int **A, int n, int m, int scalar);

int **transpozeMatrix(int **A, int n, int m);

int **powerMatrix(int **A, int n, int k);

int determinantMatrix(int **A, int n, int w, int *WK);

bool matrixIsDiagonal(int **A, int n, int m);

void swap(int *a, int *b);

void sortRow(int *A, int n);

void sortRowsInMatrix(int **A, int n, int m);

// dla double:
double **makeMatrix(int *m, int *n, double k);

void printMatrix(double **A, int n, int m);

double **addMatrix(double **A, double **B, int n, int m);

double **subtractMatrix(double **A, double **B, int n, int m);

double **multiplyMatrix(double **A, double **B, int n_A, int m_A, int m_B);

double **multiplyByScalar(double **A, int n, int m, double scalar);

double **transpozeMatrix(double **A, int n, int m);

double **powerMatrix(double **A, int n, int k);

double determinantMatrix(double **A, int n, int w, int *WK);

bool matrixIsDiagonal(double **A, int n, int m);

void swap(double *a, double *b);

void sortRow(double *A, int n);

void sortRowsInMatrix(double **A, int n, int m);


#endif //MATRIXLIB_LIBRARY_H
