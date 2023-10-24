#ifndef TASKS_KULIKOV_A_MIN_IN_MATR_H_
#define TASKS_KULIKOV_A_MIN_IN_MATR_H_

#include <boost/serialization/vector.hpp>
#include <vector>

std::vector<int> getRandomMatrix(int m, int n);
std::vector<size_t> getParallelMin(std::vector<int> glob_matr, int m, int n);
std::vector<size_t> getSequentialMin(std::vector<int> matr, int m);

#endif  // TASKS_KULIKOV_A_MIN_IN_MATR_H_