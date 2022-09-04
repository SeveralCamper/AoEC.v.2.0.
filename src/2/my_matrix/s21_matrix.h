#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define EPS 1e-7

#define SUCCESS 1
#define FAILURE 0

typedef enum {
    CORRECT_MATRIX = 0,
    INCORRECT_MATRIX = 1,
    IDENTITY_MATRIX = 2,
    ZERO_MATRIX = 3
} matrix_type_t;


typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
    matrix_type_t matrix_type;
} matrix_t;

double s21_determinant(matrix_t *A);
double ** s21_memory_allocation(int rows, int columns);

void s21_rand_matrix(matrix_t *A);
void s21_print_matrix(matrix_t A);
void s21_remove_matrix(matrix_t *A);
void s21_fill_matrix(matrix_t *A, double iterator);
void s21_init_matrix(matrix_t * A, int colums, int rows, int type);

int isinf_isnan_check(double x);
int s21_matrix_type(matrix_t A);
int s21_correct_check(matrix_t * A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

matrix_t s21_transpose(matrix_t *A);
matrix_t s21_inverse_matrix(matrix_t *A);
matrix_t s21_calc_complements(matrix_t *A);
matrix_t s21_create_matrix(int rows, int columns);
matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_mult_number(matrix_t *A, double number);
matrix_t s21_minor(matrix_t * A, int i_idx, int j_idx);
matrix_t s21_arifmetic_matrix(matrix_t *A, matrix_t *B, int type);

#endif  // SRC_S21_MATRIX_H_
