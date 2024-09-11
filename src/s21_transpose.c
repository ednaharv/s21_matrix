#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = OK;

  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0 ||
      A->matrix == NULL) {
    error_code = INCORRECT_MATRIX;
  } else {
    error_code = s21_create_matrix(A->columns, A->rows, result);
    if (error_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }

  return error_code;
}