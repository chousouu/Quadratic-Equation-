#include "SolveQE.h"
#include "inout.h"


int main(int argc, char *argv[])
{
    double a = 0;
    double b = 0;
    double c = 0;
            
    double x1 = 0;
    double x2 = 0;

    if (argc == 1) //user mode
    {   
        printf("Please, write coefficents a, b, c of quadratic equation \"ax^2 + bx + c = 0\" \n");
        while(true)
        {   
                if (GetCoeffs(&a, &b, &c))
                {
                    break;
                }
                int roots_cnt = QuadraticSolver(a, b, c, &x1, &x2);
                RootsPrinter(roots_cnt, x1, x2);
        }
    }
    else    
    {  
        if(argc == 2 && strncmp(argv[1], "-t", 3) == 0)
        {
            int failed_test = QETester(&x1, &x2);

            if(failed_test == 0)
            {
                printf("All tests completed.");
            }
            else 
            {
                printf("Theres %d Failed Tests", failed_test);
            }
        }
        else
        {
            printf("ERROR. Expected less than 3 arguments. Recieved %d arguments. \n", argc);
        }

    }
}   