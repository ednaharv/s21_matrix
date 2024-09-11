#include "s21_matrix.h"

int s21_inverse_check(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0 ||
      A->matrix == NULL) {
    error_code = INCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    error_code = CALC_ERROR;
  }
  return error_code;
}

int s21_check_determinant(matrix_t *A, double *det) {
  int error_code = s21_determinant(A, det);
  return (error_code == OK && *det != 0) ? OK : CALC_ERROR;
}

int s21_create_inverse(matrix_t *A, matrix_t *result, double det) {
  matrix_t complements;
  int error_code = OK;

  error_code = s21_calc_complements(A, &complements);
  if (error_code == OK) {
    error_code = s21_create_matrix(A->rows, A->columns, result);
    if (error_code == OK) {
      for (int i = 0; i < complements.rows; i++) {
        for (int j = 0; j < complements.columns; j++) {
          result->matrix[i][j] = complements.matrix[j][i] / det;
        }
      }
    }

    s21_remove_matrix(&complements);
  }
  return error_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  double det = 0.0;
  error_code = s21_inverse_check(A, result);
  if (error_code == OK) {
    error_code = s21_check_determinant(A, &det);
    if (error_code == OK) {
      error_code = s21_create_inverse(A, result, det);
    } else {
      error_code = CALC_ERROR;
    }
  }

  return error_code;
}