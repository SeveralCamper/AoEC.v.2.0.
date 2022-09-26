#include "MemSysPerformanceEval.h"

char *argv_parser(char *expected, char* argv[]) {
    int i = 0;
    while(argv[i]) {
        if (expected[i] == argv[i]) {
            return argv[i + 1];
        }
        i++;
    }
    return "";
}

int main(int argc, char* argv[]) {
    int exit_flag = 0;
    system("sync");
    printf("\033c");
    char *mode_string = argv_parser("-m", argv);
    char *size_string = argv_parser("-b", argv);
    char *path_string = argv_parser("-p", argv);
    char *launch_count_string = argv_parser("-l", argv);

    if (*mode_string == "" || *size_string == "" || *launch_count_string == "" ||
    (*path_string == "" && mode_string != "RAM")) {
        exit_flag = 1;
    }

    if (exit_flag != 1) {
        unsigned long long size = calculate_size(size_string);
        unsigned long long launch_count = stoull(launch_count_string);
        unsigned long long *test_results;
        for (int i = 0; i < )
        if (mode_string == "RAM") {
            test_results = test(size, launch_count);
        } else {
            test_results = test(size, launch_count, path_string);
        }

        calculate_and_write_statistic_into_file(test_results, mode_string, size, launch_count);
    }

    return 0;
}