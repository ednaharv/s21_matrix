#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK;
  if (A == NULL || B == NULL || result == NULL) {
    error_code = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    error_code = CALC_ERROR;
  } else {
    error_code = s21_create_matrix(A->rows, B->columns, result);
    if (error_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return error_code;
}