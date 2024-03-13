#include "my_test.h"

START_TEST(hello_world_12_bytes) {
  const char src[] = "Hello world";
  char dest1[12];
  char dest2[12];
  memcpy(dest1, src, 12);
  my_memcpy(dest2, src, 12);
  ck_assert_mem_eq(dest1, dest2, 12);
}
END_TEST

START_TEST(hello_world_5_bytes) {
  const char src[] = "Hello world";
  char dest1[5];
  char dest2[5];
  memcpy(dest1, src, 5);
  my_memcpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(empty_str_1_byte) {
  const char src[] = "";
  char dest1[1];
  char dest2[1];
  memcpy(dest1, src, 1);
  my_memcpy(dest2, src, 1);
  ck_assert_mem_eq(dest1, dest2, 1);
}
END_TEST

START_TEST(rand_str_15_bytes) {
  const char src[] = "o2ih12h12ejn12eljiawjdlawdjpj21o3ij";
  char dest1[15];
  char dest2[15];
  memcpy(dest1, src, 15);
  my_memcpy(dest2, src, 15);
  ck_assert_mem_eq(dest1, dest2, 15);
}
END_TEST

START_TEST(spaces_4_bytes) {
  const char src[] = "          ";
  char dest1[20];
  char dest2[20];
  memcpy(dest1, src, 4);
  my_memcpy(dest2, src, 4);
  ck_assert_mem_eq(dest1, dest2, 4);
}
END_TEST

START_TEST(nums_25_bytes) {
  const char src[] = "891264912846192837192846192863";
  char dest1[25];
  char dest2[25];
  memcpy(dest1, src, 25);
  my_memcpy(dest2, src, 25);
  ck_assert_mem_eq(dest1, dest2, 25);
}
END_TEST

START_TEST(mixed_51_bytes) {
  const char src[] =
      " j a al;j al j       le1j2e 1p2ej  lajd-02j1 poadm aj\n\n 12pi1l3";
  char dest1[52];
  char dest2[52];
  memcpy(dest1, src, 51);
  my_memcpy(dest2, src, 51);
  ck_assert_mem_eq(dest1, dest2, 51);
}
END_TEST

START_TEST(rand_str_0_bytes) {
  const char src[] = "jadlja";
  char dest1[5];
  char dest2[5];
  memcpy(dest1, src, 0);
  my_memcpy(dest2, src, 0);
  ck_assert_mem_eq(dest1, dest2, 0);
}
END_TEST

START_TEST(end_symb_in_string) {
  const char src[] = "jad\0lja";
  char dest1[5];
  char dest2[5];
  memcpy(dest1, src, 4);
  my_memcpy(dest2, src, 4);
  ck_assert_mem_eq(dest1, dest2, 4);
}
END_TEST

Suite *suite_memcpy() {
  Suite *suite = suite_create("suite_memcpy");
  TCase *tcase = tcase_create("tcase_memcpy");

  tcase_add_test(tcase, nums_25_bytes);
  tcase_add_test(tcase, spaces_4_bytes);
  tcase_add_test(tcase, mixed_51_bytes);
  tcase_add_test(tcase, empty_str_1_byte);
  tcase_add_test(tcase, rand_str_0_bytes);
  tcase_add_test(tcase, rand_str_15_bytes);
  tcase_add_test(tcase, end_symb_in_string);
  tcase_add_test(tcase, hello_world_5_bytes);
  tcase_add_test(tcase, hello_world_12_bytes);

  suite_add_tcase(suite, tcase);

  return suite;
}