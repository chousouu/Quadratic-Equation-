#ifndef INOUT_H
#define INOUT_H

/**
 * @brief Prints roots of equation 
 * @param[in] roots_cnt 
 * @param[in] x1 
 * @param[in] x2 
 */

void RootsPrinter(int roots_cnt, double x1, double x2);

/**
 * @brief Gets the Coefficients of equation
 * 
 * @param[out] a a-coefficient 
 * @param[out] b b-coefficient
 * @param[out] c c-coefficient
 * 
 * @return 1 if program exit is requiered else 0
 */
int GetCoeffs(double *a, double *b, double *c);

#endif// INOUT_H