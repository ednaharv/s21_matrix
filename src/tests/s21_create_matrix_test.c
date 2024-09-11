#include "s21_test.h"

START_TEST(test_create_1) {
  matrix_t my_matrix;
  int rows = 2;
  int columns = 2;
  int expected_error_code = 0;
  int error_code = s21_create_matrix(rows, columns, &my_matrix);
  ck_assert_int_eq(error_code, expected_error_code);
  s21_remove_matrix(&my_matrix);
}

START_TEST(test_create_2) {
  matrix_t my_matrix;
  int rows = 0;
  int columns = 0;
  int expected_error_code = 1;
  int error_code = s21_create_matrix(rows, columns, &my_matrix);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_create_3) {
  matrix_t my_matrix;
  int rows = 5;
  int columns = 10;
  int expected_error_code = 0;
  int error_code = s21_create_matrix(rows, columns, &my_matrix);
  ck_assert_int_eq(error_code, expected_error_code);
  s21_remove_matrix(&my_matrix);
}

START_TEST(test_create_4) {
  int rows = 5;
  int columns = 10;
  int expected_error_code = 1;
  int error_code = s21_create_matrix(rows, columns, NULL);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_create_5) {
  matrix_t my_matrix;
  int rows = 5;
  int columns = 0;
  int expected_error_code = 1;
  int error_code = s21_create_matrix(rows, columns, &my_matrix);
  ck_assert_int_eq(error_code, expected_error_code);
}

Suite *s21_create_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_create_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_create_1);
  tcase_add_test(core, test_create_2);
  tcase_add_test(core, test_create_3);
  tcase_add_test(core, test_create_4);
  tcase_add_test(core, test_create_5);

  suite_add_tcase(suite, core);

  return (suite);
}