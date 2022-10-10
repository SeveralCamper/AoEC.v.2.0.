#ifndef SRC_MEM_SYS_PERFORMANCE_EVAL
#define SRC_MEM_SYS_PERFORMANCE_EVAL

#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>

//  Computing performance evaluation

double meanSquareDeviation(double array[], int n, char combination);
long int writeTimeFile(int *block, long int size, std::string path);
long int writeTime(int *block, long int size);
long int readTime(int *block, long int size);

#endif //  SRC_MEM_SYS_PERFORMANCE_EVAL
