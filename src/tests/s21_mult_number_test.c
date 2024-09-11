#include "s21_test.h"

START_TEST(test_mult_num_1) {
  matrix_t A, B, result;
  double number = 1;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_2) {
  matrix_t A, result;
  double number = 0;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 0;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = 0;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_3) {
  matrix_t A, result;
  double number = -2;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -2;
  expected.matrix[0][1] = -4;
  expected.matrix[1][0] = -6;
  expected.matrix[1][1] = -8;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_4) {
  matrix_t A;
  double number = 3;

  s21_create_matrix(2, 5, &A);

  int error_code = s21_mult_number(&A, number, NULL);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}

START_TEST(test_mult_num_5) {
  matrix_t A, result;
  double number = 0.5;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 100;
  A.matrix[0][1] = 200;
  A.matrix[1][0] = 300;
  A.matrix[1][1] = 400;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 50;
  expected.matrix[0][1] = 100;
  expected.matrix[1][0] = 150;
  expected.matrix[1][1] = 200;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_6) {
  matrix_t A, result;
  double number = 2.75;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 8;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 5.5;
  expected.matrix[0][1] = 11;
  expected.matrix[1][0] = 16.5;
  expected.matrix[1][1] = 22;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_7) {
  matrix_t A, result;
  double number = -2.5;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -2.5;
  expected.matrix[0][1] = -5.0;
  expected.matrix[1][0] = -7.5;
  expected.matrix[1][1] = -10.0;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_8) {
  matrix_t A, result;
  double number = 0.03;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 2.4;
  A.matrix[1][0] = 3.6;
  A.matrix[1][1] = 4.8;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);

  expected.matrix[0][0] = 0.045;
  expected.matrix[0][1] = 0.072;
  expected.matrix[1][0] = 0.108;
  expected.matrix[1][1] = 0.144;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_9) {
  matrix_t A, result;
  double number = 0.000000001;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 2.4;
  A.matrix[1][0] = 3.6;
  A.matrix[1][1] = 4.8;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);

  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 0;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = 0;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_num_10) {
  matrix_t A, result;
  double number = -0.000000001;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 2.4;
  A.matrix[1][0] = 3.6;
  A.matrix[1][1] = 4.8;

  int error_code = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(error_code, OK);

  matrix_t expected;
  s21_create_matrix(2, 2, &expected);

  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 0;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = 0;

  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}

Suite *s21_mult_num_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_mult_num_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_mult_num_1);
  tcase_add_test(core, test_mult_num_2);
  tcase_add_test(core, test_mult_num_3);
  tcase_add_test(core, test_mult_num_4);
  tcase_add_test(core, test_mult_num_5);
  tcase_add_test(core, test_mult_num_6);
  tcase_add_test(core, test_mult_num_7);
  tcase_add_test(core, test_mult_num_8);
  tcase_add_test(core, test_mult_num_9);
  tcase_add_test(core, test_mult_num_10);

  suite_add_tcase(suite, core);

  return (suite);
}