#include "my_test.h"

START_TEST(hello_world) {
  const char str[] = "Hello world";
  ck_assert_ptr_eq(memchr(str, 'l', 5), my_memchr(str, 'l', 5));
}
END_TEST

START_TEST(empty_string) {
  const char str[] = "";
  ck_assert_ptr_eq(memchr(str, '\0', 1), my_memchr(str, '\0', 1));
}
END_TEST

START_TEST(end_symb_inside_string) {
  const char str[] = "Hello\0world";
  ck_assert_ptr_eq(memchr(str, 'd', 11), my_memchr(str, 'd', 11));
}
END_TEST

START_TEST(num) {
  const char str[] = "123456789";
  ck_assert_ptr_eq(memchr(str, '6', 6), my_memchr(str, '6', 6));
}
END_TEST

START_TEST(num_chars_string) {
  const char str[] = "123456789abcdefghijklmnopqrstuvwxyz";
  ck_assert_ptr_eq(memchr(str, 'a', 20), my_memchr(str, 'a', 20));
}
END_TEST

START_TEST(end_symb) {
  const char str[] = "\0";
  ck_assert_ptr_eq(memchr(str, '\0', 2), my_memchr(str, '\0', 2));
}
END_TEST

START_TEST(spaces) {
  const char str[] = "        ";
  ck_assert_ptr_eq(memchr(str, ' ', 8), my_memchr(str, ' ', 8));
}
END_TEST

START_TEST(tabs) {
  const char str[] = "					";
  ck_assert_ptr_eq(memchr(str, '\t', 5), my_memchr(str, '\t', 5));
}
END_TEST

START_TEST(null_test) {
  const char str[] = "ABCDE";
  ck_assert_ptr_eq(memchr(str, 'F', 5), my_memchr(str, 'F', 5));
}
END_TEST

START_TEST(not_enough_bytes) {
  const char str[] = "ABCDEF";
  ck_assert_ptr_eq(memchr(str, 'F', 3), my_memchr(str, 'F', 3));
}
END_TEST

START_TEST(find_num_in_array) {
  int array[] = {1, 2, 3, 777, 5, 99};
  ck_assert_ptr_eq(my_memchr(array, 777, sizeof(int) * 6),
                   memchr(array, 777, sizeof(int) * 6));
}
END_TEST

Suite* suite_memchr() {
  Suite* suite = suite_create("suite_memchr");
  TCase* tcase = tcase_create("tcase_memchr");

  tcase_add_test(tcase, num);
  tcase_add_test(tcase, tabs);
  tcase_add_test(tcase, spaces);
  tcase_add_test(tcase, end_symb);
  tcase_add_test(tcase, null_test);
  tcase_add_test(tcase, hello_world);
  tcase_add_test(tcase, empty_string);
  tcase_add_test(tcase, num_chars_string);
  tcase_add_test(tcase, not_enough_bytes);
  tcase_add_test(tcase, find_num_in_array);
  tcase_add_test(tcase, end_symb_inside_string);

  suite_add_tcase(suite, tcase);
  return suite;
}
