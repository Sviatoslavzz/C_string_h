#include "my_test.h"

START_TEST(hello_world) {
  const char str[] = "Hello world";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(empty_string) {
  const char str[] = "";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(end_symb_inside_string) {
  const char str[] = "Hello\0world";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(num) {
  const char str[] = "123456789";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(num_chars_string) {
  const char str[] = "123456789abcdefghijklmnopqrstuvwxyz";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(end_symb) {
  const char str[] = "\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(spaces) {
  const char str[] = "        ";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

Suite* suite_strlen() {
  Suite* suite = suite_create("suite_strlen");
  TCase* tcase = tcase_create("tcase_strlen");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, hello_world);
  tcase_add_test(tcase, empty_string);
  tcase_add_test(tcase, num_chars_string);
  tcase_add_test(tcase, end_symb_inside_string);
  suite_add_tcase(suite, tcase);

  return suite;
}
