#include "s21_test.h"

int main(void) {
  int failed = 0;

  Suite *tests[] = {s21_create_test(),
                    s21_eq_test(),
                    s21_sum_test(),
                    s21_sub_test(),
                    s21_mult_num_test(),
                    s21_mult_matrix_test(),
                    s21_transpose_test(),
                    s21_determinant_test(),
                    s21_calc_complements_test(),
                    s21_inverse_matrix_test()};

  for (int i = 0; i < 10; i++) {
    SRunner *runner = srunner_create(tests[i]);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}