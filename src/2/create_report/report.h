#ifndef SRC_REPORT_H_
#define SRC_REPORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "../my_matrix/s21_matrix.h"
#include "../CP_evaluation.h"

void create_report(int number_of_tests, double *res_array, double average_test_time,
double despersion, double standart_deviation, FILE *report_csv);
void create_report_float(int number_of_tests, float *res_array, double average_test_time,
double despersion, double standart_deviation, FILE *report_csv);
void create_report_int(int number_of_tests, int *res_array, double average_test_time,
double despersion, double standart_deviation, FILE *report_csv);

double calculate_score(double * res_array, int res_array_size, double average);

#endif  //  SRC_REPORT_H_
