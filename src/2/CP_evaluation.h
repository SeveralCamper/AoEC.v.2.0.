#ifndef SRC_CP_EVALUTION_H_
#define SRC_CP_EVALUTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "my_matrix/s21_matrix.h"

//  Computing performance evaluation

//  gettimeofday()
struct timeval time_val_1, time_val_2, data_time_val;

double CPE_check(int rows, int cols);

double time_start();
double time_stop();
void create_report(int number_of_tests, double *res_array, double average_test_time,
double despersion, double standart_deviation);

#endif  //  SRC_CP_EVALUTION_H_
