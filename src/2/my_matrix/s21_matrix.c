#include "s21_matrix.h"

int s21_correct_check(matrix_t * A) {
    int res = 0;
    if (A != NULL && A->columns > 0 && A->rows > 0 && A->matrix_type != INCORRECT_MATRIX) {
        res = 1;
    }
    return res;
}

int isinf_isnan_check(double x) {
    int res = 1;
    if (isnan(x) || isinf(x)) {
        res = 0;
    }
    return res;
}

void s21_init_matrix(matrix_t * A, int colums, int rows, int type) {
    A->columns = colums;
    A->rows = rows;
    A->matrix_type = type;
}

void s21_init_matrix_float(matrix_t_f * A, int colums, int rows, int type) { //  float
    A->columns = colums;
    A->rows = rows;
    A->matrix_type = type;
}

void s21_init_matrix_int(matrix_t_i * A, int colums, int rows, int type) { //  int
    A->columns = colums;
    A->rows = rows;
    A->matrix_type = type;
}

matrix_t s21_create_matrix(int rows, int columns) { //  double
    matrix_t new_matrix;
    if (rows > 0 && columns > 0 && (new_matrix.matrix = s21_memory_allocation(rows, columns)) != NULL) {
        s21_init_matrix(&new_matrix, columns, rows, ZERO_MATRIX);
    } else {
        new_matrix.matrix = NULL;
        s21_init_matrix(&new_matrix, 0, 0, INCORRECT_MATRIX);
    }
    return new_matrix;
}

matrix_t_f s21_create_matrix_float(int rows, int columns) { //  float
    matrix_t_f new_matrix;
    if (rows > 0 && columns > 0 && (new_matrix.matrix = s21_memory_allocation_float(rows, columns)) != NULL) {
        s21_init_matrix_float(&new_matrix, columns, rows, ZERO_MATRIX);
    } else {
        new_matrix.matrix = NULL;
        s21_init_matrix_float(&new_matrix, 0, 0, INCORRECT_MATRIX);
    }
    return new_matrix;
}

matrix_t_i s21_create_matrix_int(int rows, int columns) { //  int
    matrix_t_i new_matrix;
    if (rows > 0 && columns > 0 && (new_matrix.matrix = s21_memory_allocation_int(rows, columns)) != NULL) {
        s21_init_matrix_int(&new_matrix, columns, rows, ZERO_MATRIX);
    } else {
        new_matrix.matrix = NULL;
        s21_init_matrix_int(&new_matrix, 0, 0, INCORRECT_MATRIX);
    }
    return new_matrix;
}

void s21_fill_matrix(matrix_t *A, double iterator) {
    double iter = 0;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            iter += iterator;
            A->matrix[i][j] = iter;
        }
    }
}


void s21_remove_matrix(matrix_t *A) {
    if (s21_correct_check(A) == 1) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                A->matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
        }
        free(A->matrix);
        s21_init_matrix(A, 0, 0, INCORRECT_MATRIX);
    }
}

void s21_print_matrix(matrix_t A) {
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            if (j == A.columns - 1) {
                printf("%lf", A.matrix[i][j]);
            } else {
                printf("%lf ", A.matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int exit_flag = SUCCESS;
    if (s21_correct_check(A) == 1 && s21_correct_check(B) == 1 && A->columns == B->columns &&
    A->rows == B->rows) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j]) - fabs(B->matrix[i][j]) >= EPS
                && isinf_isnan_check(A->matrix[i][j]) == 1
                && isinf_isnan_check(B->matrix[i][j]) == 1) {
                    exit_flag = FAILURE;
                    break;
                }
            }
        }
    } else {
        exit_flag = FAILURE;
    }
    return exit_flag;
}

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    return s21_arifmetic_matrix(A, B, 1);
}

matrix_t_i s21_sum_matrix_int(matrix_t_i *A, matrix_t_i *B) {
    return s21_arifmetic_matrix_int(A, B, 1);
}

matrix_t_f s21_sum_matrix_float(matrix_t_f *A, matrix_t_f *B) {
    return s21_arifmetic_matrix_float(A, B, 1);
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
    return s21_arifmetic_matrix(A, B, 0);
}

matrix_t s21_arifmetic_matrix(matrix_t *A, matrix_t *B, int type) {
    matrix_t C;

    if (s21_correct_check(A) == 1 && s21_correct_check(B) == 1 && A->columns == B->columns
    && A->rows == B->rows) {
        C = s21_create_matrix(A->rows, A->columns);
        if (C.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < B->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    if (isinf_isnan_check(A->matrix[i][j]) == 1 && isinf_isnan_check(B->matrix[i][j]) == 1) {
                        if (type == 1) {
                            C.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                        } else {
                            C.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                        }
                    } else {
                        s21_init_matrix(&C, 0, 0, INCORRECT_MATRIX);
                        break;
                    }
                }
            }
            s21_init_matrix(&C, A->columns, A->rows, s21_matrix_type(C));
        } else {
            s21_init_matrix(&C, 0, 0, INCORRECT_MATRIX);
        }
    } else {
        s21_init_matrix(&C, 0, 0, INCORRECT_MATRIX);
    }
    return C;
}

matrix_t_i s21_arifmetic_matrix_int(matrix_t_i *A, matrix_t_i *B, int type) {
    matrix_t_i C;

    C = s21_create_matrix_int(A->rows, A->columns);
    if (C.matrix_type != INCORRECT_MATRIX) {
        for (int i = 0; i < B->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                if (isinf_isnan_check(A->matrix[i][j]) == 1 && isinf_isnan_check(B->matrix[i][j]) == 1) {
                    if (type == 1) {
                        C.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                    } else {
                        C.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                    }
                } else {
                    s21_init_matrix_int(&C, 0, 0, INCORRECT_MATRIX);
                    break;
                }
            }
        }
        s21_init_matrix_int(&C, A->columns, A->rows, 0);
    } else {
        s21_init_matrix_int(&C, 0, 0, INCORRECT_MATRIX);
    }

    return C;
}

matrix_t_f s21_arifmetic_matrix_float(matrix_t_f *A, matrix_t_f *B, int type) {
    matrix_t_f C;

    C = s21_create_matrix_float(A->rows, A->columns);
    if (C.matrix_type != INCORRECT_MATRIX) {
        for (int i = 0; i < B->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                if (isinf_isnan_check(A->matrix[i][j]) == 1 && isinf_isnan_check(B->matrix[i][j]) == 1) {
                    if (type == 1) {
                        C.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                    } else {
                        C.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                    }
                } else {
                    s21_init_matrix_float(&C, 0, 0, INCORRECT_MATRIX);
                    break;
                }
            }
        }
        s21_init_matrix_float(&C, A->columns, A->rows, 0);
    } else {
        s21_init_matrix_float(&C, 0, 0, INCORRECT_MATRIX);
    }

    return C;
}

matrix_t s21_mult_number(matrix_t *A, double number) {
    matrix_t B;

    if (s21_correct_check(A) == 1 && isinf_isnan_check(number) == 1) {
        B = s21_create_matrix(A->rows, A->columns);
        if (B.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    if (isinf_isnan_check(A->matrix[i][j]) == 1) {
                        B.matrix[i][j] = number * A->matrix[i][j];
                    } else {
                        s21_init_matrix(&B, 0, 0, INCORRECT_MATRIX);
                        break;
                    }
                }
            }
            s21_init_matrix(&B, A->columns, A->rows, s21_matrix_type(B));
        } else {
            s21_init_matrix(&B, 0, 0, INCORRECT_MATRIX);
        }
    } else {
        s21_init_matrix(&B, 0, 0, INCORRECT_MATRIX);
    }

    return B;
}

matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
    matrix_t C;

    if (s21_correct_check(A) == 1 && s21_correct_check(B) == 1 && A->columns == B->rows) {
        C = s21_create_matrix(A->rows, B->columns);
        if (C.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < C.rows; i++) {
                for (int j = 0; j < C.columns; j++) {
                    for (int k = 0; k < A->columns; k++) {
                        if (isinf_isnan_check(A->matrix[i][k]) == 1
                        && isinf_isnan_check(B->matrix[k][j]) == 1) {
                            C.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                        } else {
                            s21_init_matrix(&C, 0, 0, INCORRECT_MATRIX);
                            break;
                        }
                    }
                }
            }
            s21_init_matrix(&C, B->columns, A->rows, s21_matrix_type(C));
        } else {
            s21_init_matrix(&C, 0, 0, INCORRECT_MATRIX);
        }
    } else {
        s21_init_matrix(&C, 0, 0, INCORRECT_MATRIX);
    }

    return C;
}

matrix_t s21_transpose(matrix_t *A) {
    matrix_t B;

    if (s21_correct_check(A) == 1) {
        B = s21_create_matrix(A->columns, A->rows);
        if (B.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < B.rows; i++) {
                for (int j = 0; j < B.columns; j++) {
                    if (isinf_isnan_check(A->matrix[j][i]) == 1) {
                        B.matrix[i][j] = A->matrix[j][i];
                    } else {
                        s21_init_matrix(&B, 0, 0, INCORRECT_MATRIX);
                        break;
                    }
                }
            }
            s21_init_matrix(&B, A->rows, A->columns, s21_matrix_type(B));
        } else {
            s21_init_matrix(&B, 0, 0, INCORRECT_MATRIX);
        }
    } else {
        s21_init_matrix(&B, 0, 0, INCORRECT_MATRIX);
    }

    return B;
}

double s21_determinant(matrix_t *A) {
    double determinant = 0;

    if (s21_correct_check(A) == 1 && A->rows == A->columns) {
        if (A->rows == 1) {
            if (isinf_isnan_check(A->matrix[0][0]) == 1) {
                determinant = A->matrix[0][0];
            } else {
                determinant = NAN;
            }
        } else if (A->rows == 2) {
            if (isinf_isnan_check(A->matrix[0][0]) == 1
            && isinf_isnan_check(A->matrix[1][1]) == 1
            && isinf_isnan_check(A->matrix[1][0]) == 1
            && isinf_isnan_check(A->matrix[0][1]) == 1) {
                determinant = (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[1][0] * A->matrix[0][1]);
            }
        } else {
            for (int i = 0; i < A->columns; i++) {
                matrix_t minor = s21_minor(A, 0, i);
                if (isinf_isnan_check(A->matrix[0][i]) == 1) {
                    determinant += pow(-1, i) * A->matrix[0][i] * s21_determinant(&minor);
                } else {
                    determinant = NAN;
                }
                s21_remove_matrix(&minor);
            }
        }
    } else {
        determinant = NAN;
    }
    return determinant;
}

matrix_t s21_calc_complements(matrix_t *A) {
    matrix_t matrix_algebraic_add;

    if (s21_correct_check(A) == 1 && A->rows == A->columns) {
        matrix_algebraic_add = s21_create_matrix(A->rows, A->columns);
        if (matrix_algebraic_add.matrix_type != INCORRECT_MATRIX) {
            if (A->rows == 1) {
                    matrix_algebraic_add.matrix[0][0] = A->matrix[0][0];
            } else {
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < A->columns; j++) {
                        matrix_t minor = s21_minor(A, i, j);
                        matrix_algebraic_add.matrix[i][j] = pow((-1), i+j) * s21_determinant(&minor);
                        s21_remove_matrix(&minor);
                    }
                }
            }
            s21_init_matrix(&matrix_algebraic_add, A->columns, A->rows,
            s21_matrix_type(matrix_algebraic_add));
        } else {
            s21_init_matrix(&matrix_algebraic_add, 0, 0, INCORRECT_MATRIX);
        }
    } else {
        s21_init_matrix(&matrix_algebraic_add, 0, 0, INCORRECT_MATRIX);
    }

    return matrix_algebraic_add;
}

matrix_t s21_inverse_matrix(matrix_t *A) {
    matrix_t inverse_matrix;

    if (s21_correct_check(A) == 1 && A->columns == A->rows) {
        inverse_matrix = s21_create_matrix(A->rows, A->columns);
        if (inverse_matrix.matrix_type != INCORRECT_MATRIX) {
            double det = s21_determinant(A);
            if (isinf_isnan_check(det) == 1 && det != 0) {
                matrix_t calc_complements, union_matrix;
                calc_complements = s21_calc_complements(A);
                union_matrix = s21_transpose(&calc_complements);
                inverse_matrix = s21_mult_number(&union_matrix, (1.0/det));
                s21_remove_matrix(&union_matrix);
                s21_remove_matrix(&calc_complements);
            } else {
                s21_init_matrix(&inverse_matrix, 0, 0, INCORRECT_MATRIX);
            }
        } else {
            s21_init_matrix(&inverse_matrix, 0, 0, INCORRECT_MATRIX);
        }
    } else {
        s21_init_matrix(&inverse_matrix, 0, 0, INCORRECT_MATRIX);
    }

    return inverse_matrix;
}

double ** s21_memory_allocation(int rows, int columns) { //  double
    int error = 0;
    double ** matrix = calloc(rows, sizeof(double *));
    if (matrix != NULL) {
        for  (int i = 0; i < rows; i++) {
            matrix[i] = calloc(columns, sizeof(double));
            if (matrix[i] == NULL) {
                error = 1;
                break;
            }
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        matrix = NULL;
    }
    return matrix;
}

float ** s21_memory_allocation_float(int rows, int columns) { // float
    int error = 0;
    float ** matrix = calloc(rows, sizeof(float *));
    if (matrix != NULL) {
        for  (int i = 0; i < rows; i++) {
            matrix[i] = calloc(columns, sizeof(float));
            if (matrix[i] == NULL) {
                error = 1;
                break;
            }
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        matrix = NULL;
    }
    return matrix;
}

int ** s21_memory_allocation_int(int rows, int columns) { //  int
    int error = 0;
    int ** matrix = calloc(rows, sizeof(int *));
    if (matrix != NULL) {
        for  (int i = 0; i < rows; i++) {
            matrix[i] = calloc(columns, sizeof(int));
            if (matrix[i] == NULL) {
                error = 1;
                break;
            }
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        matrix = NULL;
    }
    return matrix;
}

int s21_matrix_type(matrix_t A) {
    int res = CORRECT_MATRIX;
    int diagonal = -1;
    int pereferia = 0;
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            if (i != j && A.matrix[i][j] != 0) {
                pereferia = -1;
                break;
            }
        }
    }
    if (A.columns == A.rows && pereferia == 0) {
        diagonal = A.matrix[0][0];
        if (diagonal == 0 || diagonal == 1) {
            for (int i = 0; i < A.columns; i++) {
                if (A.matrix[i][i] != diagonal) {
                    diagonal = -1;
                    break;
                }
            }
        }
    }
    if (diagonal == 0) {
        res = ZERO_MATRIX;
    } else if (diagonal == 1) {
        res = IDENTITY_MATRIX;
    }
    return res;
}

matrix_t s21_minor(matrix_t * A, int i_idx, int j_idx) {
    matrix_t minor;

    if (s21_correct_check(A) == 1 && A->rows == A->columns) {
        minor = s21_create_matrix(A->rows - 1, A->columns - 1);
        if (minor.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0, i_m = 0; i < A->rows; i++) {
                if (i != i_idx) {
                    for (int j = 0, j_m = 0; j < A->columns; j++) {
                        if (j != j_idx) {
                            minor.matrix[i_m][j_m] = A->matrix[i][j];
                            j_m++;
                        }
                    }
                    i_m++;
                }
            }
            s21_init_matrix(&minor, A->columns - 1, A->rows - 1, s21_matrix_type(minor));
        } else {
            s21_init_matrix(&minor, 0, 0, INCORRECT_MATRIX);
        }
    } else {
        s21_init_matrix(&minor, 0, 0, INCORRECT_MATRIX);
    }

    return minor;
}

void s21_rand_matrix(matrix_t *A) { //  double
    srand(time(NULL));
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->matrix[i][j] = (((double)rand() / 10000000))*RAND_MAX;;
        }
    }
}

void s21_rand_matrix_float(matrix_t_f *A) { //  float
    srand(time(NULL));
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->matrix[i][j] = (((float)rand() / 10000000))*RAND_MAX;;
        }
    }
}

void s21_rand_matrix_int(matrix_t_i *A) { //  int
    srand(time(NULL));
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->matrix[i][j] = (((int)rand() / 10000000))*RAND_MAX;;
        }
    }
}
