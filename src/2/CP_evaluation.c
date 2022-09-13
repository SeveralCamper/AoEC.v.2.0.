#include "create_report/report.h"
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

double* CPE_check(int rows, int cols) {
    double* res_arr = malloc(sizeof(double) * 3);
    matrix_t matrix_1, matrix_2;
    matrix_t_i matrix_1_i, matrix_2_i;
    matrix_t_f matrix_1_f, matrix_2_f;
    matrix_1 = s21_create_matrix(rows, cols);
    matrix_2 = s21_create_matrix(cols, rows);
    matrix_1_i = s21_create_matrix_int(rows, cols);
    matrix_2_i = s21_create_matrix_int(cols, rows);
    matrix_1_f = s21_create_matrix_float(rows, cols);
    matrix_2_f = s21_create_matrix_float(cols, rows);
    s21_rand_matrix(&matrix_1);
    s21_rand_matrix(&matrix_2);
    s21_rand_matrix_int(&matrix_1_i);
    s21_rand_matrix_int(&matrix_2_i);
    s21_rand_matrix_float(&matrix_1_f);
    s21_rand_matrix_float(&matrix_2_f);
    printf("Random input data:\n");
    time_start();
    matrix_1 = s21_sum_matrix(&matrix_1, &matrix_1);
    matrix_2 = s21_sum_matrix(&matrix_2, &matrix_2);
    res_arr[0] = time_stop();
    time_start();
    matrix_1_i = s21_sum_matrix_int(&matrix_1_i, &matrix_1_i);
    matrix_2_i = s21_sum_matrix_int(&matrix_2_i, &matrix_2_i);
    res_arr[1]  = time_stop();
    time_start();
    matrix_1_f = s21_sum_matrix_float(&matrix_1_f, &matrix_1_f);
    matrix_2_f = s21_sum_matrix_float(&matrix_2_f, &matrix_2_f);
    res_arr[2] = time_stop();
    printf("Time double: %lf usec(microsec)\n", res_arr[0]);
    printf("Time float: %lf usec(microsec)\n", res_arr[1]);
    printf("Time int: %lf usec(microsec)\n", res_arr[2]);
    s21_remove_matrix(&matrix_1);
    s21_remove_matrix(&matrix_2);
    s21_remove_matrix(&matrix_1);
    s21_remove_matrix(&matrix_2);
    s21_remove_matrix(&matrix_1);
    s21_remove_matrix(&matrix_2);

    return res_arr;
}

int main() {
    system("sync");
    printf("\033c");
    char c;
    int number_of_tests = 0;
    printf("Plese, enter number of tests: ");
    if ((scanf("%d%c", &number_of_tests, &c) == 2) && (c == '\n') && (number_of_tests > 10)) {
        double ** res_array = calloc(number_of_tests, sizeof(double *));
        if (res_array != NULL) {
        for  (int i = 0; i < number_of_tests; i++) {
            res_array[i] = calloc(3, sizeof(double));
            if (res_array[i] == NULL) {
                break;
            }
        }
        double average_test_time = 0, average_test_time_i = 0, average_test_time_f = 0, despersion = 0, despersion_i = 0, despersion_f = 0;
        for (int i = 0; i < number_of_tests; i++) {
            printf("Test #%d:\nTest resault:", (i + 1));
            res_array[i] = CPE_check(10, 10);
            average_test_time += res_array[i][0];
            average_test_time_f += res_array[i][1];
            average_test_time_i += res_array[i][2];
        }
        average_test_time = (average_test_time) / number_of_tests;
        average_test_time_f = (average_test_time_f) / number_of_tests;
        average_test_time_i = (average_test_time_i) / number_of_tests;
        for (int i = 0; i < number_of_tests; i++) {
            despersion += powl(res_array[i][0] - average_test_time, 2); 
            despersion_i += powl(res_array[i][1] - average_test_time_i, 2); 
            despersion_f += powl(res_array[i][2] - average_test_time_f, 2); 
        }
        printf("\n");
        despersion = despersion / number_of_tests;
        despersion_i = despersion_i / number_of_tests;
        despersion_f = despersion_f / number_of_tests;
        printf("Average test time for a typical task (double): %lf\n", average_test_time);
        printf("Average test time for a typical task (float): %lf\n", average_test_time_f);
        printf("Average test time for a typical task (int): %lf\n\n", average_test_time_i);
        printf("Dispersion for a typical task (double): %lf\n", despersion);
        printf("Dispersion for a typical task (float): %lf\n", despersion_f);
        printf("Dispersion for a typical task (int): %lf\n\n", despersion_i);
        printf("Standart deviation for a typical task (double): %lf\n", sqrt(despersion));
        printf("Standart deviation for a typical task (float): %lf\n", sqrt(despersion_f));
        printf("Standart deviation for a typical task (int): %lf\n\n", sqrt(despersion_i));
        double * array_res_d = calloc(number_of_tests, sizeof(double));
        float * array_res_f = calloc(number_of_tests, sizeof(float));
        int * array_res_i = calloc(number_of_tests, sizeof(int));
        for (int i = 0; i < number_of_tests; i++) {
            array_res_d[i] = res_array[i][0];
            array_res_f[i] = res_array[i][1];
            array_res_i[i] = res_array[i][2];
        }
        FILE *report_csv;
        report_csv = fopen("report.csv", "w");
        create_report(number_of_tests, array_res_d, average_test_time, despersion, sqrt(despersion), report_csv);
        create_report_float(number_of_tests, array_res_f, average_test_time_f, despersion, sqrt(despersion_f), report_csv);
        create_report_int(number_of_tests, array_res_i, average_test_time_i, despersion, sqrt(despersion_i), report_csv);    
    } else {
        printf("\033c");
    }
    }
}
