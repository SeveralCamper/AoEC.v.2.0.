#ifndef SRC_CP_EVALUTION_H_
#define SRC_CP_EVALUTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "my_matrix/s21_matrix.h"


// Алина
//  Computing performance evaluation

//  gettimeofday()
struct timeval time_val_1, time_val_2, data_time_val;

void first_CPE_check(int rows, int cols);

double time_start();
double time_stop();

//  times()

// struct tms tmsBegin, tmsEnd;

void second_CPE_check();

double time_start_2();
double time_stop_2();

//clock_t times(struct tms *buf);

#endif  //  SRC_CP_EVALUTION_H_
