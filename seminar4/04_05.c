#include <math.h>

int DblCmp(double a, double b);
int solve_quadratic(double a, double b, double c, double *px1, double *px2)
{
    if (DblCmp(a, 0) == 0)
    {
        if (DblCmp(b, 0) == 0)
        {
            if (DblCmp(c, 0) != 0)
                return 0;
            return -1;
        }
        else
        {
            *px1 = -c / b;
            return 1;
        }         
    }
    else
    {   
        double D = b * b - 4 * a * c;
        if (DblCmp(D, 0) == 0)
        {
            *px1 = -b / (2 * a);
            return 1;
        }
        else if (DblCmp(D, 0) > 0)
        {
            *px1 = (-b + sqrt(D)) / (2 * a);
            *px2 = (-b - sqrt(D)) / (2 * a);
            return 2;
        }
        else 
            return 0;
    }
}

int DblCmp(double a, double b)
{
    const double EPSILON = 1e-10;

    if (fabs(a - b) < EPSILON)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}