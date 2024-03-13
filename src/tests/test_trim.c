#include "my_test.h"

START_TEST(hello_world_spaces) {
  const char src_origin[20] = " Hello, World! ";
  const char trim[20] = " ";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "Hello, World!";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(hello_world_different) {
  const char src_origin[20] = " Hello, World! ";
  const char trim[20] = "H !d";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "ello, Worl";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(hello_world_not_include) {
  const char src_origin[20] = "Hello, World!";
  const char trim[20] = "x4&";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "Hello, World!";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(hello_world_nothing) {
  const char src_origin[20] = "Hello, World!";
  const char trim[20] = "";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "Hello, World!";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(empty_string_str) {
  const char src_origin[20] = "";
  const char trim[20] = "";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(end_symb_inside_string) {
  const char src_origin[20] = "Hell\0o, World!";
  const char trim[20] = "!d";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "Hell";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(num) {
  const char src_origin[20] = "12345678910";
  const char trim[20] = "10";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "23456789";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(end_symb) {
  const char src_origin[20] = "\0";
  const char trim[20] = "\0";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(spaces) {
  const char src_origin[20] = "    ";
  const char trim[20] = " ";
  char *str_res = my_trim(src_origin, trim);
  const char str_check[] = "";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

Suite *suite_trim() {
  Suite *suite = suite_create("suite_trim");
  TCase *tcase = tcase_create("tcase_trim");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, empty_string_str);
  tcase_add_test(tcase, hello_world_spaces);
  tcase_add_test(tcase, hello_world_nothing);
  tcase_add_test(tcase, hello_world_different);
  tcase_add_test(tcase, end_symb_inside_string);
  tcase_add_test(tcase, hello_world_not_include);
  suite_add_tcase(suite, tcase);

  return suite;
}