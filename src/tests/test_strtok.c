#include "my_test.h"

START_TEST(strtok_test_strings_delim_minus) {
  char str1[] = "ABCDEF-GHIJKLMNO-PQRSTUVWXYZ-abcdefghijk-lmnopqrst-uvwxyz";
  char str2[] = "ABCDEF-GHIJKLMNO-PQRSTUVWXYZ-abcdefghijk-lmnopqrst-uvwxyz";
  const char str_delim[] = "-";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

START_TEST(strtok_test_strings_delim_underlining) {
  char str1[] = "EXPORT_ALL_VARIABLES";
  char str2[] = "EXPORT_ALL_VARIABLES";
  const char str_delim[] = "_";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

START_TEST(strtok_test_strings_delim_slash) {
  char str1[] = "License/as/published/by/the/Free/Software/Foundation";
  char str2[] = "License/as/published/by/the/Free/Software/Foundation";
  const char str_delim[] = "/";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

START_TEST(strtok_test_check_strings_delim_space) {
  char str1[] =
      "You should have received a copy of the GNU Lesser General Public "
      "License along with this library";
  char str2[] =
      "You should have received a copy of the GNU Lesser General Public "
      "License along with this library";
  const char str_delim[] = " ";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

START_TEST(strtok_test_check_strings_delim_caret) {
  char str1[] = "This^document^was^generated^on^August^8,^2020";
  char str2[] = "This^document^was^generated^on^August^8,^2020";
  const char str_delim[] = "^";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

START_TEST(strtok_test_check_strings_delim_comma) {
  char str1[] = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z";
  char str2[] = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z";
  const char str_delim[] = ",";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

START_TEST(strtok_test_check_strings_delim_nulterminator) {
  char str1[] = "0123456789";
  char str2[] = "0123456789";
  const char str_delim[] = "\0";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

START_TEST(strtok_test_check_strings_delim_substring) {
  char str1[] = "ABCDEFGH";
  char str2[] = "ABCDEFGH";
  const char str_delim[] = "ABCD";
  char *tmp_str1 = strtok(str1, str_delim);
  char *tmp_str2 = my_strtok(str2, str_delim);
  while (tmp_str1 && tmp_str2) {
    ck_assert_str_eq(tmp_str1, tmp_str2);
    tmp_str1 = strtok(NULL, str_delim);
    tmp_str2 = my_strtok(MY_NULL, str_delim);
  }
}
END_TEST

Suite *suite_strtok() {
  Suite *suite = suite_create("suite_strtok");
  TCase *tcase = tcase_create("tcase_strtok");

  tcase_add_test(tcase, strtok_test_strings_delim_minus);
  tcase_add_test(tcase, strtok_test_strings_delim_slash);
  tcase_add_test(tcase, strtok_test_check_strings_delim_space);
  tcase_add_test(tcase, strtok_test_strings_delim_underlining);
  tcase_add_test(tcase, strtok_test_check_strings_delim_caret);
  tcase_add_test(tcase, strtok_test_check_strings_delim_comma);
  tcase_add_test(tcase, strtok_test_check_strings_delim_substring);
  tcase_add_test(tcase, strtok_test_check_strings_delim_nulterminator);

  suite_add_tcase(suite, tcase);

  return suite;
}