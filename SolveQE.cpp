#include "SolveQE.h"

static const QuadrData Tests[] = 
    { // a          b              c    nRoots         x1   x2      
        {1.0,       0.0,          -1.0, TWO_ROOTS,     1.0, -1.0},
        {0.0,       1.0,          -3.0, ONE_ROOTS,     3.0, NAN},
        {1.0,       0.0,           1.0,  NO_ROOTS,     NAN, NAN},
        {0.0,       0.0,           0.0, INF_ROOTS,     NAN, NAN},
        {1.0, -0.000145, 0.00000000525, ONE_ROOTS, 0.00007, NAN},
    };

int QuadraticSolver(double a, double b, double c, double *x1, double *x2)
{
    int roots_cnt = 0; 

    if (isZero(a))
    {
        roots_cnt = LinearSolver(b, c, x1);
        *x2 = NAN;
        return roots_cnt;
    }
    // x^2 = 9 
/*  if(isZero(b))
    {
        *x1 = sqrt( c / a);
        *x2 = -sqrt( c / a);
    }
    // X^2 + x = 0; x (x + 1) = 0
*/
    double discrim = sqrt(b * b - 4 * a * c);

    if(isZero(discrim))
    {
        *x1 = -b / (2 * a);
        *x2 = NAN;
        return ONE_ROOTS;
    }
    else if(discrim > EPSILON_ZERO) // сравнить_даблы(Дискриминант, 0) == БОЛЬШЕ
    {
        *x1 = (-b + discrim) / (2 * a);
        *x2 = (-b - discrim) / (2 * a);
        return TWO_ROOTS;
    }
    else 
    {
        *x1 = NAN;
        *x2 = NAN;
        return NO_ROOTS;
    }
}
    
Roots LinearSolver(double b, double c, double *x1)
{
    if (isZero(b)) 
    {
        if (isZero(c))
        {
            return INF_ROOTS;
        }
        else 
        {
            return NO_ROOTS;
        }
    }
    else if (isZero(c))
    {
        *x1 = 0;
    }
    else 
    {
        *x1 = -(c / b);
    }
    
    return ONE_ROOTS;
}

int isZero(double o)
{
    return (fabs(o) < EPSILON_ZERO);
}

void TestResult(int result, int *failed_test, int i)
{
    if (result)
    {
        printf("%d.Test COMPLETED\n", i + 1);
    }
    else 
    {
        printf("%d.Test FAILED\n", i+1);
        (*failed_test)++;
    }
}

int QETester(double *x1, double *x2)
{
    int failed_test = 0;
    
    const int TEST_AMOUNT = sizeof (Tests) / sizeof (Tests[0]);

    for (int i = 0; i < TEST_AMOUNT; i++)
    {
        int result = 0;
        if (QuadraticSolver(Tests[i].a, Tests[i].b, Tests[i].c, x1, x2) == Tests[i].roots_cnt)
        {
            if (isnan(Tests[i].x2) && !isnan(Tests[i].x1))
            {
                result = (isnan(*x2) && isZero(*x1 - Tests[i].x1));
            }
            else if (isnan(Tests[i].x1) && isnan(Tests[i].x2))
            {
                result = (isnan(*x2) && isnan(*x1));
            }
            else 
            {
                result = (isZero(*x1 - (Tests[i].x1)) && isZero(*x2 - Tests[i].x2));
            }
        } 
        TestResult(result, &failed_test, i);
    }
    
    return failed_test;
}
