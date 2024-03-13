#include "my_test.h"

START_TEST(hello_world) {
  const char str[] = "Hello world";
  ck_assert_ptr_eq(strchr(str, 'l'), my_strchr(str, 'l'));
}
END_TEST

START_TEST(end_str_nonempty) {
  const char str[] = "Hello world";
  ck_assert_ptr_eq(strchr(str, '\0'), my_strchr(str, '\0'));
}
END_TEST

START_TEST(empty_string) {
  const char str[] = "";
  ck_assert_ptr_eq(strchr(str, '\0'), my_strchr(str, '\0'));
}
END_TEST

START_TEST(symb_after_end_str) {
  const char str[] = "Hello\0world";
  ck_assert_ptr_eq(strchr(str, 'w'), my_strchr(str, 'w'));
}
END_TEST

START_TEST(num) {
  const char str[] = "123456789";
  ck_assert_ptr_eq(strchr(str, '9'), my_strchr(str, '9'));
}
END_TEST

START_TEST(num_chars_string) {
  const char str[] = "123456789abcdefghijklmnopqrstuvwxyz";
  ck_assert_ptr_eq(strchr(str, 'z'), my_strchr(str, 'z'));
}
END_TEST

START_TEST(end_symb) {
  const char str[] = "\0";
  ck_assert_ptr_eq(strchr(str, '\0'), my_strchr(str, '\0'));
}
END_TEST

START_TEST(spaces) {
  const char str[] = "        ";
  ck_assert_ptr_eq(strchr(str, ' '), my_strchr(str, ' '));
}
END_TEST

START_TEST(tabs) {
  const char str[] = "11	11";
  ck_assert_ptr_eq(strchr(str, '\t'), my_strchr(str, '\t'));
}
END_TEST

START_TEST(null_test) {
  const char str[] = "ABCDE";
  ck_assert_ptr_eq(strchr(str, 'F'), my_strchr(str, 'F'));
}
END_TEST

Suite* suite_strchr() {
  Suite* suite = suite_create("suite_strchr");
  TCase* tcase = tcase_create("tcase_strchr");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, tabs);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, null_test);
  tcase_add_test(tcase, hello_world);
  tcase_add_test(tcase, empty_string);
  tcase_add_test(tcase, num_chars_string);
  tcase_add_test(tcase, end_str_nonempty);
  tcase_add_test(tcase, symb_after_end_str);

  suite_add_tcase(suite, tcase);

  return suite;
}
