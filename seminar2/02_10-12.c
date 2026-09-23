#include <stdio.h>

#define MAX 100

void assign(double A[MAX][MAX], double B[MAX][MAX], int n);
void multiply(double A[MAX][MAX], double B[MAX][MAX], double C[MAX][MAX], int n);
void power(double A[MAX][MAX], double C[MAX][MAX], int n, int pow);

int main(void)
{
    double A[MAX][MAX] = {{7, 7, 2}, {1, 8, 3}, {2, 1, 6}};
    double B[MAX][MAX] = {0};
    double C[MAX][MAX] = {0};

    power(A, C, 3, 4);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            printf("%lg ", C[i][j]);
            if (j == 2)
                printf("\n");
        }
    
    return 0;
}

void assign(double A[MAX][MAX], double B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j];
}

void multiply(double A[MAX][MAX], double B[MAX][MAX], double C[MAX][MAX], int n)
{
    double temp = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            temp = 0;
            for (int k = 0; k < n; k++)
                temp += A[i][k] * B[k][j];
            C[i][j] = temp;
        }
}

void power(double A[MAX][MAX], double C[MAX][MAX], int n, int pow)
{
    double Temp[MAX][MAX] = {0};

    assign(C, A, n);

    for (int i = 0; i < pow - 1; i++)
    {
        multiply(C, A, Temp, n);
        assign(C, Temp, n);
    }
}