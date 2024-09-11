#include "s21_test.h"

START_TEST(test_determinant_1) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 4.0;
  A.matrix[1][0] = 5.0;
  A.matrix[1][1] = 6.0;
  A.matrix[1][2] = 7.0;
  A.matrix[1][3] = 8.0;
  A.matrix[2][0] = 9.0;
  A.matrix[2][1] = 10.0;
  A.matrix[2][2] = 11.0;
  A.matrix[2][3] = 12.0;
  A.matrix[3][0] = 13.0;
  A.matrix[3][1] = 14.0;
  A.matrix[3][2] = 15.0;
  A.matrix[3][3] = 16.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_2) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[1][3] = 5.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 4.0;
  A.matrix[2][2] = 5.0;
  A.matrix[2][3] = 6.0;
  A.matrix[3][0] = 4.0;
  A.matrix[3][1] = 5.0;
  A.matrix[3][2] = 6.0;
  A.matrix[3][3] = 7.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_3) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[0][2] = 0.0;
  A.matrix[0][3] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 0.0;
  A.matrix[2][1] = 0.0;
  A.matrix[2][2] = 1.0;
  A.matrix[2][3] = 0.0;
  A.matrix[3][0] = 0.0;
  A.matrix[3][1] = 0.0;
  A.matrix[3][2] = 0.0;
  A.matrix[3][3] = 1.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 1.0);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_4) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = -3.0;
  A.matrix[0][2] = 1.0;
  A.matrix[0][3] = 5.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 4.0;
  A.matrix[1][3] = 2.0;
  A.matrix[2][0] = 1.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  A.matrix[2][3] = 0.0;
  A.matrix[3][0] = 4.0;
  A.matrix[3][1] = 2.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 39);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_5) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 2.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_6) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 0.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 1);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_7) {
  matrix_t A;
  double result = 0.0000;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 32.1;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 1.0;
  A.matrix[0][3] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[1][3] = 5.0;
  A.matrix[2][0] = 1.0;
  A.matrix[2][1] = 1.0;
  A.matrix[2][2] = 1.564;
  A.matrix[2][3] = 1.0;
  A.matrix[3][0] = 4.0;
  A.matrix[3][1] = 11.7;
  A.matrix[3][2] = 3.0;
  A.matrix[3][3] = 2.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, -1154.8934, 0.0001);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_8) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  ck_assert_int_eq(s21_determinant(&A, &result), CALC_ERROR);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_9) {
  double result;
  ck_assert_int_eq(s21_determinant(NULL, &result), INCORRECT_MATRIX);
}

START_TEST(test_determinant_10) {
  matrix_t A;
  double result;
  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 7.0;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(result, 7.0);
  s21_remove_matrix(&A);
}

Suite *s21_determinant_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_determinant_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_determinant_1);
  tcase_add_test(core, test_determinant_2);
  tcase_add_test(core, test_determinant_3);
  tcase_add_test(core, test_determinant_4);
  tcase_add_test(core, test_determinant_5);
  tcase_add_test(core, test_determinant_6);
  tcase_add_test(core, test_determinant_7);
  tcase_add_test(core, test_determinant_8);
  tcase_add_test(core, test_determinant_9);
  tcase_add_test(core, test_determinant_10);

  suite_add_tcase(suite, core);

  return (suite);
}