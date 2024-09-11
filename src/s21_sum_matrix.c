
#include "s21_matrix.h"

int s21_correct_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;
  if (A == NULL || B == NULL || result == NULL) {
    error_code = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error_code = CALC_ERROR;
  }
  return error_code;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = s21_correct_matrix(A, B, result);
  if (!error_code) {
    error_code = s21_create_matrix(A->rows, A->columns, result);
    if (error_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return error_code;
}