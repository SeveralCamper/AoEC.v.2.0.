#include "report.h"

double calculate_score(double * res_array, int res_array_size, double average) {
    double resault;
    for (int i = 0; i < res_array_size; i++) {
        resault += 1 / (1 / res_array[i]);
    }

    return pow(1 / (1 / average), -1);
}

double calculate_score_float(float * res_array, int res_array_size, double average) {
    double resault;
    for (int i = 0; i < res_array_size; i++) {
        resault += 1 / (1 / res_array[i]);
    }

    return pow(1 / (1 / average), -1);
}

double calculate_score_int(int * res_array, int res_array_size, double average) {
    double resault;
    for (int i = 0; i < res_array_size; i++) {
        resault += 1 / (1 / (float)res_array[i]);
    }

    return pow(1 / (1 / average), -1);
}

void create_report(int number_of_tests, double *res_array, double average_test_time,
    double despersion, double standart_deviation, FILE *report_csv) {
    fprintf(report_csv, ";");
    for (int i = 0; i < number_of_tests; i++) {
        if (i != number_of_tests - 1) {
            fprintf(report_csv, "%d;", (i+1));
        } else {
            fprintf(report_csv, "%d;\n", (i+1));
        }
    }
    fprintf(report_csv, "Pmodel;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "Intel(R) Core(TM) i5-10300H;");
    }
    fprintf(report_csv, "\nTask;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "Matrix Sum Mult Transpose CalcComplements Inverse;");
    }
    fprintf(report_csv, "\nOpType;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "matrix_t/double;");
    }
    fprintf(report_csv, "\nOpt;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "None;");
    }
    fprintf(report_csv, "\nInsCOunt;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "6;");
    }
    fprintf(report_csv, "\nTimer;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "gettimeofday();");
    }
    fprintf(report_csv, "\nTime;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", res_array[i]);
    }
    fprintf(report_csv, "\nLNum;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%d;", i);
    }
    fprintf(report_csv, "\nAvTime;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", average_test_time);
    }
    fprintf(report_csv, "\nAbsError;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", despersion);
    }
    fprintf(report_csv, "\nRelError;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf%%;", (standart_deviation) * 100);
    }
    fprintf(report_csv, "\nTaskPerf;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", calculate_score(res_array, number_of_tests, average_test_time));
    }
    fprintf(report_csv, "\n\n");
}

void create_report_int(int number_of_tests, int *res_array, double average_test_time,
    double despersion, double standart_deviation, FILE *report_csv) {
    fprintf(report_csv, ";");
    for (int i = 0; i < number_of_tests; i++) {
        if (i != number_of_tests - 1) {
            fprintf(report_csv, "%d;", (i+1));
        } else {
            fprintf(report_csv, "%d;\n", (i+1));
        }
    }
    fprintf(report_csv, "Pmodel;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "Intel(R) Core(TM) i5-10300H;");
    }
    fprintf(report_csv, "\nTask;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "Matrix Sum Mult Transpose CalcComplements Inverse;");
    }
    fprintf(report_csv, "\nOpType;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "matrix_t/double;");
    }
    fprintf(report_csv, "\nOpt;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "None;");
    }
    fprintf(report_csv, "\nInsCOunt;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "6;");
    }
    fprintf(report_csv, "\nTimer;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "gettimeofday();");
    }
    fprintf(report_csv, "\nTime;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%d;", res_array[i]);
    }
    fprintf(report_csv, "\nLNum;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%d;", i);
    }
    fprintf(report_csv, "\nAvTime;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", average_test_time);
    }
    fprintf(report_csv, "\nAbsError;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", despersion);
    }
    fprintf(report_csv, "\nRelError;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf%%;", (standart_deviation) * 100);
    }
    fprintf(report_csv, "\nTaskPerf;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", calculate_score_int(res_array, number_of_tests, average_test_time));
    }
    fprintf(report_csv, "\n\n");
}

void create_report_float(int number_of_tests, float *res_array, double average_test_time,
    double despersion, double standart_deviation, FILE *report_csv) {
    fprintf(report_csv, ";");
    for (int i = 0; i < number_of_tests; i++) {
        if (i != number_of_tests - 1) {
            fprintf(report_csv, "%d;", (i+1));
        } else {
            fprintf(report_csv, "%d;\n", (i+1));
        }
    }
    fprintf(report_csv, "Pmodel;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "Intel(R) Core(TM) i5-10300H;");
    }
    fprintf(report_csv, "\nTask;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "Matrix Sum Mult Transpose CalcComplements Inverse;");
    }
    fprintf(report_csv, "\nOpType;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "matrix_t/double;");
    }
    fprintf(report_csv, "\nOpt;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "None;");
    }
    fprintf(report_csv, "\nInsCOunt;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "6;");
    }
    fprintf(report_csv, "\nTimer;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "gettimeofday();");
    }
    fprintf(report_csv, "\nTime;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", res_array[i]);
    }
    fprintf(report_csv, "\nLNum;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%d;", i);
    }
    fprintf(report_csv, "\nAvTime;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", average_test_time);
    }
    fprintf(report_csv, "\nAbsError;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", despersion);
    }
    fprintf(report_csv, "\nRelError;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf%%;", (standart_deviation) * 100);
    }
    fprintf(report_csv, "\nTaskPerf;");
    for (int i = 0; i < number_of_tests; i++) {
        fprintf(report_csv, "%lf;", calculate_score_float(res_array, number_of_tests, average_test_time));
    }
    fprintf(report_csv, "\n\n");
}

