#include "s21_test.h"

START_TEST(test_eq_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(5, 7, &A);
  s21_create_matrix(5, 7, &B);
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 7;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 0;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 7, &A);
  s21_create_matrix(5, 7, &B);
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 0;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_5) {
  matrix_t A;
  s21_create_matrix(4, 7, &A);
  int error_code = s21_eq_matrix(&A, NULL);
  int expected_error_code = 0;
  s21_remove_matrix(&A);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_6) {
  matrix_t B;
  s21_create_matrix(7, 1, &B);
  int error_code = s21_eq_matrix(NULL, &B);
  int expected_error_code = 0;
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_7) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0.12345678;
  A.matrix[0][1] = 0.7;
  A.matrix[1][0] = -14.3;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 0.12345679;
  B.matrix[0][1] = 0.7;
  B.matrix[1][0] = -14.3;
  B.matrix[1][1] = 1;
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_8) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0.12345658;
  A.matrix[0][1] = 0.7;
  A.matrix[1][0] = -14.3;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 0.12345679;
  B.matrix[0][1] = 0.7;
  B.matrix[1][0] = -14.3;
  B.matrix[1][1] = 1;
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 0;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_9) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0.12345679;
  A.matrix[0][1] = 0.7;
  A.matrix[1][0] = -14.3;
  A.matrix[1][1] = -1;
  B.matrix[0][0] = 0.12345679;
  B.matrix[0][1] = 0.7;
  B.matrix[1][0] = -14.3;
  B.matrix[1][1] = 1;
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 0;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_eq_10) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0.0000000123;
  A.matrix[0][1] = 0.0000000123;
  A.matrix[1][0] = 0.0000000123;
  A.matrix[1][1] = 0.0000000123;
  B.matrix[0][0] = 0.0000000456;
  B.matrix[0][1] = 0.0000000456;
  B.matrix[1][0] = 0.0000000456;
  B.matrix[1][1] = 0.0000000456;
  int error_code = s21_eq_matrix(&A, &B);
  int expected_error_code = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(error_code, expected_error_code);
}

Suite *s21_eq_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_eq_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_eq_1);
  tcase_add_test(core, test_eq_2);
  tcase_add_test(core, test_eq_3);
  tcase_add_test(core, test_eq_4);
  tcase_add_test(core, test_eq_5);
  tcase_add_test(core, test_eq_6);
  tcase_add_test(core, test_eq_7);
  tcase_add_test(core, test_eq_8);
  tcase_add_test(core, test_eq_9);
  tcase_add_test(core, test_eq_10);

  suite_add_tcase(suite, core);

  return (suite);
}