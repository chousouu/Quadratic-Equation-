#ifndef SOLVEQE_H
#define SOLVEQE_H

#include <stdio.h>
#include <math.h>
#include <string.h>

enum Roots
{
    TWO_ROOTS = 2,
    ONE_ROOTS = 1,
    NO_ROOTS  = 0,
    INF_ROOTS = -1
};

struct QuadrData
    {
        double a; 
        double b; 
        double c;
        int roots_cnt;
        float x1;
        float x2;
    };


const double EPSILON_ZERO = 0.00001; // min. distance between unequal doubles

/**
 * @brief This program solves quadratic equations.
 * 
 * @param[in] a a-coefficient 
 * @param[in] b b-coefficient
 * @param[in] c c-coefficient
 *  
 * @param [out] x1 Pointer to the first root
 * @param [out] x2 Pointer to the second root
 * 
 * @return Number of Roots
 */
int QuadraticSolver(double a, double b, double c, double *x1, double *x2);

/**
 * @brief This program solves linear equations
 * 
 * @param[in] b 
 * @param[in] c 
 * @param[out] x1 
 * 
 * @return Number of Roots 
 */
Roots LinearSolver(double b, double c, double *x1);
int isZero(double o);

/**
 * @brief Prints result of the test into terminal
 * 
 * @param result 
 * @param succesful_tests 
 */
void TestResult(int result, int *succesful_tests, int i);

/**
 * @brief Unit Tests
 * 
 * @param[in] x1 
 * @param[in] x2  
 * @return amount of false tests.
 */
int QETester(double *x1, double *x2);

#endif // SOLVEQE_H
