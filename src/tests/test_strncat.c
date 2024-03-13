#include "my_test.h"

START_TEST(hello_world) {
  char str1_origin[20] = "Hello";
  char str1_my[20] = "Hello";
  const char str_add[] = "world";
  strncat(str1_origin, str_add, 5);
  my_strncat(str1_my, str_add, 5);
  ck_assert_str_eq(str1_origin, str1_my);
}
END_TEST

START_TEST(empty_string) {
  char str1_origin[20] = "";
  char str1_my[20] = "";
  const char str_add[] = "add to empty";
  strncat(str1_origin, str_add, 12);
  my_strncat(str1_my, str_add, 12);
  ck_assert_str_eq(str1_origin, str1_my);
}
END_TEST

START_TEST(end_symb_inside_string) {
  char str1_origin[20] = "Hello\0world";
  char str1_my[20] = "Hello\0world";
  const char str_add[] = "Verter";
  strncat(str1_origin, str_add, 6);
  my_strncat(str1_my, str_add, 6);
  ck_assert_str_eq(str1_origin, str1_my);
}
END_TEST

START_TEST(num) {
  char str1_origin[20] = "123456789";
  char str1_my[20] = "123456789";
  const char str_add[] = "10";
  strncat(str1_origin, str_add, 2);
  my_strncat(str1_my, str_add, 2);
  ck_assert_str_eq(str1_origin, str1_my);
}
END_TEST

START_TEST(end_symb) {
  char str1_origin[40] = "\0";
  char str1_my[40] = "\0";
  const char str_add[] = "I'm placed after empty string";
  strncat(str1_origin, str_add, 29);
  my_strncat(str1_my, str_add, 29);
  ck_assert_str_eq(str1_origin, str1_my);
}
END_TEST

START_TEST(spaces) {
  char str1_origin[40] = "        ";
  char str1_my[40] = "        ";
  const char str_add[] = "I'm placed after spaces";
  strncat(str1_origin, str_add, 23);
  my_strncat(str1_my, str_add, 23);
  ck_assert_str_eq(str1_origin, str1_my);
}
END_TEST

START_TEST(add_more_bytes_than_append_string) {
  char str1_origin[20] = "123456789";
  char str1_my[20] = "123456789";
  const char str_add[] = "qwrt";
  strncat(str1_origin, str_add, 6);
  my_strncat(str1_my, str_add, 6);
  ck_assert_str_eq(str1_origin, str1_my);
}
END_TEST

Suite* suite_strncat() {
  Suite* suite = suite_create("suite_strncat");
  TCase* tcase = tcase_create("tcase_strncat");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, hello_world);
  tcase_add_test(tcase, empty_string);
  tcase_add_test(tcase, end_symb_inside_string);
  tcase_add_test(tcase, add_more_bytes_than_append_string);

  suite_add_tcase(suite, tcase);

  return suite;
}
