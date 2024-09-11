#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = s21_correct_matrix(A, B, result);
  if (!error_code) {
    error_code = s21_create_matrix(A->rows, A->columns, result);
    if (error_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return error_code;
}