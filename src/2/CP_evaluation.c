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

    printf("Time: %lf \n", (double)((time_val_1.tv_sec)));
    printf("Time: %lf \n", (double)((time_val_2.tv_sec)));
    printf("Time: %lf \n", (double)((time_val_1.tv_usec)));
    printf("Time: %lf \n", (double)((time_val_2.tv_usec)));
    resault = (double) (data_time_val.tv_sec + data_time_val.tv_usec) / 1000;

    return resault;
}

void first_CPE_check() {
    int val_1 = 7, val_2 = 5;
    double val_res = 0;
    matrix_t matrix_1, matrix_2;
    time_start();
    val_res = 5 * ((val_1 - val_2) + val_1) - (val_2 / val_1) * 4.5 - 1.12;
    printf("Time: %lf Resault: %lf usec(microsec)\n", time_stop(), val_res);
}

// *****

/* void time_start_2() {
    times(&tmsBegin);
}

long time_stop_2() {
    long res = 0;
    times(&tmsEnd);
    res = ((tmsEnd->tms_utime - tmsBegin->tms_utime)+
        (tmsEnd->tms_stime - tmsBegin->tms_stime)) * 1000 / CLK_TCK;
    return res;
}

void second_CPE_check() {
    int val_1 = 7, val_2 = 5;
    double val_res = 0;
    time_start();
    val_res = 5 * ((val_1 - val_2) + val_1) - (val_2 / val_1) * 4.5 - 1.12;
    printf("Time: %lf Resault: %lf\n", time_stop(), val_res);
} */

int main() {
    system("sync");
    printf("\033c");
    s21_create_matrix(5, 7);
    s21_create_matrix(7, 5);

    char c;
    int program_option = 0;
    printf("Plese, enter program option:\n1. gettimeofday().\n");
    printf("2. times()\n3. processor cycle counter.\n0. exit\n");
    while(1) {
        if ((scanf("%d%c", &program_option, &c) == 2) && (c == '\n') && (program_option != 0)) {
            switch(program_option) {
                case 1:
                    first_CPE_check();
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    printf("Invalid input! Value out of range!\n");
                    break;
            }
        } else {
            printf("\033c");
            break;
        }
        printf("Plese, enter program option:\n1. gettimeofday().\n");
        printf("2. times()\n3. processor cycle counter.\n0. exit\n");
    }
}
