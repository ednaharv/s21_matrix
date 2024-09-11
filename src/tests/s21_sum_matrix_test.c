#include "s21_test.h"

START_TEST(test_sum_1) {
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

  C.matrix[0][0] = 6;
  C.matrix[0][1] = 8;
  C.matrix[1][0] = 10;
  C.matrix[1][1] = 12;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_2) {
  matrix_t A, B, result, C;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = 0;
      B.matrix[i][j] = 0;
      C.matrix[i][j] = 0;
    }
  }

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_3) {
  matrix_t A, B, result, C;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 3;

  B.matrix[0][0] = 2;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 2;

  C.matrix[0][0] = 5;
  C.matrix[0][1] = 5;
  C.matrix[1][0] = 5;
  C.matrix[1][1] = 5;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_4) {
  matrix_t A, B, result, C;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = -1;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = -4;

  B.matrix[0][0] = -5;
  B.matrix[0][1] = -6;
  B.matrix[1][0] = -7;
  B.matrix[1][1] = -8;

  C.matrix[0][0] = -6;
  C.matrix[0][1] = -8;
  C.matrix[1][0] = -10;
  C.matrix[1][1] = -12;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_6) {
  matrix_t A, B, result, C;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 2;
  B.matrix[2][2] = 1;

  C.matrix[0][0] = 10;
  C.matrix[0][1] = 10;
  C.matrix[0][2] = 10;
  C.matrix[1][0] = 10;
  C.matrix[1][1] = 10;
  C.matrix[1][2] = 10;
  C.matrix[2][0] = 10;
  C.matrix[2][1] = 10;
  C.matrix[2][2] = 10;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_5) {
  matrix_t A, B, result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_sum_7) {
  matrix_t A, B;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  // Инициализация матрицы B
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;

  int error_code = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_sum_8) {
  matrix_t A, B, C, result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0000001;
  A.matrix[0][1] = 2.0000002;
  A.matrix[1][0] = 3.0000003;
  A.matrix[1][1] = 4.0000004;

  B.matrix[0][0] = 1.0000001;
  B.matrix[0][1] = 2.0000002;
  B.matrix[1][0] = 3.0000003;
  B.matrix[1][1] = 4.0000004;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 2.0000002;
  C.matrix[0][1] = 4.0000004;
  C.matrix[1][0] = 6.0000006;
  C.matrix[1][1] = 8.0000008;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_9) {
  matrix_t A, B, C, result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.00000011;
  A.matrix[0][1] = 2.00000021;
  A.matrix[1][0] = 3.00000031;
  A.matrix[1][1] = 4.00000041;

  B.matrix[0][0] = 1.00000012;
  B.matrix[0][1] = 2.00000022;
  B.matrix[1][0] = 3.00000032;
  B.matrix[1][1] = 4.00000042;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 2.0000002;
  C.matrix[0][1] = 4.0000004;
  C.matrix[1][0] = 6.0000006;
  C.matrix[1][1] = 8.0000008;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_10) {
  matrix_t A, B, C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = -5;
  B.matrix[0][0] = 5;

  matrix_t result;
  s21_create_matrix(1, 1, &result);

  s21_create_matrix(1, 1, &C);
  C.matrix[0][0] = 0;

  int error_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(error_code, OK);
  ck_assert_double_eq(result.matrix[0][0], C.matrix[0][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&C);
}

Suite *s21_sum_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_sum_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_sum_1);
  tcase_add_test(core, test_sum_2);
  tcase_add_test(core, test_sum_3);
  tcase_add_test(core, test_sum_4);
  tcase_add_test(core, test_sum_5);
  tcase_add_test(core, test_sum_6);
  tcase_add_test(core, test_sum_7);
  tcase_add_test(core, test_sum_8);
  tcase_add_test(core, test_sum_9);
  tcase_add_test(core, test_sum_10);

  suite_add_tcase(suite, core);

  return (suite);
}