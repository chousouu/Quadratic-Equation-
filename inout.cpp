#include "SolveQE.h"

int GetCoeffs(double *a, double *b, double *c)
{
    while (scanf("%lf %lf %lf", a, b, c) != 3)
    {   
        if (getchar() == 'q')
        {
            return 1;            
        }


        while(getchar() != '\n')
        {
            ;
        }

       printf("Error in reading coeffs.\n");
    }
    return 0;
}


void RootsPrinter(int roots_cnt, double x1, double x2)
{
    switch(roots_cnt)
    {
        case TWO_ROOTS: 
            printf ("x1 = %.5f ; x2 = %.5f\n", x1, x2);
            break;
        case ONE_ROOTS:
            printf ("x = %.5f\n", x1);
            break;
        case NO_ROOTS:
            printf ("No roots.\n");
            break;
        case INF_ROOTS:
            printf("Inf. roots\n");
            break;
    }
}
