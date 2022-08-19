#include <stdio.h>
#include <math.h>
#include <assert.h>

enum 
{
    TWO_ROOTS = 2,
    ONE_ROOTS = 1,
    NO_ROOTS = 0,
    NOT_EQUATION = -1
};

const double EPSILON_ZERO = 0.00001;

int CoefCheck(double a, double b, double c, double *x1, double *x2);
int LinearSolver(double b, double c, double *x1);
int QuadraticSolver(double a, double b, double c, double *x1, double *x2);
int OneRootSolve(double a, double b, double discrim, double *x1);
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
        roots_cnt = LinearSolver(b, c, x1);
    }
    return roots_cnt;
}

int LinearSolver(double b, double c, double *x1)
{
    if (fabs(b) < EPSILON_ZERO)
    {
        return NOT_EQUATION;
    }
    else if ( fabs(c) < EPSILON_ZERO)
    {
        *x1 = 0;
    }
    else 
    {
        *x1 = -(c / b);
    }
    return ONE_ROOTS;
}

int QuadraticSolver(double a, double b, double c, double *x1, double *x2)
{
    int roots_cnt = 0; 
    double discrim = b * b - 4 * a * c;
    
    roots_cnt = CoefCheck(a, b, c, x1, x2);

    if (roots_cnt != 0) 
    {
        return roots_cnt;
    }
    else if (discrim == 0)
    {
        roots_cnt = OneRootSolve(a, b, discrim, x1);
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

    

int OneRootSolve(double a, double b, double discrim, double *x1)
{
    *x1 = -b / (2 * a);
    return ONE_ROOTS;
}

int TwoRootSolve(double a, double b, double discrim, double *x1, double *x2)
{
    discrim = pow(discrim, 0.5);

    *x1 = (-b + discrim) / (2 * a);
    *x2 = (-b - discrim) / (2 * a);
    
    return TWO_ROOTS;
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
            printf("Root of \"%.5fx %+.5f = 0\" : x = %.2f\n", b, c, x1);
        }
        else 
        {
            printf("Root of \" %.5lfx^2 + %.5lfx + %.5lf = 0 \" :\nx = %-6.5f", a, b, c, x1);
        }
    }

    else if (roots_cnt == NO_ROOTS)
    {
        printf("\"%.5lfx^2 + %.5lfx + %.5lf = 0 \" does not have roots", a, b, c);
    }
    else if (roots_cnt == NOT_EQUATION)
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
}

 