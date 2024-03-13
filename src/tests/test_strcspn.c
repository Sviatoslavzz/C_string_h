#include "my_test.h"

START_TEST(strcspn_test_string_with_string) {
  const char str1[] = "9876543210";
  const char str1_search[] = "537";
  ck_assert_int_eq(strcspn(str1, str1_search), my_strcspn(str1, str1_search));
}
END_TEST

START_TEST(strcspn_test_string_with_end_symb) {
  const char str1[] = "Hel\0lo";
  const char str1_search[] = "Hlo\0";
  ck_assert_int_eq(strcspn(str1, str1_search), my_strcspn(str1, str1_search));
}
END_TEST

START_TEST(strcspn_test_string_with_empty) {
  const char str2[] = "1111111";
  const char str2_search[] = "";
  ck_assert_int_eq(strcspn(str2, str2_search), my_strcspn(str2, str2_search));
}
END_TEST

START_TEST(strcspn_test_empty_with_string) {
  const char str3[] = "";
  const char str3_search[] = "753";
  ck_assert_int_eq(strcspn(str3, str3_search), my_strcspn(str3, str3_search));
}
END_TEST

START_TEST(strcspn_test_string_with_signes) {
  const char str4[] =
      "!(^)*+,-./"
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}"
      "~";
  const char str4_search[] = "+*^";
  ck_assert_int_eq(strcspn(str4, str4_search), my_strcspn(str4, str4_search));
}
END_TEST

Suite *suite_strcspn() {
  Suite *suite = suite_create("suite_strcspn");
  TCase *tcase = tcase_create("tcase_strcspn");

  tcase_add_test(tcase, strcspn_test_string_with_empty);
  tcase_add_test(tcase, strcspn_test_empty_with_string);
  tcase_add_test(tcase, strcspn_test_string_with_signes);
  tcase_add_test(tcase, strcspn_test_string_with_string);
  tcase_add_test(tcase, strcspn_test_string_with_end_symb);

  suite_add_tcase(suite, tcase);

  return suite;
}