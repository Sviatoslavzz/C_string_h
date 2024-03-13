#include "my_test.h"

START_TEST(strerror_valid_number) {
  int errnum = 1;
  char *result = my_strerror(errnum);
  char *expected = strerror(errnum);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strerror_success_number) {
  int errnum = 0;
  char *result = my_strerror(errnum);
  char *expected = strerror(errnum);
  ck_assert_str_eq(result, expected);
}
END_TEST
START_TEST(strerror_valid_number1) {
  int errnum = 100;
  char *result = my_strerror(errnum);
  char *expected = strerror(errnum);
  ck_assert_str_eq(result, expected);
}
END_TEST

// START_TEST(strerror_unknown) {
//   int errnum = 777;
//   char *result = my_strerror(errnum);
//   char *expected = strerror(errnum);
//   ck_assert_str_eq(result, expected);
// }
// END_TEST

Suite *suite_strerror() {
  Suite *suite = suite_create("suite_strerror");
  TCase *tcase = tcase_create("tcase_strerror");

  tcase_add_test(tcase, strerror_valid_number);
  tcase_add_test(tcase, strerror_success_number);
  tcase_add_test(tcase, strerror_valid_number1);
  // tcase_add_test(tcase, strerror_unknown);

  suite_add_tcase(suite, tcase);

  return suite;
}