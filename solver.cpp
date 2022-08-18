#include <stdio.h>
#include <math.h>
#include <assert.h>

const int TWO_ROOTS = 2;
const int ONE_ROOTS = 1;
const int NO_ROOTS = 0;
const int NOT_EQUATION = -1;
const double EPSILON_ZERO = 0.00001;

void NotEquation(double c);
double Disc(double a, double b, double c);
int CoefCheck(double a, double b, double c, double *x1, double *x2);
int LinearSolver(double b, double c, double *x1);
int QuadraticSolver(double a, double b, double c, double *x1, double *x2);
int OneRootSolve(double a, double b, double discrim, double *x1, double *x2);
int TwoRootSolve(double a, double b, double discrim, double *x1, double *x2);
void RootsPrinter(int roots_cnt, double a, double b, double c, double x1, double x2);


int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    printf("Please, write coefficents a, b, c of quadratic equation \"ax^2 + bx + c = 0\" \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = 0;
    double x2 = 0;

    int roots_cnt = QuadraticSolver(a, b, c, &x1, &x2);

    RootsPrinter(roots_cnt, a, b, c, x1, x2);

}

int CoefCheck(double a, double b, double c, double *x1, double *x2)
{
    int roots_cnt = 0;

    if (fabs(a) < EPSILON_ZERO)
    {
        if (fabs(b) < EPSILON_ZERO)
        {
            roots_cnt = NOT_EQUATION;
        }
        else 
        {
            roots_cnt = LinearSolver(b, c, x1);
        }
    }
    return roots_cnt;
}

double Disc(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

int LinearSolver(double b, double c, double *x1)
{
    *x1 = -(c / b);
    return ONE_ROOTS;
}

int QuadraticSolver(double a, double b, double c, double *x1, double *x2)
{
    int roots_cnt = 0; 
    double discrim = Disc(a,b,c);
    
    roots_cnt = CoefCheck(a, b, c, x1, x2);

    if (roots_cnt != 0) 
    {
        return roots_cnt;
    }
    else if (discrim == 0)
    {
        roots_cnt = OneRootSolve(a, b, discrim, x1, x2);
    }
    else if (discrim > 0)
    {
        roots_cnt = TwoRootSolve(a, b, discrim, x1, x2);
    }
    else 
    {
        roots_cnt = NO_ROOTS;
    }

    return roots_cnt;
}

    

int OneRootSolve(double a, double b, double discrim, double *x1, double *x2)
{
    *x1 = -b / (2 * a);
    *x2 = 0;

    return ONE_ROOTS;
}

int TwoRootSolve(double a, double b, double discrim, double *x1, double *x2)
{
    *x1 = (-b + pow(discrim, 0.5)) / (2 * a);
    *x2 = (-b - pow(discrim, 0.5)) / (2 * a);
    
    return TWO_ROOTS;
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

void RootsPrinter(int roots_cnt, double a, double b, double c, double x1, double x2)
{
    if (roots_cnt == TWO_ROOTS)
    {
        if ( fabs(x1-x2) > EPSILON_ZERO)
        {
            printf("Roots of \" %.5fx^2%+.5fx%+.5f = 0 \" :\nx1 = %-6.5f x2 = %-6.5f", a, b, c, x1, x2);
        }
        else
        {
            printf("Both roots of \" %.5fx^2%+.5fx%+.5f = 0 \" are equal:\nx1 = x2 = %-6.5f", a, b, c, x1);
        }

    }

    else if (roots_cnt == ONE_ROOTS)  //LinearSolver ; OneRootSolve
    {
        if (fabs(a) < EPSILON_ZERO)
        {
            printf("Root of \"%.5fx %+.5f = 0\" : x1 = %.2f\n", b, c, x1);
        }
        else 
        {
            printf("Root of \" %.5lfx^2 + %.5lfx + %.5lf = 0 \" :\nx1 = %-6.5f", a, b, c, x1);
        }
    }

    else if (roots_cnt == NO_ROOTS)
    {
        printf("\"%.5lfx^2 + %.5lfx + %.5lf = 0 \" does not have roots", a, b, c);
    }
    else if (roots_cnt == NOT_EQUATION)
    {
        NotEquation(c);
    }
}

 