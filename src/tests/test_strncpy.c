#include "my_test.h"

START_TEST(basic) {
  char string[20] = {'\0'};
  char string_test[20] = {'\0'};
  const char *src = "Hello";
  my_size_t count = 4;

  ck_assert_str_eq(my_strncpy(string, src, count),
                   strncpy(string_test, src, count));
}
END_TEST

START_TEST(large_count) {
  char string[] = "Hello World";
  char string_test[] = "Hello World";
  const char *src = "777";
  my_size_t count = 4;

  ck_assert_str_eq(my_strncpy(string, src, count),
                   strncpy(string_test, src, count));
}
START_TEST(large_count_ptr) {
  char string[] = "Hello World";
  char string_test[] = "Hello World";
  const char *src = "777";
  my_size_t count = 4;

  ck_assert_mem_eq(my_strncpy(string, src, count),
                   strncpy(string_test, src, count), 11);
}

END_TEST

START_TEST(small_count) {
  char string[] = "Hello World";
  char string_test[] = "Hello World";
  const char *src = "777";
  my_size_t count = 2;

  ck_assert_str_eq(my_strncpy(string, src, count),
                   strncpy(string_test, src, count));
}
END_TEST

START_TEST(empty_entry) {
  char string[20] = {'\0'};
  char string_test[20] = {'\0'};
  const char *src = "";
  my_size_t count = 5;

  ck_assert_str_eq(my_strncpy(string, src, count),
                   strncpy(string_test, src, count));
}
END_TEST

START_TEST(empty_entry_with_text) {
  char string[] = "Hello World";
  char string_test[] = "Hello World";
  const char *src = "";
  my_size_t count = 5;

  ck_assert_str_eq(my_strncpy(string, src, count),
                   strncpy(string_test, src, count));
}
END_TEST

START_TEST(copy_to_empty) {
  char string[20];
  char string_test[20];
  const char *src = "12345";
  my_size_t count = 5;
  ck_assert_mem_eq(my_strncpy(string, src, count),
                   strncpy(string_test, src, count), 5);
}
END_TEST

Suite *suite_strncpy() {
  Suite *suite = suite_create("suite_strncpy");
  TCase *tcase = tcase_create("tcase_strncpy");

  tcase_add_test(tcase, basic);
  tcase_add_test(tcase, large_count);
  tcase_add_test(tcase, small_count);
  tcase_add_test(tcase, empty_entry);
  tcase_add_test(tcase, copy_to_empty);
  tcase_add_test(tcase, large_count_ptr);
  tcase_add_test(tcase, empty_entry_with_text);

  suite_add_tcase(suite, tcase);

  return suite;
}