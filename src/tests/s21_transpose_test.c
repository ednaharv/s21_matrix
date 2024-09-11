#include "s21_test.h"

START_TEST(test_transpose_1) {
  matrix_t A, result;

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  matrix_t expected;
  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 1.0;
  expected.matrix[0][1] = 4.0;
  expected.matrix[1][0] = 2.0;
  expected.matrix[1][1] = 5.0;
  expected.matrix[2][0] = 3.0;
  expected.matrix[2][1] = 6.0;

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(test_transpose_2) {
  matrix_t A, result;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  matrix_t expected;
  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1.0;
  expected.matrix[0][1] = 4.0;
  expected.matrix[0][2] = 7.0;
  expected.matrix[1][0] = 2.0;
  expected.matrix[1][1] = 5.0;
  expected.matrix[1][2] = 8.0;
  expected.matrix[2][0] = 3.0;
  expected.matrix[2][1] = 6.0;
  expected.matrix[2][2] = 9.0;

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(test_transpose_3) {
  matrix_t A;

  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int error_code = s21_transpose(&A, NULL);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}

START_TEST(test_transpose_4) {
  matrix_t A, result;

  s21_create_matrix(4, 5, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i * A.columns + j + 1;
    }
  }

  matrix_t expected;
  s21_create_matrix(5, 4, &expected);

  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      expected.matrix[i][j] = (j * expected.rows + i + 1);
    }
  }

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
START_TEST(test_transpose_5) {
  matrix_t A, result;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 3.5;

  matrix_t expected;
  s21_create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 3.5;

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(test_transpose_6) {
  matrix_t A, result;

  s21_create_matrix(5, 2, &A);
  for (int i = 0; i < A.rows; i++) {
    A.matrix[i][0] = i + 1;
    A.matrix[i][1] = (i + 1) * 2;
  }

  matrix_t expected;
  s21_create_matrix(2, 5, &expected);

  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      expected.matrix[i][j] = (j + 1) * (i + 1);
    }
  }

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(test_transpose_7) {
  matrix_t A, result;

  s21_create_matrix(2, 3, &A);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 0.0;
    }
  }

  matrix_t expected;
  s21_create_matrix(3, 2, &expected);

  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      expected.matrix[i][j] = 0.0;
    }
  }

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(test_transpose_8) {
  matrix_t A, result;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[1][0] = -3.0;
  A.matrix[1][1] = -4.0;

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -1.0;
  expected.matrix[0][1] = -3.0;
  expected.matrix[1][0] = -2.0;
  expected.matrix[1][1] = -4.0;

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(test_transpose_9) {
  matrix_t A, intermediate, result;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 6.0;

  s21_transpose(&A, &intermediate);

  matrix_t expected;
  s21_create_matrix(2, 3, &expected);
  expected.matrix[0][0] = 1.0;
  expected.matrix[0][1] = 3.0;
  expected.matrix[0][2] = 5.0;
  expected.matrix[1][0] = 2.0;
  expected.matrix[1][1] = 4.0;
  expected.matrix[1][2] = 6.0;

  ck_assert_int_eq(s21_eq_matrix(&expected, &intermediate), 1);

  int error_code = s21_transpose(&intermediate, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&A, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&intermediate);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(test_transpose_10) {
  matrix_t A, result;

  s21_create_matrix(100, 100, &A);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (double)(i * A.columns + j);
    }
  }

  matrix_t expected;
  s21_create_matrix(100, 100, &expected);

  for (int i = 0; i < expected.rows; i++) {
    for (int j = 0; j < expected.columns; j++) {
      expected.matrix[i][j] = (double)(j * expected.rows + i);
    }
  }

  int error_code = s21_transpose(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

Suite *s21_transpose_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_transpose_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_transpose_1);
  tcase_add_test(core, test_transpose_2);
  tcase_add_test(core, test_transpose_3);
  tcase_add_test(core, test_transpose_4);
  tcase_add_test(core, test_transpose_5);
  tcase_add_test(core, test_transpose_6);
  tcase_add_test(core, test_transpose_7);
  tcase_add_test(core, test_transpose_8);
  tcase_add_test(core, test_transpose_9);
  tcase_add_test(core, test_transpose_10);

  suite_add_tcase(suite, core);

  return (suite);
}