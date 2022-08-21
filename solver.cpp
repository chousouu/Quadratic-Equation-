#include <stdio.h>
#include <math.h>
#include <string.h>
    
enum Roots
{
    TWO_ROOTS = 2,
    ONE_ROOTS = 1,
    NO_ROOTS = 0,
    INF_ROOTS = -1
};
    
const double EPSILON_ZERO = 0.00001;
    
    
void QETester(double *x1, double *x2);

int QuadraticSolver(double a, double b, double c, double *x1, double *x2);
Roots LinearSolver(double b, double c, double *x1);
void RootsPrinter(int roots_cnt, double x1, double x2);
int isZero(double o);
    
    
    
int main(int argc, char *argv[])
{
    double a = 0;
    double b = 0;
    double c = 0;
            
    double x1 = 0;
    double x2 = 0;

//    if (argc == 1) //user mode
   // {   
        printf("Please, write coefficents a, b, c of quadratic equation \"ax^2 + bx + c = 0\" \n");
        if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        {
            printf("Error in reading coeffs.\n");
        }
        else 
        {
            int roots_cnt = QuadraticSolver(a, b, c, &x1, &x2);
            RootsPrinter(roots_cnt, x1, x2);
        }
    //}
   /*
    else 
    {
        if (argc == 2 && strcmp(argv[1], "-t") == 0)
            QETester(&x1, &x2);
    }
    */
}
    

    int QuadraticSolver(double a, double b, double c, double *x1, double *x2)
    {
        int roots_cnt = 0; 
    
        if (isZero(a))
        {
            roots_cnt = LinearSolver(b, c, x1);
            *x2 = NAN;
            return roots_cnt;
        }
    
        double discrim = pow(b * b - 4 * a * c, 0.5);

        if(isZero(discrim))
        {
            *x1 = -b / (2 * a);
            *x2 = NAN;
            return ONE_ROOTS;
        }
        else if(discrim > EPSILON_ZERO)
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
                return INF_ROOTS;
            else 
                return NO_ROOTS;
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
    
    void RootsPrinter(int roots_cnt, double x1, double x2)
    {
        switch(roots_cnt)
        {
            case TWO_ROOTS: 
                printf("x1 = %.5f ; x2 = %.5f\n", x1, x2);
                break;
            case ONE_ROOTS:
                printf("x = %.5f\n", x1);
                break;
            case NO_ROOTS:
                printf("No roots.\n");
                break;
            case INF_ROOTS:
                printf("Inf. roots\n");
                break;
        }
    }
    
    int isZero(double o)
    {
        if (fabs(o) < EPSILON_ZERO)
            return 1;
        
        return 0;
    }
     
    
    void QETester(double *x1, double *x2)
    {
        int succesful_tests = 1;
        if (QuadraticSolver(1, 0, -1, x1, x2) == TWO_ROOTS && isZero(*x1 - (1)) && isZero(*x2 - (-1)) )
        {
            printf("%d.Test Completed\n", succesful_tests);
            succesful_tests++;
        }
        else 
            printf("%d.Test Fail\n", succesful_tests);

        if (QuadraticSolver(0, 1, -3, x1, x2) == ONE_ROOTS &&  isnan(*x2) && isZero(*x1 - 3))
        {
            printf("%d.Test Completed\n", succesful_tests);
            succesful_tests++;
        }
        else 
            printf("%d.Test Fail\n", succesful_tests);

        if (QuadraticSolver(1, 0, 1, x1, x2) == NO_ROOTS &&  isnan(*x2) && isnan(*x1))
        {
            printf("%d.Test Completed\n", succesful_tests);
            succesful_tests++;
        }
        else 
            printf("%d.Test Fail\n", succesful_tests);

        if (QuadraticSolver(0, 0, 0, x1, x2) == INF_ROOTS &&  isnan(*x2) && isnan(*x1))
        {
            printf("%d.Test Completed\n", succesful_tests);
            succesful_tests++;
        }
        else 
            printf("%d.Test Fail\n", succesful_tests);

        if (QuadraticSolver(1, -0.000145, 0.00000000525, x1, x2) == ONE_ROOTS && isnan(*x2) && isZero(*x1 - 0.00007))
        {
            printf("%d.Test Completed\n", succesful_tests);
            succesful_tests++;
        }
        else 
            printf("%d.Test Fail\n", succesful_tests);


    }   