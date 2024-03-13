#include "my_test.h"

START_TEST(hello_world_strlen) {
  const char src_origin[20] = "Hello, ";
  const char str_origin[20] = "World!";
  char* str_res = my_insert(src_origin, str_origin, my_strlen(src_origin));
  const char str_check[] = "Hello, World!";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(hello_world_start) {
  const char src_origin[20] = "Hello, ";
  const char str_origin[20] = "World!";
  char* str_res = my_insert(src_origin, str_origin, 0);
  const char str_check[] = "World!Hello, ";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(hello_world_center) {
  const char src_origin[20] = "Hello, ";
  const char str_origin[20] = "World!";
  char* str_res = my_insert(src_origin, str_origin, 3);
  const char str_check[] = "HelWorld!lo, ";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(hello_world_big_start) {
  const char src_origin[20] = "Hello, ";
  const char str_origin[20] = "World!";
  char* str_res = my_insert(src_origin, str_origin, my_strlen(src_origin) + 20);
  const char str_check[] = "Hello, World!";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(empty_string_str) {
  const char src_origin[20] = "";
  const char str_origin[20] = "";
  char* str_res = my_insert(src_origin, str_origin, 3);
  const char str_check[] = "";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(end_symb_inside_string) {
  const char src_origin[20] = "Hel\0lo, ";
  const char str_origin[20] = "Worl\0d!";
  char* str_res = my_insert(src_origin, str_origin, my_strlen(src_origin));
  const char str_check[] = "HelWorl";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(num) {
  const char src_origin[20] = "123456";
  const char str_origin[20] = "789101112";
  char* str_res = my_insert(src_origin, str_origin, 3);
  const char str_check[] = "123789101112456";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(end_symb) {
  const char src_origin[20] = "\0";
  const char str_origin[20] = "\0";
  char* str_res = my_insert(src_origin, str_origin, 3);
  const char str_check[] = "\0";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(spaces) {
  const char src_origin[20] = "    ";
  const char str_origin[20] = "    ";
  char* str_res = my_insert(src_origin, str_origin, 3);
  const char str_check[] = "        ";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(null_str) {
  const char src_origin[20] = "Tested:    ";
  const char str_origin[20] = "";
  char* str_res = my_insert(src_origin, str_origin, 3);
  const char str_check[] = "Tested:    ";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

START_TEST(null_str_2) {
  const char src_origin[20] = "Tested:    ";
  const char* str_origin = MY_NULL;
  char* str_res = my_insert(src_origin, str_origin, 3);
  const char str_check[] = "Tested:    ";
  ck_assert_str_eq(str_res, str_check);
  free(str_res);
}
END_TEST

END_TEST
Suite* suite_insert() {
  Suite* suite = suite_create("suite_insert");
  TCase* tcase = tcase_create("tcase_insert");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, null_str);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, null_str_2);
  tcase_add_test(tcase, empty_string_str);
  tcase_add_test(tcase, hello_world_start);
  tcase_add_test(tcase, hello_world_strlen);
  tcase_add_test(tcase, hello_world_center);
  tcase_add_test(tcase, hello_world_big_start);
  tcase_add_test(tcase, end_symb_inside_string);

  suite_add_tcase(suite, tcase);

  return suite;
}