#ifndef S21_TEST_H
#define S21_TEST_H
#include <check.h>

#include "../s21_matrix.h"

Suite *s21_create_test(void);
Suite *s21_eq_test(void);
Suite *s21_sum_test(void);
Suite *s21_sub_test(void);
Suite *s21_mult_num_test(void);
Suite *s21_mult_matrix_test(void);
Suite *s21_transpose_test(void);
Suite *s21_determinant_test(void);
Suite *s21_calc_complements_test(void);
Suite *s21_inverse_matrix_test(void);

#endif
