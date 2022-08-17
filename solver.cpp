#include <stdio.h>
#include <math.h>
#include <assert.h>

const int TWO_ROOTS = 2;
const int ONE_ROOTS = 1;
const int NO_ROOTS = 0;
const double EPSILON_ZERO = 0.00001;

void NotEquation(double c);
double Disc(double a, double b, double c);
void CoefCheck(double a, double b, double c);
void QuadraticSolver(double a, double b, double c, double *x1, double *x2);
void OneRootSolve(double a, double b, double discrim, double *x1, double *x2);
void TwoRootSolve(double a, double b, double discrim, double *x1, double *x2);
void RootsPrinter(int roots_cnt, double a, double b, double c, double x1, double x2);


int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    printf("Please, write coefficents a, b, c of quadratic equation \"ax^2 + bx + c = 0\" \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    CoefCheck(a, b, c);

}

void CoefCheck(double a, double b, double c)
{
    double x1 = 0;
    double x2 = 0;

    if (fabs(a) < EPSILON_ZERO )
    {
        if (fabs(b) < EPSILON_ZERO)
        {
            NotEquation(c);
        }
        else 
        {
            x1 = -( c / b);
            x2 = 0;
            printf("Root of \"%.5fx %+.5f = 0\" : x1 = %.2f\n", b, c, x1 );
        }
    }
    else 
    {
        QuadraticSolver(a, b, c, &x1, &x2);
    }
}

double Disc(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

void NotEquation(double c)
{
    if (fabs(c) < EPSILON_ZERO)
    {
        printf("0 = 0.");
    }
    else 
    {
        printf("%.2lf = 0. This is just wrong.", c);
    }
}

void QuadraticSolver(double a, double b, double c, double *x1, double *x2)
{
    int roots_cnt = 0; 
    double discrim = disc(a,b,c);

    if (discrim == 0)
    {
        roots_cnt = ONE_ROOTS;
        OneRootSolve(a, b, discrim, x1, x2);
        RootsPrinter(roots_cnt, a, b, c, *x1, *x2);
    }
    else if (discrim > 0)
    {
        roots_cnt = TWO_ROOTS;
        TwoRootSolve(a, b, discrim, x1, x2);
        RootsPrinter(roots_cnt, a, b, c, *x1, *x2);
    }
    else 
    {
        roots_cnt = NO_ROOTS;
        RootsPrinter(roots_cnt, a, b, c, *x1, *x2);
    }
}

void OneRootSolve(double a, double b, double discrim, double *x1, double *x2)
{
    *x1 = -b / (2 * a);
    *x2 = 0;
}

void TwoRootSolve(double a, double b, double discrim, double *x1, double *x2)
{
    *x1 = (-b + sqrt(discrim)) / (2 * a);
    *x2 = (-b - sqrt(discrim)) / (2 * a);
}

void RootsPrinter(int roots_cnt, double a, double b, double c, double x1, double x2)
{
    if (roots_cnt == TWO_ROOTS)
    {
        printf("Roots of \" %.5fx^2%+.5fx%+.5f = 0 \" :\nx1 = %-6.5f x2 = %-6.5f", a, b, c, x1, x2);
    }
    else if (roots_cnt == ONE_ROOTS)
    {
        printf("Root of \" %.5lfx^2 + %.5lfx + %.5lf = 0 \" :\nx1 = %-6.5f", a, b, c, x1);
    }
    else if (roots_cnt == NO_ROOTS)
    {
        printf("\"%.5lfx^2 + %.5lfx + %.5lf = 0 \" does not have roots", a, b, c);
    }
}

 