#include "my_test.h"

START_TEST(Hello_world_find_e) {
  const char str1[] = "Hello world";
  const char str2[] = "e";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(Hello_world_find_H) {
  const char str1[] = "Hello world";
  const char str2[] = "eoltH";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(Hello_world_find_d) {
  const char str1[] = "Hello world";
  const char str2[] = "d312q";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(Hello_world_find_non_existing) {
  const char str1[] = "Hello world";
  const char str2[] = "q";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(Hello_world_find_space) {
  const char str1[] = "Hello world";
  const char str2[] = " ";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(empty_str_find_any) {
  const char str1[] = "";
  const char str2[] = "123";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(empty_str_find_emty) {
  const char str1[] = "";
  const char str2[] = "";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(tab_str_find_tab) {
  const char str1[] = "123	123";
  const char str2[] = "	";
  ck_assert_pstr_eq(my_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *suite = suite_create("suite_strpbrk");
  TCase *tcase = tcase_create("tcase_strpbrk");

  tcase_add_test(tcase, tab_str_find_tab);
  tcase_add_test(tcase, Hello_world_find_e);
  tcase_add_test(tcase, Hello_world_find_H);
  tcase_add_test(tcase, Hello_world_find_d);
  tcase_add_test(tcase, empty_str_find_any);
  tcase_add_test(tcase, empty_str_find_emty);
  tcase_add_test(tcase, Hello_world_find_space);
  tcase_add_test(tcase, Hello_world_find_non_existing);

  suite_add_tcase(suite, tcase);

  return suite;
}