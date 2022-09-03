#include "CP_evaluation.h"

double time_start() {
    gettimeofday(&time_val_1, NULL);
    printf("time_val_1: %ld\n", time_val_1.tv_usec);

    return time_val_1.tv_usec;
}

double time_stop() {
    double resault = 0;
    gettimeofday(&time_val_2, NULL);
    printf("time_val_1: %ld\n", time_val_1.tv_usec);
    printf("time_val_2: %ld\n", time_val_2.tv_usec);
    data_time_val.tv_sec = time_val_2.tv_sec - time_val_1.tv_sec;
    data_time_val.tv_usec = time_val_2.tv_usec - time_val_1.tv_usec;
    if (data_time_val.tv_usec < 0) {
        data_time_val.tv_sec--;
        data_time_val.tv_usec += 1000000;
    }

    resault = (double) data_time_val.tv_sec * 1000 + data_time_val.tv_usec / 1000;
    printf("Tmth: %lf\n", resault);

    return resault;
}

void first_CPE_check() {
    int val_1 = 7, val_2 = 5;
    double val_res = 0;
    time_start();
    val_res = 5 * ((val_1 - val_2) + val_1) - (val_2 / val_1) * 4.5 - 1.12;
    printf("Time: %lf Resault: %lf\n", time_stop(), val_res);
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
    char c;
    int program_option = 0;
    printf("Plese, enter program option:\n1. gettimeofday().\n");
    printf("2. times()\n3. processor cycle counter.\n");
    if ((scanf("%d%c", &program_option, &c) == 2) && (c == '\n')) {
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
    }
}
