#include "my_test.h"

START_TEST(strncmp_same) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  my_size_t number = 5;
  ck_assert_int_eq(my_strncmp(str1, str2, number), strncmp(str1, str2, number));
}
END_TEST

START_TEST(strncmp_min) {
  const char *str1 = "apple";
  const char *str2 = "apricot";
  my_size_t number = 5;

  ck_assert_int_lt(my_strncmp(str1, str2, number), 0);
  ck_assert_int_lt(strncmp(str1, str2, number), 0);
}
END_TEST

START_TEST(strncmp_little_string) {
  const char *str1 = "He";
  const char *str2 = "Hello";
  my_size_t number = 5;

  ck_assert_int_lt(my_strncmp(str1, str2, number), 0);
  ck_assert_int_lt(strncmp(str1, str2, number), 0);
}
END_TEST

START_TEST(strncmp_register_diff) {
  const char *str1 = "Hello";
  const char *str2 = "hello";
  my_size_t number = 5;

  ck_assert_int_lt(my_strncmp(str1, str2, number), 0);
  ck_assert_int_lt(strncmp(str1, str2, number), 0);
}
END_TEST

START_TEST(strncmp_first_str_greater) {
  const char *str1 = "Cello";
  const char *str2 = "Aello";
  my_size_t number = 5;

  ck_assert_int_gt(my_strncmp(str1, str2, number), 0);
  ck_assert_int_gt(strncmp(str1, str2, number), 0);
}
END_TEST

START_TEST(strncmp_all_empty) {
  const char *str1 = "";
  const char *str2 = "";
  my_size_t number = 0;
  ck_assert_int_eq(my_strncmp(str1, str2, number), strncmp(str1, str2, number));
}
END_TEST

START_TEST(strncmp_empty_string) {
  const char *str1 = "";
  const char *str2 = "";
  my_size_t number = 2;
  ck_assert_int_eq(my_strncmp(str1, str2, number), strncmp(str1, str2, number));
}
END_TEST

START_TEST(strncmp_empty_number) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  my_size_t number = 0;
  ck_assert_int_eq(my_strncmp(str1, str2, number), strncmp(str1, str2, number));
}
END_TEST

START_TEST(strncmp_empty_one_string) {
  const char *str1 = "";
  const char *str2 = "Hello";
  my_size_t number = 5;

  ck_assert_int_lt(my_strncmp(str1, str2, number), 0);
  ck_assert_int_lt(strncmp(str1, str2, number), 0);
}
END_TEST

START_TEST(strncmp_spaces) {
  const char *str1 = "   ";
  const char *str2 = "   ";
  my_size_t number = 3;
  ck_assert_int_eq(my_strncmp(str1, str2, number), strncmp(str1, str2, number));
}
END_TEST

Suite *suite_strncmp() {
  Suite *suite = suite_create("suite_strncmp");
  TCase *tcase = tcase_create("tcase_strncmp");

  tcase_add_test(tcase, strncmp_min);
  tcase_add_test(tcase, strncmp_same);
  tcase_add_test(tcase, strncmp_spaces);
  tcase_add_test(tcase, strncmp_all_empty);
  tcase_add_test(tcase, strncmp_empty_string);
  tcase_add_test(tcase, strncmp_empty_number);
  tcase_add_test(tcase, strncmp_little_string);
  tcase_add_test(tcase, strncmp_register_diff);
  tcase_add_test(tcase, strncmp_empty_one_string);
  tcase_add_test(tcase, strncmp_first_str_greater);

  suite_add_tcase(suite, tcase);

  return suite;
}
