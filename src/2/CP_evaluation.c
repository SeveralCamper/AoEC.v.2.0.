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
    time_start();
    printf("Random input data:\n");
    matrix_1 = s21_sum_matrix(&matrix_1, &matrix_1);
    matrix_1 = s21_sum_matrix(&matrix_2, &matrix_2);
    matrix_1 = s21_mult_matrix(&matrix_1, &matrix_2);
    matrix_1 = s21_transpose(&matrix_1);
    matrix_1 = s21_calc_complements(&matrix_1);
    matrix_1 = s21_inverse_matrix(&matrix_1);
    double res = time_stop();
    printf("Time: %lf usec(microsec)\n", res);
    s21_remove_matrix(&matrix_1);
    s21_remove_matrix(&matrix_2);

    return res;
}

int main() {
    system("sync");
    printf("\033c");
    char c;
    int number_of_tests = 0;
    printf("Plese, enter number of tests: ");
    if ((scanf("%d%c", &number_of_tests, &c) == 2) && (c == '\n') && (number_of_tests > 10)) {
        s21_create_matrix(5, 7);
        s21_create_matrix(7, 5);
        double average_test_time = 0;
        for (int i = 0; i < number_of_tests; i++) {
            printf("Test #%d:\nTest resault:", (i + 1));
            average_test_time += CPE_check(5, 7);
        }
        printf("Average test time for a typical task: %lf\n", (average_test_time) / number_of_tests);
        printf("Dispersion for a typical task: %lf\n", (average_test_time) / number_of_tests);
        printf("\n");
    } else {
        printf("\033c");
    }
}
