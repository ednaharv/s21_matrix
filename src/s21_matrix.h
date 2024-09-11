#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
int array_of_pointers_to_arrays(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_correct_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int create_minor_matrix(matrix_t *A, matrix_t *minor, int row_to_exclude,
                        int col_to_exclude);
double calculate_determinant(matrix_t *A, int n);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_check(matrix_t *A, matrix_t *result);
int s21_check_determinant(matrix_t *A, double *det);
int s21_create_inverse(matrix_t *A, matrix_t *result, double det);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif