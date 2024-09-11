#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (A == NULL || result == NULL || A->rows != A->columns) {
    error_code = INCORRECT_MATRIX;
  } else {
    error_code = s21_create_matrix(A->rows, A->columns, result);
    if (error_code == OK) {
      matrix_t minor;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          error_code = create_minor_matrix(A, &minor, i, j);
          if (error_code == OK) {
            double det_minor = calculate_determinant(&minor, A->rows - 1);
            result->matrix[i][j] = ((i + j) % 2 == 0 ? det_minor : -det_minor);
            s21_remove_matrix(&minor);
          }
        }
      }
    }
  }
  return error_code;
}