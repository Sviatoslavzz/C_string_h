#include "my_test.h"

START_TEST(memset_test_26_letters_two_equal_strings) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 97; i < 123; i++) {
    ck_assert_str_eq(memset(str1, i, strlen(str1)),
                     my_memset(str2, i, my_strlen(str2)));
    ck_assert_mem_eq(str1, str2, 26);
  }
}
END_TEST

START_TEST(memset_test_check_two_empty_strings) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_str_eq(memset(str1, 97, strlen(str1)),
                   my_memset(str2, 97, my_strlen(str2)));
}
END_TEST

START_TEST(memset_test_check_memory_location_two_empty_strings) {
  char str1[] = "";
  char str2[] = "";
  memset(str1, 97, 1);
  my_memset(str2, 97, 1);
  ck_assert_mem_eq(str1, str2, 1);
}
END_TEST

START_TEST(memset_test_check_two_strings_with_slash_n) {
  char str1[] = "\n";
  char str2[] = "\n";
  ck_assert_str_eq(memset(str1, 48, strlen(str1)),
                   my_memset(str2, 48, my_strlen(str2)));
}
END_TEST

START_TEST(memset_test_check_two_strings_with_slash_0) {
  char str1[] = "\0";
  char str2[] = "\0";
  ck_assert_str_eq(memset(str1, 48, strlen(str1)),
                   my_memset(str2, 48, my_strlen(str2)));
}
END_TEST

START_TEST(memset_test_char) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_str_eq(memset(str1, 'A', strlen(str1)),
                   my_memset(str2, 'A', my_strlen(str2)));
}
END_TEST

START_TEST(memset_test_check_memory_location_two_strings) {
  char str1[] = "Hello world";
  char str2[] = "Hello world";
  memset(str1, 97, 11);
  my_memset(str2, 97, 11);
  ck_assert_mem_eq(str1, str2, 12);
}
END_TEST

START_TEST(memset_test_check_memory_location_two_diff_strings) {
  char str1[] = "nadnhawodiuhn1p928eh";
  char str2[] = ";ljdp2398phe1io;akdn";
  memset(str1, 97, 15);
  my_memset(str2, 97, 15);
  ck_assert_mem_eq(str1, str2, 15);
}
END_TEST

Suite *suite_memset() {
  Suite *suite = suite_create("suite_memset");
  TCase *tcase = tcase_create("tcase_memset");

  tcase_add_test(tcase, memset_test_char);
  tcase_add_test(tcase, memset_test_check_two_empty_strings);
  tcase_add_test(tcase, memset_test_26_letters_two_equal_strings);
  tcase_add_test(tcase, memset_test_check_two_strings_with_slash_n);
  tcase_add_test(tcase, memset_test_check_two_strings_with_slash_0);
  tcase_add_test(tcase, memset_test_check_memory_location_two_strings);
  tcase_add_test(tcase, memset_test_check_memory_location_two_diff_strings);
  tcase_add_test(tcase, memset_test_check_memory_location_two_empty_strings);

  suite_add_tcase(suite, tcase);
  return suite;
}