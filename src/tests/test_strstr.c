#include "my_test.h"

START_TEST(strstr_test_letters_two_equal_strings) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const char *str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
END_TEST
START_TEST(strstr_test_two_not_equal_strings) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const char *str2 = "PQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
END_TEST
START_TEST(strstr_test_26_letters_with_empty_strings) {
  char *str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char *str2 = "";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
END_TEST
START_TEST(strstr_test_check_string_with_slash_null) {
  char *str1 = "abcdefghijklmnopqrstuvwxyz";
  const char *str2 = "\0";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
END_TEST
START_TEST(strstr_test_check_string_with_slash_n) {
  char *str1 = "0123456789\n";
  const char *str2 = "\n";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
START_TEST(strstr_test_check_string_with_substr) {
  char *str1 = "0123456789";
  const char *str2 = "78";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
END_TEST
START_TEST(strstr_test_check_two_empty_string) {
  char *str1 = "";
  const char *str2 = "";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
END_TEST
START_TEST(strstr_test_check_signes) {
  char *str1 =
      "!(^)*+,-./"
      "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz{|}"
      "~";
  const char *str2 = "(^)";
  ck_assert_pstr_eq(strstr(str1, str2), my_strstr(str1, str2));
}
END_TEST

Suite *suite_strstr() {
  Suite *suite = suite_create("suite_strstr");
  TCase *tcase = tcase_create("tcase_strstr");

  tcase_add_test(tcase, strstr_test_check_signes);
  tcase_add_test(tcase, strstr_test_two_not_equal_strings);
  tcase_add_test(tcase, strstr_test_check_two_empty_string);
  tcase_add_test(tcase, strstr_test_check_string_with_substr);
  tcase_add_test(tcase, strstr_test_letters_two_equal_strings);
  tcase_add_test(tcase, strstr_test_check_string_with_slash_n);
  tcase_add_test(tcase, strstr_test_check_string_with_slash_null);
  tcase_add_test(tcase, strstr_test_26_letters_with_empty_strings);

  suite_add_tcase(suite, tcase);
  return suite;
}