
#include "s21_test.h"

START_TEST(test_calc_complements_1) {
  matrix_t A, C, result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &C);

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

  C.matrix[0][0] = 0;
  C.matrix[0][1] = 0;
  C.matrix[0][2] = 0;
  C.matrix[0][3] = 0;
  C.matrix[1][0] = 0;
  C.matrix[1][1] = 0;
  C.matrix[1][2] = 0;
  C.matrix[1][3] = 0;
  C.matrix[2][0] = 0;
  C.matrix[2][1] = 0;
  C.matrix[2][2] = 0;
  C.matrix[2][3] = 0;
  C.matrix[3][0] = 0;
  C.matrix[3][1] = 0;
  C.matrix[3][2] = 0;
  C.matrix[3][3] = 0;

  int error_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_2) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  C.matrix[0][0] = 4.0;
  C.matrix[0][1] = -3.0;
  C.matrix[1][0] = -2.0;
  C.matrix[1][1] = 1.0;

  int error_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_3) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  int error_code = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}

START_TEST(test_calc_complements_4) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 5.0;

  int error_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(error_code, CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_5) {
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
  C.matrix[0][1] = 20;
  C.matrix[0][2] = -5.0;
  C.matrix[1][0] = 18;
  C.matrix[1][1] = -15.0;
  C.matrix[1][2] = 4.0;
  C.matrix[2][0] = 5.0;
  C.matrix[2][1] = -4.0;
  C.matrix[2][2] = 1.0;

  int error_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_6) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.0;

  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 0.0;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 0.0;

  int error_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_7) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[1][0] = -3.0;
  A.matrix[1][1] = -4.0;

  C.matrix[0][0] = -4.0;
  C.matrix[0][1] = 3;
  C.matrix[1][0] = 2;
  C.matrix[1][1] = -1.0;

  int error_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_8) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 2.5;
  A.matrix[1][0] = 3.5;
  A.matrix[1][1] = 4.5;

  C.matrix[0][0] = 4.5;
  C.matrix[0][1] = -3.5;
  C.matrix[1][0] = -2.5;
  C.matrix[1][1] = 1.5;

  int error_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_9) {
  matrix_t A, C, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);

  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.5;
  A.matrix[0][2] = -3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = -5.5;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = -7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = -9.5;

  C.matrix[0][0] = 4.25;
  C.matrix[0][1] = -4;
  C.matrix[0][2] = -6.5;
  C.matrix[1][0] = -0.25;
  C.matrix[1][1] = -11.5;
  C.matrix[1][2] = -9.5;
  C.matrix[2][0] = -1.5;
  C.matrix[2][1] = -6;
  C.matrix[2][2] = -4.5;

  int error_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
START_TEST(test_calc_complements_10) {
  matrix_t A, C, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 100;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = -12;
  A.matrix[1][1] = 1;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = 12;
  C.matrix[1][0] = -3;
  C.matrix[1][1] = 100;

  int error_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

Suite *s21_calc_complements_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_calc_complements_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_calc_complements_1);
  tcase_add_test(core, test_calc_complements_2);
  tcase_add_test(core, test_calc_complements_3);
  tcase_add_test(core, test_calc_complements_4);
  tcase_add_test(core, test_calc_complements_5);
  tcase_add_test(core, test_calc_complements_6);
  tcase_add_test(core, test_calc_complements_7);
  tcase_add_test(core, test_calc_complements_8);
  tcase_add_test(core, test_calc_complements_9);
  tcase_add_test(core, test_calc_complements_10);

  suite_add_tcase(suite, core);

  return (suite);
}