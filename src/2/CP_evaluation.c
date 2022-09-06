#include "CP_evaluation.h"

double time_start() {
    gettimeofday(&time_val_1, NULL);
    return time_val_1.tv_usec;
}

double time_stop() {
    double resault = 0;
    gettimeofday(&time_val_2, NULL);
    data_time_val.tv_sec = time_val_2.tv_sec - time_val_1.tv_sec;
    data_time_val.tv_usec = time_val_2.tv_usec - time_val_1.tv_usec;
    if (data_time_val.tv_usec < 0) {
        data_time_val.tv_sec--;
        data_time_val.tv_usec += 1000000;
    }
    resault = (double) (data_time_val.tv_sec + data_time_val.tv_usec) / 1000;

    return resault;
}

double CPE_check(int rows, int cols) {
    matrix_t matrix_1, matrix_2;
    matrix_1 = s21_create_matrix(rows, cols);
    matrix_2 = s21_create_matrix(cols, rows);
    s21_rand_matrix(&matrix_1);
    s21_rand_matrix(&matrix_2);
    printf("Random input data:\n");
    time_start();
    matrix_1 = s21_sum_matrix(&matrix_1, &matrix_1);
    matrix_1 = s21_sum_matrix(&matrix_2, &matrix_2);
    double res = time_stop();
    printf("Time: %lf usec(microsec)\n", res);
    s21_remove_matrix(&matrix_1);
    s21_remove_matrix(&matrix_2);

    return res;
}

double calculate_score(int * res_array, int res_array_size, double average) {
    double resault;
    for (int i = 0; i < res_array_size; i++) {
        resault += 1 / (1 / res_array[i]);
    }

    return pow(1 / (1 / ), -1)
}

void create_report(int number_of_tests, double *res_array, double average_test_time,
    double despersion, double standart_deviation) {
    FILE *report_csv;
    report_csv = fopen("report.csv", "w");
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
        fprintf(report_csv, "%lf;", calculate_score(&res_array, number_of_tests, average_test_time););
    }
}

int main() {
    system("sync");
    printf("\033c");
    char c;
    int number_of_tests = 0;
    printf("Plese, enter number of tests: ");
    if ((scanf("%d%c", &number_of_tests, &c) == 2) && (c == '\n') && (number_of_tests > 10)) {
        double res_array[number_of_tests];
        double average_test_time = 0, despersion = 0;
        for (int i = 0; i < number_of_tests; i++) {
            printf("Test #%d:\nTest resault:", (i + 1));
            res_array[i] = CPE_check(1000, 1000);
            average_test_time += res_array[i];
        }
        average_test_time = (average_test_time) / number_of_tests;
        for (int i = 0; i < number_of_tests; i++) {
            despersion += powl(res_array[i] - average_test_time, 2); 
        }
        printf("\n");
        despersion = despersion / number_of_tests;
        printf("Average test time for a typical task: %lf\n", average_test_time);
        printf("Dispersion for a typical task: %lf\n", despersion);
        printf("Standart deviation for a typical task: %lf\n", sqrt(despersion));
        create_report(number_of_tests, res_array, average_test_time, despersion, sqrt(despersion));    
    } else {
        printf("\033c");
    }
}
