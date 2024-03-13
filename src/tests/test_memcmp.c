#include "my_test.h"

START_TEST(hello_world) {
  const char str1[] = "Hello world";
  const char str2[] = "Hello world";
  ck_assert_int_eq(memcmp(str1, str2, 11), my_memcmp(str1, str2, 11));
}
END_TEST

START_TEST(empty_string) {
  const char str1[] = "";
  const char str2[] = "";
  ck_assert_int_eq(memcmp(str1, str2, 1), my_memcmp(str1, str2, 1));
}
END_TEST

START_TEST(end_symb_inside_string) {
  const char str1[] = "Hello\0world";
  const char str2[] = "Hello";
  ck_assert_int_eq(memcmp(str1, str2, 6), my_memcmp(str1, str2, 6));
}
END_TEST

START_TEST(num) {
  const char str1[] = "123456789";
  const char str2[] = "123459876";
  ck_assert_int_eq(memcmp(str1, str2, 5), my_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(end_symb) {
  const char str1[] = "\0";
  const char str2[] = "\0";
  ck_assert_int_eq(memcmp(str1, str2, 1), my_memcmp(str1, str2, 1));
}
END_TEST

START_TEST(spaces) {
  const char str1[] = "        ";
  const char str2[] = "        ";
  ck_assert_int_eq(memcmp(str1, str2, 4), my_memcmp(str1, str2, 4));
}
END_TEST

START_TEST(positive_test) {
  const char str1[] = "ABCDE";
  const char str2[] = "ABBDE";
  ck_assert_int_eq(memcmp(str1, str2, 4), my_memcmp(str1, str2, 4));
}
END_TEST

START_TEST(negative_test) {
  const char str1[] = "ABCDE";
  const char str2[] = "ABDDE";
  ck_assert_int_eq(memcmp(str1, str2, 4), my_memcmp(str1, str2, 4));
}
END_TEST

Suite* suite_memcmp() {
  Suite* suite = suite_create("suite_memcmp");
  TCase* tcase = tcase_create("tcase_memcmp");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, hello_world);
  tcase_add_test(tcase, empty_string);
  tcase_add_test(tcase, positive_test);
  tcase_add_test(tcase, negative_test);
  tcase_add_test(tcase, end_symb_inside_string);

  suite_add_tcase(suite, tcase);

  return suite;
}
