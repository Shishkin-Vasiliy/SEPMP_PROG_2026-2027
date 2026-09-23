// gamma-function
#include <stdio.h>
#include <math.h>

double gamma(double x);
int DblCmp(double a, double b);

int main(void)
{
    double G = 0;
    double x = 0;

    scanf("%lg", &x);

    G = gamma(x);

    printf("G(%lg) = %lg\n", x, G);

    return 0;
}

double gamma(double x)
{
    const double step = 1e-2;
    const double eps = 1e-10;

    double G = 0;
    double t = 0;
    double dS = 0;

    do
    {
        t += step;
        dS = pow(t, x - 1) * exp(-t) * step;
        G += dS;
        printf("dS = %lg, G = %lg, t = %lg\n", dS, G, t);
    }
    while (DblCmp(dS, eps) > 0);

    return G;
}

int DblCmp(double a, double b)
{
    const double EPSILON = 1e-11;

    if (fabs(a - b) < EPSILON)
        return 0;
    
    if (a - b > EPSILON)
        return 1;

    else   
        return -1;
}