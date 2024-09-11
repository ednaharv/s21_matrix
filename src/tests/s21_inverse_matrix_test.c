#include "s21_test.h"

START_TEST(test_inverse_matrix_1) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[1][0] = -3.0;
  A.matrix[1][1] = -4.0;

  C.matrix[0][0] = 2;
  C.matrix[0][1] = -1;
  C.matrix[1][0] = -1.5;
  C.matrix[1][1] = 0.5;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_inverse_matrix_2) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;

  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = 0.0;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 1.0;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_inverse_matrix_3) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 0.5;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 2.0;

  C.matrix[0][0] = 0.66666667;
  C.matrix[0][1] = -0.16666667;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 0.5;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_inverse_matrix_4) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 4.0;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, CALC_ERROR);
  s21_remove_matrix(&A);
}

START_TEST(test_inverse_matrix_5) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  int error_code = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}

START_TEST(test_inverse_matrix_6) {
  matrix_t A, C, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 0.0;

  C.matrix[0][0] = -24.0;
  C.matrix[0][1] = 18.0;
  C.matrix[0][2] = 5.0;
  C.matrix[1][0] = 20;
  C.matrix[1][1] = -15;
  C.matrix[1][2] = -4;
  C.matrix[2][0] = -5.0;
  C.matrix[2][1] = 4;
  C.matrix[2][2] = 1.0;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_inverse_matrix_7) {
  matrix_t A, result;
  s21_create_matrix(3, 2, &A);

  A.matrix[0][0] = 100;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = -12;
  A.matrix[1][1] = 1;
  A.matrix[2][0] = 6;

  int error_code = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(error_code, CALC_ERROR);

  s21_remove_matrix(&A);
}

START_TEST(test_inverse_matrix_8) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 1000.0;
  A.matrix[0][1] = 2000.0;
  A.matrix[1][0] = 3000.0;
  A.matrix[1][1] = 4000.0;

  C.matrix[0][0] = -0.002;
  C.matrix[0][1] = 0.001;
  C.matrix[1][0] = 0.0015;
  C.matrix[1][1] = -0.0005;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_inverse_matrix_9) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 100;
  A.matrix[0][1] = 300;
  A.matrix[1][0] = 200;
  A.matrix[1][1] = 400;

  C.matrix[0][0] = -0.02;
  C.matrix[0][1] = 0.015;
  C.matrix[1][0] = 0.01;
  C.matrix[1][1] = -0.005;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_inverse_matrix_10) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = -1;
  A.matrix[1][0] = -2;
  A.matrix[1][1] = -3;

  C.matrix[0][0] = 1.5;
  C.matrix[0][1] = -0.5;
  C.matrix[1][0] = -1;
  C.matrix[1][1] = 0;

  int error_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

Suite *s21_inverse_matrix_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_inverse_matrix_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_inverse_matrix_1);
  tcase_add_test(core, test_inverse_matrix_2);
  tcase_add_test(core, test_inverse_matrix_3);
  tcase_add_test(core, test_inverse_matrix_4);
  tcase_add_test(core, test_inverse_matrix_5);
  tcase_add_test(core, test_inverse_matrix_6);
  tcase_add_test(core, test_inverse_matrix_7);
  tcase_add_test(core, test_inverse_matrix_8);
  tcase_add_test(core, test_inverse_matrix_9);
  tcase_add_test(core, test_inverse_matrix_10);

  suite_add_tcase(suite, core);

  return (suite);
}
