#include "s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error_code = 1;

  if (A == NULL || B == NULL) {
    error_code = 0;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error_code = 0;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.0000001) {
          error_code = 0;
        }
      }
    }
  }

  return error_code;
}