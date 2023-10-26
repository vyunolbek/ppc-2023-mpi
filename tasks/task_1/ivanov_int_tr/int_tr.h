#ifndef TASKS_KULIKOV_A_MIN_IN_MATR_H_
#define TASKS_KULIKOV_A_MIN_IN_MATR_H_

typedef double (*func)(double);

double function(double x);

double trapezium(double a, double b, func f);

double getParallelOperations(double a, double b, int N, func f);

#endif  // TASKS_KULIKOV_A_MIN_IN_MATR_H_