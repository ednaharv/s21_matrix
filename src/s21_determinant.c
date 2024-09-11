#include "s21_matrix.h"

int create_minor_matrix(matrix_t *A, matrix_t *minor, int row_to_exclude,
                        int col_to_exclude) {
  int error_code = OK;
  if (A->rows <= 1 || A->columns <= 1) {
    error_code = CALC_ERROR;
  } else {
    error_code = s21_create_matrix(A->rows - 1, A->columns - 1, minor);
    if (error_code == OK) {
      for (int i = 0, minor_i = 0; i < A->rows; i++) {
        if (i != row_to_exclude) {
          for (int j = 0, minor_j = 0; j < A->columns; j++) {
            if (j != col_to_exclude) {
              minor->matrix[minor_i][minor_j] = A->matrix[i][j];
              minor_j++;
            }
          }
          minor_i++;
        }
      }
    }
  }
  return error_code;
}

double calculate_determinant(matrix_t *A, int n) {
  double det = 0.0;

  if (n == 1) {
    det = A->matrix[0][0];
  } else if (n == 2) {
    det =
        (A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0]);
  } else {
    matrix_t minor;
    for (int k = 0; k < n; k++) {
      if (create_minor_matrix(A, &minor, 0, k) == OK) {
        det += (k % 2 == 0 ? 1 : -1) * A->matrix[0][k] *
               calculate_determinant(&minor, n - 1);
        s21_remove_matrix(&minor);
      }
    }
  }

  return det;
}

int s21_determinant(matrix_t *A, double *result) {
  int error_code = OK;
  if (A == NULL || result == NULL) {
    error_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error_code = CALC_ERROR;
  } else {
    *result = calculate_determinant(A, A->rows);
  }
  return error_code;
}