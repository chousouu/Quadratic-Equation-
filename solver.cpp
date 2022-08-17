#include <stdio.h>
#include <math.h>
#include <assert.h>

#define TWO_ROOTS 2
#define ONE_ROOTS 1
#define NO_ROOTS 0

double DISC(double a, double b, double c);
void ONE_ROOT_SOLVE(double a, double b, double discrim, double *x1, double *x2);
void TWO_ROOT_SOLVE(double a, double b, double discrim, double *x1, double *x2);
void ROOTS_PRINTER(int roots, double a, double b, double c, double x1, double x2);

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    printf("Please, write coefficents a, b, c of quadratic equation \"ax^2 + bx + c = 0\" \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    assert(a); 

    int roots = 0; 
    double discrim = DISC(a,b,c);
    double x1 = 0;
    double x2 = 0;

    if (discrim == 0)
    {
        roots = ONE_ROOTS;
        ONE_ROOT_SOLVE(a, b, discrim, &x1, &x2);
        ROOTS_PRINTER(roots, a, b, c, x1, x2);
    }
    else if (discrim > 0)
    {
        roots = TWO_ROOTS;
        TWO_ROOT_SOLVE(a, b, discrim, &x1, &x2);
        ROOTS_PRINTER(roots, a, b, c, x1, x2);
    }
    else 
    {
        roots = NO_ROOTS;
        ROOTS_PRINTER(roots, a, b, c, x1, x2);
    }


}

double DISC(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

void ONE_ROOT_SOLVE(double a, double b, double discrim, double *x1, double *x2)
{
    *x1 = -b / (2 * a);
    *x2 = 0;
}

void TWO_ROOT_SOLVE(double a, double b, double discrim, double *x1, double *x2)
{
    *x1 = (-b + sqrt(discrim)) / (2 * a);
    *x2 = (-b - sqrt(discrim)) / (2 * a);
}

void ROOTS_PRINTER(int roots, double a, double b, double c, double x1, double x2)
{
    if (roots == TWO_ROOTS)
    {
        printf("Roots of \" %.2fx^2%+.2fx%+.2f = 0 \" :\nx1 = %-6.2f x2 = %-6.2f", a, b, c, x1, x2);
    }
    else if (roots == ONE_ROOTS)
    {
        printf("Root of \" %.2lfx^2 + %.2lfx + %.2lf = 0 \" :\nx1 = %-6.2f", a, b, c, x1);
    }
    else if (roots == NO_ROOTS)
    {
        printf("\"%.2lfx^2 + %.2lfx + %.2lf = 0 \" does not have roots", a, b, c);
    }
}