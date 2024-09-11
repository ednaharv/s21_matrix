#include "s21_matrix.h"

int array_of_pointers_to_arrays(int rows, int columns, matrix_t *result) {
  int error_code = OK;
  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (result->matrix == NULL)
    error_code = CALC_ERROR;
  else {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
      if (result->matrix[i] == NULL) error_code = CALC_ERROR;
    }
  }
  return error_code;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = OK;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    error_code = INCORRECT_MATRIX;
  } else if (array_of_pointers_to_arrays(rows, columns, result)) {
    s21_remove_matrix(result);
    error_code = CALC_ERROR;
  } else {
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
  }
  return error_code;
}
