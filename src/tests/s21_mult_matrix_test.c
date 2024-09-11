#include "s21_test.h"

START_TEST(test_mult_matrix_1) {
  matrix_t A, B, result, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;

  C.matrix[0][0] = 19;
  C.matrix[0][1] = 22;
  C.matrix[1][0] = 43;
  C.matrix[1][1] = 50;

  int error_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_2) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);

  int error_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_mult_matrix_3) {
  matrix_t A, B, result, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;

  C.matrix[0][0] = 0;
  C.matrix[0][1] = 0;
  C.matrix[1][0] = 0;
  C.matrix[1][1] = 0;

  int error_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_4) {
  matrix_t A, B, result, expected;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(3, 1, &expected);

  A.matrix[0][0] = -1.5;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = -3.0;

  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = -5.5;
  A.matrix[1][2] = 6.0;

  A.matrix[2][0] = -7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = -9.5;

  B.matrix[0][0] = -1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[2][0] = -3.0;

  expected.matrix[0][0] = (-1.5 * -1.0) + (2.0 * 2.0) + (-3.0 * -3.0);
  expected.matrix[1][0] = (4.0 * -1.0) + (-5.5 * 2.0) + (6.0 * -3.0);
  expected.matrix[2][0] = (-7.0 * -1.0) + (8.0 * 2.0) + (-9.5 * -3.0);

  int error_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_5) {
  matrix_t A, B;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;

  int error_code = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_mult_matrix_6) {
  matrix_t A, B, result, expected;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &expected);

  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = -2.0;
  A.matrix[1][0] = 3.5;
  A.matrix[1][1] = 4.5;

  B.matrix[0][0] = -1.5;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = -4.0;

  expected.matrix[0][0] = (1.5 * -1.5) + (-2.0 * 3.0);
  expected.matrix[0][1] = (1.5 * 2.0) + (-2.0 * -4.0);
  expected.matrix[1][0] = (3.5 * -1.5) + (4.5 * 3.0);
  expected.matrix[1][1] = (3.5 * 2.0) + (4.5 * -4.0);

  int error_code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_7) {
  matrix_t A, B, result, expected;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  B.matrix[0][0] = 9.0;
  B.matrix[0][1] = 8.0;
  B.matrix[0][2] = 7.0;
  B.matrix[1][0] = 6.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 4.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 2.0;
  B.matrix[2][2] = 1.0;

  expected.matrix[0][0] = (1.0 * 9.0) + (2.0 * 6.0) + (3.0 * 3.0);
  expected.matrix[0][1] = (1.0 * 8.0) + (2.0 * 5.0) + (3.0 * 2.0);
  expected.matrix[0][2] = (1.0 * 7.0) + (2.0 * 4.0) + (3.0 * 1.0);
  expected.matrix[1][0] = (4.0 * 9.0) + (5.0 * 6.0) + (6.0 * 3.0);
  expected.matrix[1][1] = (4.0 * 8.0) + (5.0 * 5.0) + (6.0 * 2.0);
  expected.matrix[1][2] = (4.0 * 7.0) + (5.0 * 4.0) + (6.0 * 1.0);
  expected.matrix[2][0] = (7.0 * 9.0) + (8.0 * 6.0) + (9.0 * 3.0);
  expected.matrix[2][1] = (7.0 * 8.0) + (8.0 * 5.0) + (9.0 * 2.0);
  expected.matrix[2][2] = (7.0 * 7.0) + (8.0 * 4.0) + (9.0 * 1.0);

  int error_code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(error_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_8) {
  matrix_t A, B, result, expected;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);

  A.matrix[0][0] = -1.1;
  A.matrix[0][1] = -2.2;
  A.matrix[0][2] = -3.3;
  A.matrix[1][0] = -4.4;
  A.matrix[1][1] = -5.5;
  A.matrix[1][2] = -6.6;
  A.matrix[2][0] = -7.7;
  A.matrix[2][1] = -8.8;
  A.matrix[2][2] = -9.9;

  B.matrix[0][0] = -9.9;
  B.matrix[0][1] = -8.8;
  B.matrix[0][2] = -7.7;
  B.matrix[1][0] = -6.6;
  B.matrix[1][1] = -5.5;
  B.matrix[1][2] = -4.4;
  B.matrix[2][0] = -3.3;
  B.matrix[2][1] = -2.2;
  B.matrix[2][2] = -1.1;

  expected.matrix[0][0] = (-1.1 * -9.9) + (-2.2 * -6.6) + (-3.3 * -3.3);
  expected.matrix[0][1] = (-1.1 * -8.8) + (-2.2 * -5.5) + (-3.3 * -2.2);
  expected.matrix[0][2] = (-1.1 * -7.7) + (-2.2 * -4.4) + (-3.3 * -1.1);
  expected.matrix[1][0] = (-4.4 * -9.9) + (-5.5 * -6.6) + (-6.6 * -3.3);
  expected.matrix[1][1] = (-4.4 * -8.8) + (-5.5 * -5.5) + (-6.6 * -2.2);
  expected.matrix[1][2] = (-4.4 * -7.7) + (-5.5 * -4.4) + (-6.6 * -1.1);
  expected.matrix[2][0] = (-7.7 * -9.9) + (-8.8 * -6.6) + (-9.9 * -3.3);
  expected.matrix[2][1] = (-7.7 * -8.8) + (-8.8 * -5.5) + (-9.9 * -2.2);
  expected.matrix[2][2] = (-7.7 * -7.7) + (-8.8 * -4.4) + (-9.9 * -1.1);

  int error_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_9) {
  matrix_t A, B, result, expected;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 1.0;
  A.matrix[0][2] = 2.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = -1.0;
  A.matrix[2][1] = 0.0;
  A.matrix[2][2] = 4.0;

  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 0.0;
  B.matrix[0][2] = -3.0;
  B.matrix[1][0] = 0.0;
  B.matrix[1][1] = 6.0;
  B.matrix[1][2] = 0.0;
  B.matrix[2][0] = 7.0;
  B.matrix[2][1] = 0.0;
  B.matrix[2][2] = -2.0;

  expected.matrix[0][0] = (0.0 * 5.0) + (1.0 * 0.0) + (2.0 * 7.0);
  expected.matrix[0][1] = (0.0 * 0.0) + (1.0 * 6.0) + (2.0 * 0.0);
  expected.matrix[0][2] = (0.0 * -3.0) + (1.0 * 0.0) + (2.0 * -2.0);
  expected.matrix[1][0] = (0.0 * 5.0) + (3.0 * 0.0) + (0.0 * 7.0);
  expected.matrix[1][1] = (0.0 * 0.0) + (3.0 * 6.0) + (0.0 * 0.0);
  expected.matrix[1][2] = (0.0 * -3.0) + (3.0 * 0.0) + (0.0 * -2.0);
  expected.matrix[2][0] = (-1.0 * 5.0) + (0.0 * 0.0) + (4.0 * 7.0);
  expected.matrix[2][1] = (-1.0 * 0.0) + (0.0 * 6.0) + (4.0 * 0.0);
  expected.matrix[2][2] = (-1.0 * -3.0) + (0.0 * 0.0) + (4.0 * -2.0);

  int error_code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_10) {
  matrix_t A, B, result, expected;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &expected);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -2.5;
  A.matrix[0][2] = 3.5;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.5;
  A.matrix[1][2] = -6.5;
  A.matrix[2][0] = -7.0;
  A.matrix[2][1] = 8.5;
  A.matrix[2][2] = 9.0;

  B.matrix[0][0] = 1.5;
  B.matrix[0][1] = -2.0;
  B.matrix[0][2] = 3.0;
  B.matrix[1][0] = -4.0;
  B.matrix[1][1] = 5.5;
  B.matrix[1][2] = -6.0;
  B.matrix[2][0] = 7.0;
  B.matrix[2][1] = -8.0;
  B.matrix[2][2] = 9.0;

  expected.matrix[0][0] = (1.0 * 1.5) + (-2.5 * -4.0) + (3.5 * 7.0);
  expected.matrix[0][1] = (1.0 * -2.0) + (-2.5 * 5.5) + (3.5 * -8.0);
  expected.matrix[0][2] = (1.0 * 3.0) + (-2.5 * -6.0) + (3.5 * 9.0);
  expected.matrix[1][0] = (4.0 * 1.5) + (5.5 * -4.0) + (-6.5 * 7.0);
  expected.matrix[1][1] = (4.0 * -2.0) + (5.5 * 5.5) + (-6.5 * -8.0);
  expected.matrix[1][2] = (4.0 * 3.0) + (5.5 * -6.0) + (-6.5 * 9.0);
  expected.matrix[2][0] = (-7.0 * 1.5) + (8.5 * -4.0) + (9.0 * 7.0);
  expected.matrix[2][1] = (-7.0 * -2.0) + (8.5 * 5.5) + (9.0 * -8.0);
  expected.matrix[2][2] = (-7.0 * 3.0) + (8.5 * -6.0) + (9.0 * 9.0);

  int error_code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

Suite *s21_mult_matrix_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_mult_matrix_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_mult_matrix_1);
  tcase_add_test(core, test_mult_matrix_2);
  tcase_add_test(core, test_mult_matrix_3);
  tcase_add_test(core, test_mult_matrix_4);
  tcase_add_test(core, test_mult_matrix_5);
  tcase_add_test(core, test_mult_matrix_6);
  tcase_add_test(core, test_mult_matrix_7);
  tcase_add_test(core, test_mult_matrix_8);
  tcase_add_test(core, test_mult_matrix_9);
  tcase_add_test(core, test_mult_matrix_10);

  suite_add_tcase(suite, core);

  return (suite);
}