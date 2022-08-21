    #include <stdio.h>
    #include <math.h>
    #include <assert.h>
    
    enum Roots
    {
        TWO_ROOTS = 2,
        ONE_ROOTS = 1,
        NO_ROOTS = 0,
        INF_ROOTS = -1
    };
    
    const double EPSILON_ZERO = 0.00001;
    
    
    int QuadraticSolver(double a, double b, double c, double *x1, double *x2);
    Roots LinearSolver(double b, double c, double *x1);
    void RootsPrinter(int roots_cnt, double x1, double x2);
    int isZero(double o);
    
    
    
    int main()
    {
        double a = 0;
        double b = 0;
        double c = 0;
    
        char quitbutton = ' ';
        printf("q to leave ; ENTER to continue");
        while ((quitbutton = getchar()) != 'q')
        {
           // while ((quitbutton = getchar()) != '\n')
                //continue;
            
            printf("Please, write coefficents a, b, c of quadratic equation \"ax^2 + bx + c = 0\" \n");
            printf("Or write 'q' to leave.");

            if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
            {
                printf("Error in getting coeffs.\n");
                continue;
            }
        
            double x1 = 0;
            double x2 = 0;
        
            int roots_cnt = QuadraticSolver(a, b, c, &x1, &x2);
        
            RootsPrinter(roots_cnt, x1, x2);
        
            quitbutton = getchar(); //сюда enter который от scanf остался 

        }
    
    }
    
    int QuadraticSolver(double a, double b, double c, double *x1, double *x2)
    {
        int roots_cnt = 0; 
        double discrim = pow(b * b - 4 * a * c, 0.5);
    
        if (isZero(a))
        {
            roots_cnt = LinearSolver(b, c, x1);
            return roots_cnt;
        }
    
        if(isZero(discrim))
        {
            *x1 = -b / (2 * a);
            return ONE_ROOTS;
        }
        else if(discrim > EPSILON_ZERO)
        {
            *x1 = (-b + discrim) / (2 * a);
            *x2 = (-b - discrim) / (2 * a);
            return TWO_ROOTS;
        }
        else 
            return NO_ROOTS;
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
     