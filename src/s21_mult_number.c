#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = OK;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0 ||
      result == NULL) {
    error_code = INCORRECT_MATRIX;
  } else {
    int error_code = s21_create_matrix(A->rows, A->columns, result);
    if (error_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return error_code;
}