#include <stdio.h>

#define SUCCESS 0
#define ERROR -1
#define MAX_MTX 1000

int GetMtx(int *Mtx, int Mtx_size);
int MultElem(int *Mtx_1, int *Mtx_2, int *Mtx_res, int Mtx_size, int i, int j);
int MultMtx(int *Mtx_1, int *Mtx_2, int *Mtx_res, int Mtx_size);
int PrintMtx(int *Mtx, int Mtx_size);

int main(void)
{
    int Mtx_size = 0;

    int Mtx_1[MAX_MTX] = {};
    int Mtx_size_1 = 0;
    scanf("%d", &Mtx_size_1);
    GetMtx(Mtx_1, Mtx_size_1);

    int Mtx_2[MAX_MTX] = {};
    int Mtx_size_2 = 0;
    scanf("%d", &Mtx_size_2);
    GetMtx(Mtx_2, Mtx_size_2);

    Mtx_size = Mtx_size_1;
    int Mtx_res[MAX_MTX] = {};

    MultMtx(Mtx_1, Mtx_2, Mtx_res, Mtx_size);
    PrintMtx(Mtx_res, Mtx_size);

    return 0;
}

int GetMtx(int *Mtx, int Mtx_size)
{
    if (!Mtx)
        return ERROR;

    for (int i = 0; i < Mtx_size * Mtx_size; i++)
        scanf("%d", Mtx + i);

    return SUCCESS;
}

int MultMtx(int *Mtx_1, int *Mtx_2, int *Mtx_res, int Mtx_size)
{
    if (!(Mtx_1 && Mtx_2 && Mtx_res))
        return ERROR;

    int n = Mtx_size;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            MultElem(Mtx_1, Mtx_2, Mtx_res, n, i, j);

    return SUCCESS;
}

int MultElem(int *Mtx_1, int *Mtx_2, int *Mtx_res, int Mtx_size, int i, int j)
{
    if (!(Mtx_1 && Mtx_2 && Mtx_res))
        return ERROR; 

    int n = Mtx_size;
    int c_ij = 0;

    for (int k = 0; k < n; k++)
    {
         c_ij += *(Mtx_1 + i * n + k) * *(Mtx_2 + k * n + j);
    }

    *(Mtx_res + i * n + j) = c_ij;

    return SUCCESS;
}

int PrintMtx(int *Mtx, int Mtx_size)
{
    if (!Mtx)
        return ERROR;

    int n = Mtx_size;
    int count = 0;

    for (int i = 0; i < n * n; i++)
    {
        printf("%d ", Mtx[i]);
        count++;
        if (count == n)
        {
            printf("\n");
            count = 0;
        }
    }
    
    return SUCCESS;
}