#include "my_test.h"

START_TEST(hello_world) {
  const char str[] = "Hello world";
  ck_assert_ptr_eq(strrchr(str, 'l'), my_strrchr(str, 'l'));
}
END_TEST

START_TEST(end_str_nonempty) {
  const char str[] = "Hello world";
  ck_assert_ptr_eq(strrchr(str, '\0'), my_strrchr(str, '\0'));
}
END_TEST

START_TEST(empty_string) {
  const char str[] = "";
  ck_assert_ptr_eq(strrchr(str, '\0'), my_strrchr(str, '\0'));
}
END_TEST

START_TEST(symb_after_end_str) {
  const char str[] = "Hello\0world";
  ck_assert_ptr_eq(strrchr(str, 'w'), my_strrchr(str, 'w'));
}
END_TEST

START_TEST(symb_after_end_str_2) {
  const char str[] = "Hello\0world";
  ck_assert_ptr_eq(strrchr(str, 'H'), my_strrchr(str, 'H'));
}
END_TEST

START_TEST(num) {
  const char str[] = "123456789";
  ck_assert_ptr_eq(strrchr(str, '1'), my_strrchr(str, '1'));
}
END_TEST

START_TEST(num_chars_string) {
  const char str[] = "123456789abcdefghijklmnopqrstuvwxyz";
  ck_assert_ptr_eq(strrchr(str, 'a'), my_strrchr(str, 'a'));
}
END_TEST

START_TEST(end_symb) {
  const char str[] = "\0";
  ck_assert_ptr_eq(strrchr(str, '\0'), my_strrchr(str, '\0'));
}
END_TEST

START_TEST(spaces) {
  const char str[] = "        ";
  ck_assert_ptr_eq(strrchr(str, ' '), my_strrchr(str, ' '));
}
END_TEST

START_TEST(tabs) {
  const char str[] = "      ";
  ck_assert_ptr_eq(strrchr(str, '\t'), my_strrchr(str, '\t'));
}
END_TEST

START_TEST(null_test) {
  const char str[] = "ABCDE";
  ck_assert_ptr_eq(strrchr(str, 'F'), my_strrchr(str, 'F'));
}
END_TEST

Suite* suite_strrchr() {
  Suite* suite = suite_create("suite_strrchr");
  TCase* tcase = tcase_create("tcase_strrchr");

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
  tcase_add_test(tcase, symb_after_end_str_2);

  suite_add_tcase(suite, tcase);

  return suite;
}
