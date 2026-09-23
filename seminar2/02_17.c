#include <stdio.h>
#include <math.h>

int DblCmp(double a, double b);
int intersect(double x1, double y1, double r1, double x2, double y2, double r2);
int main(void)
{
    double x1 = 0, y1 = 0, r1 = 0;
    double x2 = 0, y2 = 0, r2 = 0;

    scanf("%lg %lg %lg %lg %lg %lg", &x1, &y1, &r1, &x2, &y2, &r2);

    if (intersect(x1, y1, r1, x2, y2, r2) < 0)
        printf("Intersect\n");

    else if (intersect(x1, y1, r1, x2, y2, r2) > 0)
        printf("Don't intersect\n");

    else
        printf("Touch\n");

    return 0;

}

int DblCmp(double a, double b)
{
    const double EPSILON = 1.0 / 100000;

    if (fabs(a - b) < EPSILON)
        return 0;
    
    if (a - b > EPSILON)
        return 1;

    else   
        return -1;
}

int intersect(double x1, double y1, double r1, double x2, double y2, double r2)
{
    double d = 0;
    d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (DblCmp(d, r2 + r1) == 0)
        return 0;

    else if (DblCmp(d, r2 + r1) > 0)
        return 1;

    else
        return -1;
}