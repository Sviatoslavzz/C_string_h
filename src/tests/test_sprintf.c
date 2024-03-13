#include <limits.h>

#include "my_test.h"
// integer
START_TEST(integer) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 1;
  const char* format = "number: %d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 99119977;
  const char* format = "number: %d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %2.2d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %3.3d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_4) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %6.7d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_5) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = -777;
  const char* format = "number: %-.7d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_6) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %+.7d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_7) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: % .7d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_8) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %*.*d";
  int int_std = sprintf(str_std, format, 4, 10, number);
  int int_my = my_sprintf(str_my, format, 4, 10, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_9) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %-020d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_10) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %-20.2d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_11) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %+020d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_12) {
  char str_std[150] = {'\0'};
  char str_my[150] = {'\0'};
  int number = 2147483647;
  const char* format = "number: % .50d, %1d, %+d, %d";
  int int_std = sprintf(str_std, format, number, number, number, number);
  int int_my = my_sprintf(str_my, format, number, number, number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_13) {
  char str_std[150] = {'\0'};
  char str_my[150] = {'\0'};
  int number = 2147483647;
  const char* format = "number: %+050.10d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_14) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 123456;
  const char* format = "number: %-20.7d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_15) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  short int number = 12;
  const char* format = "number: %hd";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_16) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 0;
  const char* format = "number: % d";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(integer_17) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = -999, number1 = 0, number2 = 777, number3 = -100;
  const char* format = "number: %d%d%d%d";
  int int_std = sprintf(str_std, format, number, number1, number2, number3);
  int int_my = my_sprintf(str_my, format, number, number1, number2, number3);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// long integer
START_TEST(long_integer) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  long int number = 10;
  const char* format = "number: %ld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_1) {
  char str_my[70] = {'\0'};
  char str_std[70] = {'\0'};
  long long int number = 9223372036854775807;
  const char* format = "number: %lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_2) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  long long int number = 9223372036854775807;
  const char* format = "number: %2.2lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_3) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  long long int number = 9223372036854775807;
  const char* format = "number: %3.40lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_4) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  long long int number = -9223372036854775807;
  const char* format = "number: %-40.7lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_5) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  long int number = 123456;
  const char* format = "number: %-.7ld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_6) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  long int number = 999999999;
  const char* format = "number: % 015.7ld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_7) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  long long int number = 11111111112;
  const char* format = "number: % -.20lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_8) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  long long int number = 1111;
  const char* format = "number: %*.*lld";
  int int_std = sprintf(str_std, format, 4, 10, number);
  int int_my = my_sprintf(str_my, format, 4, 10, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_9) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  long long int number = 9223372036854775807;
  const char* format = "number: %+050lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_10) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  long long int number = 92233720368;
  const char* format = "number: %+-50.30lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_integer_11) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  long long int number = 123123;
  const char* format = "number: %-+20lld";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// char "c"
START_TEST(ch) {
  char str_std[10] = {'\0'};
  char str_my[10] = {'\0'};
  char symbol = 'a';
  const char* format = "char: %c";
  int int_std = sprintf(str_std, format, symbol);
  int int_my = my_sprintf(str_my, format, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(ch_1) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char symbol = 'a';
  const char* format = "char: %2c";
  int int_std = sprintf(str_std, format, symbol);
  int int_my = my_sprintf(str_my, format, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(ch_2) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char symbol = 'a';
  const char* format = "char: %*c";
  int int_std = sprintf(str_std, format, 4, symbol);
  int int_my = my_sprintf(str_my, format, 4, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(ch_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  char symbol = 'a';
  const char* format = "char: %20c";
  int int_std = sprintf(str_std, format, symbol);
  int int_my = my_sprintf(str_my, format, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(ch_4) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  char symbol = '%';
  const char* format = "char: %-*c";
  int int_std = sprintf(str_std, format, 20, symbol);
  int int_my = my_sprintf(str_my, format, 20, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(ch_5) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  int symbol = 78;
  const char* format = "char: %.10c";
  int int_std = sprintf(str_std, format, symbol);
  int int_my = my_sprintf(str_my, format, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(ch_6) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  char symbol = 'q';
  const char* format = "char: %c, %c, %c----123";
  int int_std = sprintf(str_std, format, symbol, symbol, symbol);
  int int_my = my_sprintf(str_my, format, symbol, symbol, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_ch_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned long symbol = 150;
  const char* format = "char: %lc";
  int int_std = sprintf(str_std, format, symbol);
  int int_my = my_sprintf(str_my, format, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_ch_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned long symbol = 230;
  const char* format = "char: %10lc";
  int int_std = sprintf(str_std, format, symbol);
  int int_my = my_sprintf(str_my, format, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_ch_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned long symbol = 300;
  const char* format = "char: %lc";
  int int_std = sprintf(str_std, format, symbol);
  int int_my = my_sprintf(str_my, format, symbol);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

START_TEST(wide_string_0) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  wchar_t* w = NULL;
  const char* format = "char: %ls";
  int int_std = sprintf(str_std, format, w);
  int int_my = my_sprintf(str_my, format, w);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(wide_string_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  wchar_t w[4] = {450, 450, 450, 450};
  const char* format = "char: %ls";
  int int_std = sprintf(str_std, format, w);
  int int_my = my_sprintf(str_my, format, w);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(wide_string_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  wchar_t w[5] = {50, 60, 70, 80, 0};
  const char* format = "char: %10.2ls";
  int int_std = sprintf(str_std, format, w);
  int int_my = my_sprintf(str_my, format, w);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(wide_string_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  wchar_t w[5] = {50, 60, 70, 400, 0};
  const char* format = "char: %ls";
  int int_std = sprintf(str_std, format, w);
  int int_my = my_sprintf(str_my, format, w);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// Decimal "i"

START_TEST(decimal) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 1;
  const char* format = "number: %i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 99119977;
  const char* format = "number: %i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %2.2i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %3.3i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_4) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %6.7i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_5) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = -777;
  const char* format = "number: %-.7i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_6) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %+.7i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_7) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: % .7i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_8) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %*.*i";
  int int_std = sprintf(str_std, format, 4, 10, number);
  int int_my = my_sprintf(str_my, format, 4, 10, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_9) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %-020i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_10) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %-020.2i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_11) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  int number = 777;
  const char* format = "number: %+020.1i";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_12) {
  char str_std[150] = {'\0'};
  char str_my[150] = {'\0'};
  int number = 2147483647;
  const char* format = "number: % .50i, %1i, %+i, %i";
  int int_std = sprintf(str_std, format, number, number, number, number);
  int int_my = my_sprintf(str_my, format, number, number, number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(decimal_13) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  signed char number = 11;
  const char* format = "number: %hhi";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// %% "%"

START_TEST(symbol_percent) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  int int_std = sprintf(str_std, "char: %%");
  int int_my = my_sprintf(str_my, "char: %%");
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(symbol_percent_1) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  int number = 123;
  int int_std = sprintf(str_std, "char: %%d%d%dasd%%", number, number);
  int int_my = my_sprintf(str_my, "char: %%d%d%dasd%%", number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// hexadecimal integer "x"

START_TEST(hexadecimal) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %x";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %#x";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %.10x";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %-#10x";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_4) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %0#20x";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_5) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  unsigned long int number = 4294967295;
  const char* format = "num: % 30lx";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_6) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 9999;
  const char* format = "num: %.5hx";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_7) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 100;
  const char* format = "num: %*hx";
  int int_std = sprintf(str_std, format, 10, number);
  int int_my = my_sprintf(str_my, format, 10, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_8) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 1;
  const char* format = "num: %*.*hx";
  int int_std = sprintf(str_std, format, 10, 5, number);
  int int_my = my_sprintf(str_my, format, 10, 5, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_9) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#hx";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_10) {
  char str_std[150] = {'\0'};
  char str_my[150] = {'\0'};
  unsigned int number = 10991099;
  const char* format = "num: %#x, %#-30x, %.15x";
  int int_std = sprintf(str_std, format, number, number, number);
  int int_my = my_sprintf(str_my, format, number, number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_11) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#20x";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_12) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#.20x";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(hexadecimal_13) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = -11;
  const char* format = "num: %hx";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// capital hexadecimal integer "X"

START_TEST(capital_hexadecimal) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %X";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %#X";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %.10X";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %-#10X";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_4) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %0#20X";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_5) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  unsigned long int number = 4294967295;
  const char* format = "num: % 30lX";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_6) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 9999;
  const char* format = "num: %.5hX";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_7) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 100;
  const char* format = "num: %*hX";
  int int_std = sprintf(str_std, format, 10, number);
  int int_my = my_sprintf(str_my, format, 10, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_8) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 1;
  const char* format = "num: %*.*hX";
  int int_std = sprintf(str_std, format, 10, 5, number);
  int int_my = my_sprintf(str_my, format, 10, 5, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_9) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#hX";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_10) {
  char str_std[150] = {'\0'};
  char str_my[150] = {'\0'};
  unsigned int number = 10991099;
  const char* format = "num: %#X, %#-30X, %.15X";
  int int_std = sprintf(str_std, format, number, number, number);
  int int_my = my_sprintf(str_my, format, number, number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_11) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#20X";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_hexadecimal_12) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#.20X";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// pointer "p"

START_TEST(pointer) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* pointer = str_std;
  const char* format = "pointer: %p";
  int int_std = sprintf(str_std, format, pointer);
  int int_my = my_sprintf(str_my, format, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(pointer_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  char* pointer = str_std;
  const char* format = "pointer: %20p";
  int int_std = sprintf(str_std, format, pointer);
  int int_my = my_sprintf(str_my, format, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(pointer_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  char* pointer = str_std;
  const char* format = "pointer: %-20p";
  int int_std = sprintf(str_std, format, pointer);
  int int_my = my_sprintf(str_my, format, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(pointer_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  char* pointer = str_std;
  const char* format = "pointer: %*p";
  int int_std = sprintf(str_std, format, 25, pointer);
  int int_my = my_sprintf(str_my, format, 25, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(pointer_4) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  char* pointer = str_std;
  const char* format = "pointer: %-*p";
  int int_std = sprintf(str_std, format, 25, pointer);
  int int_my = my_sprintf(str_my, format, 25, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(pointer_5) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  char* pointer = NULL;
  const char* format = "pointer: %p";
  int int_std = sprintf(str_std, format, pointer);
  int int_my = my_sprintf(str_my, format, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(pointer_6) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  char* pointer = str_std;
  const char* format = "pointer: %020p";
  int int_std = sprintf(str_std, format, pointer);
  int int_my = my_sprintf(str_my, format, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(pointer_7) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  char* pointer = str_std;
  const char* format = "pointer: %#p";
  int int_std = sprintf(str_std, format, pointer);
  int int_my = my_sprintf(str_my, format, pointer);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// string "s"

START_TEST(string) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_1) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %.0s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_2) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %1.1s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_3) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %2.1s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_4) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %20s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_5) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %-20s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_6) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %+20s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_7) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %+20s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_8) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: %*s";
  int int_std = sprintf(str_std, format, 20, str);
  int int_my = my_sprintf(str_my, format, 20, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_9) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  char* str = "123456, \n!%)(;}{}):,.;!";
  const char* format = "str: %*.*s";
  int int_std = sprintf(str_std, format, 30, 12, str);
  int int_my = my_sprintf(str_my, format, 30, 12, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_10) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  char* str = "Hello, verter!";
  const char* format = "str: % +-#.7s, % .5s, %s, %1s";
  int int_std = sprintf(str_std, format, str, str, str, str);
  int int_my = my_sprintf(str_my, format, str, str, str, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_11) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = NULL;
  const char* format = "str: %s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_12) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = NULL;
  const char* format = "str: %15.2s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_13) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = NULL;
  const char* format = "str: %-20s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_14) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = NULL;
  const char* format = "str: %.3s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(string_15) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  char* str = "Hello22124";
  const char* format = "str: %20s";
  int int_std = sprintf(str_std, format, str);
  int int_my = my_sprintf(str_my, format, str);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// unsigned decimal "u"

START_TEST(unsigned_decimal) {
  char str_std[30] = {'\0'};
  char str_my[30] = {'\0'};
  unsigned int number = 77;
  const char* format = "char: %u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 77;
  const char* format = "char: 32%-20u32";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 77;
  const char* format = "char: %.3u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 9999;
  const char* format = "char: %*.*u";
  int int_std = sprintf(str_std, format, 10, 5, number);
  int int_my = my_sprintf(str_my, format, 10, 5, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_4) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 77;
  const char* format = "char: %+*.*u";
  int int_std = sprintf(str_std, format, 10, 5, number);
  int int_my = my_sprintf(str_my, format, 10, 5, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_5) {
  char str_std[70] = {'\0'};
  char str_my[70] = {'\0'};
  unsigned int number = 10000001;
  const char* format = "char: %-*.*u";
  int int_std = sprintf(str_std, format, 20, 10, number);
  int int_my = my_sprintf(str_my, format, 20, 10, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_6) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 77;
  const char* format = "char: % u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_7) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 1;
  const char* format = "char: %020u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_8) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 123123;
  const char* format = "char: %u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_9) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 77;
  const char* format = "char: %+u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_10) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 0;
  const char* format = "char: %020u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_11) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned int number = 0;
  const char* format = "char: %.10u";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_decimal_12) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  unsigned char number = 12;
  const char* format = "char: %.10hhu";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// unsigned octal number "o"

START_TEST(unsigned_octal) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %#o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %.10o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %-#10o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_4) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned int number = 75347;
  const char* format = "num: %0#20o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_5) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  unsigned long int number = 4294967295;
  const char* format = "num: % 30lo";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_6) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 9999;
  const char* format = "num: %.5ho";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_7) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 100;
  const char* format = "num: %*ho";
  int int_std = sprintf(str_std, format, 10, number);
  int int_my = my_sprintf(str_my, format, 10, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_8) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 1;
  const char* format = "num: %*.*ho";
  int int_std = sprintf(str_std, format, 10, 5, number);
  int int_my = my_sprintf(str_my, format, 10, 5, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_9) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#ho";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_10) {
  char str_std[150] = {'\0'};
  char str_my[150] = {'\0'};
  unsigned int number = 10991099;
  const char* format = "num: %#o, %#-30o, %.15o";
  int int_std = sprintf(str_std, format, number, number, number);
  int int_my = my_sprintf(str_my, format, number, number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_11) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#20o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_12) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#.20o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(unsigned_octal_13) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  unsigned short int number = 0;
  const char* format = "num: %#.0o";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// float "f"

START_TEST(float_) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 10.000005;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 0.000005;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %.10f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_4) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %.1f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_5) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %+.10f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_6) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %+20.10f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_7) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %020.10f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_8) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %+020.10f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_9) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: % 020.10f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_10) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: % .1f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_11) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = -778.342;
  const char* format = "number: %-20.1f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_12) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %-.10f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_13) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 0.123;
  const char* format = "number: %+0*.*f";
  int int_std = sprintf(str_std, format, 5, 2, number);
  int int_my = my_sprintf(str_my, format, 5, 2, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_14) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 1.5;
  const char* format = "number: %.0f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_15) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 1.6;
  const char* format = "number: %.0f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_16) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 1.4;
  const char* format = "number: %.0f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_17) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 9.99999;
  const char* format = "number: %.3f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_18) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 1.778999;
  const char* format = "number: %.4f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_19) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 0.778999;
  const char* format = "number: %.4f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_20) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 123.123;
  const char* format = "number: %#.0f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
START_TEST(float_21) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 123.123;
  const char* format = "number: %.0f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_22) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = NAN;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_23) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = NAN;
  const char* format = "number: %020f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_24) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = INFINITY;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_25) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = INFINITY;
  const char* format = "number: %20f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(float_26) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = -INFINITY;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

START_TEST(double_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 123456789.00006;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(double_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.00000000123456;
  const char* format = "number: %.20f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(double_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0;
  const char* format = "number: %f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(double_4) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0;
  const char* format = "number: %020f";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_double_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 1234567891236.999999;
  const char* format = "number: %Lf";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_double_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 0.999999999999999;
  const char* format = "number: %.2Lf";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(long_double_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 0;
  const char* format = "number: %Lf";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// scientific notation "e"

START_TEST(scientific_notation) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  float number = 778.342;
  const char* format = "number: %e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 778.342;
  const char* format = "number: %.4e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 778342.0;
  const char* format = "number: %.10e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.00778342;
  const char* format = "number: %e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_4) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = -0.00778342;
  const char* format = "number: %.4e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_5) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 7;
  const char* format = "number: %020e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_6) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 77777777777777777777777.0;
  const char* format = "number: %e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_7) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 77777777777777777777777.0;
  const char* format = "number: %.14e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_8) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 0.0000000000000000000000000000000000007;
  const char* format = "number: %.2Le";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_9) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 7.0777;
  const char* format = "number: %.0e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_10) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.00077777;
  const char* format = "number: %.4e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_11) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.00099999;
  const char* format = "number: %.4e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_12) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 1.999999;
  const char* format = "number: %.3e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_13) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %+.10e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_14) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %-20.10e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_15) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %0 20.10e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_16) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %0+20.10e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_17) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %*.*e";
  int int_std = sprintf(str_std, format, 30, 5, number);
  int int_my = my_sprintf(str_my, format, 30, 5, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_18) {
  char str_std[300] = {'\0'};
  char str_my[300] = {'\0'};
  double number = 777.777;
  const char* format = "number: %.0e, %05e, %.14e";
  int int_std = sprintf(str_std, format, number, number, number);
  int int_my = my_sprintf(str_my, format, number, number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_19) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 777.777;
  const char* format = "number: %#.0e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_20) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 0;
  const char* format = "number: %0#20.0e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_21) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 0;
  const char* format = "number: %#.3e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_22) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = NAN;
  const char* format = "number: %e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_23) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = INFINITY;
  const char* format = "number: %.0e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(scientific_notation_24) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  long double number = 15.35;
  const char* format = "number: %.15Le";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// capital scientific notation "E"

START_TEST(capital_scientific_notation) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  float number = 778.342;
  const char* format = "number: %E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_1) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 778.342;
  const char* format = "number: %.4E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_2) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 778342.0;
  const char* format = "number: %.10E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_3) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 0.00778342;
  const char* format = "number: %E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_4) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = -0.00778342;
  const char* format = "number: %.4E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_5) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 7;
  const char* format = "number: %020E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_6) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 77777777777777777777777.0;
  const char* format = "number: %E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_7) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 77777777777777777777777.0;
  const char* format = "number: %.14E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_8) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  long double number = 0.0000000000000000000000000000000000007;
  const char* format = "number: %.2LE";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_9) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 7.0777;
  const char* format = "number: %.0E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_10) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 0.00077777;
  const char* format = "number: %.4E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_11) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 0.00099999;
  const char* format = "number: %.4E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_12) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 1.999999;
  const char* format = "number: %.3E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_13) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %+.10E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_14) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %-20.10E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_15) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %0 20.10E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_16) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %0+20.10E";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_17) {
  char str_std[100] = {'\0'};
  char str_my[100] = {'\0'};
  double number = 123456789.123456789;
  const char* format = "number: %*.*E";
  int int_std = sprintf(str_std, format, 30, 5, number);
  int int_my = my_sprintf(str_my, format, 30, 5, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_18) {
  char str_std[300] = {'\0'};
  char str_my[300] = {'\0'};
  double number = 777.777;
  const char* format = "number: %.0E, %05E, %.14E";
  int int_std = sprintf(str_std, format, number, number, number);
  int int_my = my_sprintf(str_my, format, number, number, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_scientific_notation_19) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  double number = 7;
  const char* format = "number: %#e";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// shortest of decimal "g"

START_TEST(shortest_decimal) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  float number = 778.342;
  const char* format = "number: %g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 7783442.001;
  const char* format = "number: %g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 2.34244;
  const char* format = "number: %g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 432432;
  const char* format = "number: %g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_4) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 4327332.3;
  const char* format = "number: %15g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_5) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.0000004327332715;
  const char* format = "number: %.10g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_6) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 4327332.37;
  const char* format = "number: %-15.2g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_7) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 9.9999;
  const char* format = "number: %+15.3g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_8) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.9999;
  const char* format = "number: % 15.2g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_9) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 123.123;
  const char* format = "number: %10.10g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_10) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 473353453453432.3;
  const char* format = "number: %Lg";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_11) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 0.12312312412412;
  const char* format = "number: %.10Lg";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_12) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 4732.368687;
  const char* format = "number: %+020.5g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_13) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 47375915.0;
  const char* format = "number: %#10g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_14) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.001;
  const char* format = "number: %-*.*g";
  int int_std = sprintf(str_std, format, 5, 2, number);
  int int_my = my_sprintf(str_my, format, 5, 2, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_15) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0;
  const char* format = "number: %0#20.0g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_16) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0;
  const char* format = "number: %g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_17) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 100;
  const char* format = "number: %#g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_18) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.1;
  const char* format = "number: %#.5g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_19) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0;
  const char* format = "number: %0.0g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_20) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = NAN;
  const char* format = "number: %g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_21) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = INFINITY;
  const char* format = "number: %g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_22) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.123000;
  const char* format = "number: %.0g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(shortest_decimal_23) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.123000;
  const char* format = "number: %.g";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// capital shortest of decimal "G"

START_TEST(capital_shortest_decimal) {
  char str_std[50] = {'\0'};
  char str_my[50] = {'\0'};
  float number = 778.342;
  const char* format = "number: %G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 7783442.001;
  const char* format = "number: %G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 2.34244;
  const char* format = "number: %G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 432432;
  const char* format = "number: %G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_4) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 4327332.3;
  const char* format = "number: %15G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_5) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.0000004327332715;
  const char* format = "number: %.10G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_6) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 4327332.37;
  const char* format = "number: %-15.2G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_7) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 9.9999;
  const char* format = "number: %+15.3G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_8) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.9999;
  const char* format = "number: % 15.2G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_9) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 123.123;
  const char* format = "number: %10.10G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_10) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 473353453453432.3;
  const char* format = "number: %LG";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_11) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  long double number = 0.12312312412412;
  const char* format = "number: %.10LG";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_12) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 4732.368687;
  const char* format = "number: %+020.5G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_13) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 47375915.0;
  const char* format = "number: %#10G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_14) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.001;
  const char* format = "number: %-*.*G";
  int int_std = sprintf(str_std, format, 5, 2, number);
  int int_my = my_sprintf(str_my, format, 5, 2, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_15) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0;
  const char* format = "number: %0#20.0G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_16) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0;
  const char* format = "number: %G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_17) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 100;
  const char* format = "number: %#G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(capital_shortest_decimal_18) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  double number = 0.1;
  const char* format = "number: %#.5G";
  int int_std = sprintf(str_std, format, number);
  int int_my = my_sprintf(str_my, format, number);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

// test %n

START_TEST(specifier_n) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  int n1 = -2, n2 = -2;
  const char* format = "number: %n";
  int int_std = sprintf(str_std, format, &n1);
  int int_my = my_sprintf(str_my, format, &n2);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(specifier_n_1) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  int number = 1423;
  int n1 = -2, n2 = -2;
  const char* format = "number: %d%n";
  int int_std = sprintf(str_std, format, number, &n1);
  int int_my = my_sprintf(str_my, format, number, &n2);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(specifier_n_2) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  int number = 1423;
  char* str = "helloVerter";
  int n1 = -2, n2 = -2;
  const char* format = "number: %d%s%n";
  int int_std = sprintf(str_std, format, number, str, &n1);
  int int_my = my_sprintf(str_my, format, number, str, &n2);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST
START_TEST(specifier_n_3) {
  char str_std[60] = {'\0'};
  char str_my[60] = {'\0'};
  int n1 = -2, n2 = -2;
  const char* format = "%n";
  int int_std = sprintf(str_std, format, &n1);
  int int_my = my_sprintf(str_my, format, &n2);
  ck_assert_str_eq(str_std, str_my);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_my);
}
END_TEST

Suite* suite_sprintf() {
  Suite* suite = suite_create("suite_sprintf");
  TCase* tcase = tcase_create("sprintf");
  tcase_add_test(tcase, ch);
  tcase_add_test(tcase, ch_1);
  tcase_add_test(tcase, ch_2);
  tcase_add_test(tcase, ch_3);
  tcase_add_test(tcase, ch_4);
  tcase_add_test(tcase, ch_5);
  tcase_add_test(tcase, ch_6);

  tcase_add_test(tcase, unsigned_ch_1);
  tcase_add_test(tcase, unsigned_ch_2);
  tcase_add_test(tcase, unsigned_ch_3);

  tcase_add_test(tcase, wide_string_0);
  tcase_add_test(tcase, wide_string_1);
  tcase_add_test(tcase, wide_string_2);
  tcase_add_test(tcase, wide_string_3);

  tcase_add_test(tcase, specifier_n);
  tcase_add_test(tcase, specifier_n_1);
  tcase_add_test(tcase, specifier_n_2);
  tcase_add_test(tcase, specifier_n_3);

  tcase_add_test(tcase, float_);
  tcase_add_test(tcase, float_1);
  tcase_add_test(tcase, float_2);
  tcase_add_test(tcase, float_3);
  tcase_add_test(tcase, float_4);
  tcase_add_test(tcase, float_5);
  tcase_add_test(tcase, float_6);
  tcase_add_test(tcase, float_7);
  tcase_add_test(tcase, float_8);
  tcase_add_test(tcase, float_9);
  tcase_add_test(tcase, float_10);
  tcase_add_test(tcase, float_11);
  tcase_add_test(tcase, float_12);
  tcase_add_test(tcase, float_13);
  tcase_add_test(tcase, float_14);
  tcase_add_test(tcase, float_15);
  tcase_add_test(tcase, float_16);
  tcase_add_test(tcase, float_17);
  tcase_add_test(tcase, float_18);
  tcase_add_test(tcase, float_19);
  tcase_add_test(tcase, float_20);
  tcase_add_test(tcase, float_21);
  tcase_add_test(tcase, float_22);
  tcase_add_test(tcase, float_23);
  tcase_add_test(tcase, float_24);
  tcase_add_test(tcase, float_25);
  tcase_add_test(tcase, float_26);

  tcase_add_test(tcase, double_1);
  tcase_add_test(tcase, double_2);
  tcase_add_test(tcase, double_3);
  tcase_add_test(tcase, double_4);

  tcase_add_test(tcase, long_double_1);
  tcase_add_test(tcase, long_double_2);
  tcase_add_test(tcase, long_double_3);

  tcase_add_test(tcase, string);
  tcase_add_test(tcase, string_1);
  tcase_add_test(tcase, string_2);
  tcase_add_test(tcase, string_3);
  tcase_add_test(tcase, string_4);
  tcase_add_test(tcase, string_5);
  tcase_add_test(tcase, string_6);
  tcase_add_test(tcase, string_7);
  tcase_add_test(tcase, string_8);
  tcase_add_test(tcase, string_9);
  tcase_add_test(tcase, string_10);
  tcase_add_test(tcase, string_11);
  tcase_add_test(tcase, string_12);
  tcase_add_test(tcase, string_13);
  tcase_add_test(tcase, string_14);
  tcase_add_test(tcase, string_15);

  tcase_add_test(tcase, pointer);
  tcase_add_test(tcase, pointer_1);
  tcase_add_test(tcase, pointer_2);
  tcase_add_test(tcase, pointer_3);
  tcase_add_test(tcase, pointer_4);
  tcase_add_test(tcase, pointer_5);
  tcase_add_test(tcase, pointer_6);
  tcase_add_test(tcase, pointer_7);

  tcase_add_test(tcase, integer);
  tcase_add_test(tcase, integer_1);
  tcase_add_test(tcase, integer_2);
  tcase_add_test(tcase, integer_3);
  tcase_add_test(tcase, integer_4);
  tcase_add_test(tcase, integer_5);
  tcase_add_test(tcase, integer_6);
  tcase_add_test(tcase, integer_7);
  tcase_add_test(tcase, integer_8);
  tcase_add_test(tcase, integer_9);
  tcase_add_test(tcase, integer_10);
  tcase_add_test(tcase, integer_11);
  tcase_add_test(tcase, integer_12);
  tcase_add_test(tcase, integer_13);
  tcase_add_test(tcase, integer_14);
  tcase_add_test(tcase, integer_15);
  tcase_add_test(tcase, integer_16);
  tcase_add_test(tcase, integer_17);

  tcase_add_test(tcase, decimal);
  tcase_add_test(tcase, decimal_1);
  tcase_add_test(tcase, decimal_2);
  tcase_add_test(tcase, decimal_3);
  tcase_add_test(tcase, decimal_4);
  tcase_add_test(tcase, decimal_5);
  tcase_add_test(tcase, decimal_6);
  tcase_add_test(tcase, decimal_7);
  tcase_add_test(tcase, decimal_8);
  tcase_add_test(tcase, decimal_9);
  tcase_add_test(tcase, decimal_10);
  tcase_add_test(tcase, decimal_11);
  tcase_add_test(tcase, decimal_12);
  tcase_add_test(tcase, decimal_13);

  tcase_add_test(tcase, hexadecimal);
  tcase_add_test(tcase, hexadecimal_1);
  tcase_add_test(tcase, hexadecimal_2);
  tcase_add_test(tcase, hexadecimal_3);
  tcase_add_test(tcase, hexadecimal_4);
  tcase_add_test(tcase, hexadecimal_5);
  tcase_add_test(tcase, hexadecimal_6);
  tcase_add_test(tcase, hexadecimal_7);
  tcase_add_test(tcase, hexadecimal_8);
  tcase_add_test(tcase, hexadecimal_9);
  tcase_add_test(tcase, hexadecimal_10);
  tcase_add_test(tcase, hexadecimal_11);
  tcase_add_test(tcase, hexadecimal_12);
  tcase_add_test(tcase, hexadecimal_13);

  tcase_add_test(tcase, long_integer);
  tcase_add_test(tcase, long_integer_1);
  tcase_add_test(tcase, long_integer_2);
  tcase_add_test(tcase, long_integer_3);
  tcase_add_test(tcase, long_integer_4);
  tcase_add_test(tcase, long_integer_5);
  tcase_add_test(tcase, long_integer_6);
  tcase_add_test(tcase, long_integer_7);
  tcase_add_test(tcase, long_integer_8);
  tcase_add_test(tcase, long_integer_9);
  tcase_add_test(tcase, long_integer_10);
  tcase_add_test(tcase, long_integer_11);

  tcase_add_test(tcase, symbol_percent);
  tcase_add_test(tcase, symbol_percent_1);

  tcase_add_test(tcase, unsigned_octal);
  tcase_add_test(tcase, unsigned_octal_1);
  tcase_add_test(tcase, unsigned_octal_2);
  tcase_add_test(tcase, unsigned_octal_3);
  tcase_add_test(tcase, unsigned_octal_4);
  tcase_add_test(tcase, unsigned_octal_5);
  tcase_add_test(tcase, unsigned_octal_6);
  tcase_add_test(tcase, unsigned_octal_7);
  tcase_add_test(tcase, unsigned_octal_8);
  tcase_add_test(tcase, unsigned_octal_9);
  tcase_add_test(tcase, unsigned_octal_10);
  tcase_add_test(tcase, unsigned_octal_11);
  tcase_add_test(tcase, unsigned_octal_12);
  tcase_add_test(tcase, unsigned_octal_13);

  tcase_add_test(tcase, shortest_decimal);
  tcase_add_test(tcase, shortest_decimal_1);
  tcase_add_test(tcase, shortest_decimal_2);
  tcase_add_test(tcase, shortest_decimal_3);
  tcase_add_test(tcase, shortest_decimal_4);
  tcase_add_test(tcase, shortest_decimal_5);
  tcase_add_test(tcase, shortest_decimal_6);
  tcase_add_test(tcase, shortest_decimal_7);
  tcase_add_test(tcase, shortest_decimal_8);
  tcase_add_test(tcase, shortest_decimal_9);
  tcase_add_test(tcase, shortest_decimal_10);
  tcase_add_test(tcase, shortest_decimal_11);
  tcase_add_test(tcase, shortest_decimal_12);
  tcase_add_test(tcase, shortest_decimal_13);
  tcase_add_test(tcase, shortest_decimal_14);
  tcase_add_test(tcase, shortest_decimal_15);
  tcase_add_test(tcase, shortest_decimal_16);
  tcase_add_test(tcase, shortest_decimal_17);
  tcase_add_test(tcase, shortest_decimal_18);
  tcase_add_test(tcase, shortest_decimal_19);
  tcase_add_test(tcase, shortest_decimal_20);
  tcase_add_test(tcase, shortest_decimal_21);
  tcase_add_test(tcase, shortest_decimal_22);
  tcase_add_test(tcase, shortest_decimal_23);

  tcase_add_test(tcase, unsigned_decimal);
  tcase_add_test(tcase, unsigned_decimal_1);
  tcase_add_test(tcase, unsigned_decimal_2);
  tcase_add_test(tcase, unsigned_decimal_3);
  tcase_add_test(tcase, unsigned_decimal_4);
  tcase_add_test(tcase, unsigned_decimal_5);
  tcase_add_test(tcase, unsigned_decimal_6);
  tcase_add_test(tcase, unsigned_decimal_7);
  tcase_add_test(tcase, unsigned_decimal_8);
  tcase_add_test(tcase, unsigned_decimal_9);
  tcase_add_test(tcase, unsigned_decimal_10);
  tcase_add_test(tcase, unsigned_decimal_11);
  tcase_add_test(tcase, unsigned_decimal_12);

  tcase_add_test(tcase, scientific_notation);
  tcase_add_test(tcase, scientific_notation_1);
  tcase_add_test(tcase, scientific_notation_2);
  tcase_add_test(tcase, scientific_notation_3);
  tcase_add_test(tcase, scientific_notation_4);
  tcase_add_test(tcase, scientific_notation_5);
  tcase_add_test(tcase, scientific_notation_6);
  tcase_add_test(tcase, scientific_notation_7);
  tcase_add_test(tcase, scientific_notation_8);
  tcase_add_test(tcase, scientific_notation_9);
  tcase_add_test(tcase, scientific_notation_10);
  tcase_add_test(tcase, scientific_notation_11);
  tcase_add_test(tcase, scientific_notation_12);
  tcase_add_test(tcase, scientific_notation_13);
  tcase_add_test(tcase, scientific_notation_14);
  tcase_add_test(tcase, scientific_notation_15);
  tcase_add_test(tcase, scientific_notation_16);
  tcase_add_test(tcase, scientific_notation_17);
  tcase_add_test(tcase, scientific_notation_18);
  tcase_add_test(tcase, scientific_notation_19);
  tcase_add_test(tcase, scientific_notation_20);
  tcase_add_test(tcase, scientific_notation_21);
  tcase_add_test(tcase, scientific_notation_22);
  tcase_add_test(tcase, scientific_notation_23);
  tcase_add_test(tcase, scientific_notation_24);

  tcase_add_test(tcase, capital_hexadecimal);
  tcase_add_test(tcase, capital_hexadecimal_1);
  tcase_add_test(tcase, capital_hexadecimal_2);
  tcase_add_test(tcase, capital_hexadecimal_3);
  tcase_add_test(tcase, capital_hexadecimal_4);
  tcase_add_test(tcase, capital_hexadecimal_5);
  tcase_add_test(tcase, capital_hexadecimal_6);
  tcase_add_test(tcase, capital_hexadecimal_7);
  tcase_add_test(tcase, capital_hexadecimal_8);
  tcase_add_test(tcase, capital_hexadecimal_9);
  tcase_add_test(tcase, capital_hexadecimal_10);
  tcase_add_test(tcase, capital_hexadecimal_11);
  tcase_add_test(tcase, capital_hexadecimal_12);

  tcase_add_test(tcase, capital_shortest_decimal);
  tcase_add_test(tcase, capital_shortest_decimal_1);
  tcase_add_test(tcase, capital_shortest_decimal_2);
  tcase_add_test(tcase, capital_shortest_decimal_3);
  tcase_add_test(tcase, capital_shortest_decimal_4);
  tcase_add_test(tcase, capital_shortest_decimal_5);
  tcase_add_test(tcase, capital_shortest_decimal_6);
  tcase_add_test(tcase, capital_shortest_decimal_7);
  tcase_add_test(tcase, capital_shortest_decimal_8);
  tcase_add_test(tcase, capital_shortest_decimal_9);
  tcase_add_test(tcase, capital_shortest_decimal_10);
  tcase_add_test(tcase, capital_shortest_decimal_11);
  tcase_add_test(tcase, capital_shortest_decimal_12);
  tcase_add_test(tcase, capital_shortest_decimal_13);
  tcase_add_test(tcase, capital_shortest_decimal_14);
  tcase_add_test(tcase, capital_shortest_decimal_15);
  tcase_add_test(tcase, capital_shortest_decimal_16);
  tcase_add_test(tcase, capital_shortest_decimal_17);
  tcase_add_test(tcase, capital_shortest_decimal_18);

  tcase_add_test(tcase, capital_scientific_notation);
  tcase_add_test(tcase, capital_scientific_notation_1);
  tcase_add_test(tcase, capital_scientific_notation_2);
  tcase_add_test(tcase, capital_scientific_notation_3);
  tcase_add_test(tcase, capital_scientific_notation_4);
  tcase_add_test(tcase, capital_scientific_notation_5);
  tcase_add_test(tcase, capital_scientific_notation_6);
  tcase_add_test(tcase, capital_scientific_notation_7);
  tcase_add_test(tcase, capital_scientific_notation_8);
  tcase_add_test(tcase, capital_scientific_notation_9);
  tcase_add_test(tcase, capital_scientific_notation_10);
  tcase_add_test(tcase, capital_scientific_notation_11);
  tcase_add_test(tcase, capital_scientific_notation_12);
  tcase_add_test(tcase, capital_scientific_notation_13);
  tcase_add_test(tcase, capital_scientific_notation_14);
  tcase_add_test(tcase, capital_scientific_notation_15);
  tcase_add_test(tcase, capital_scientific_notation_16);
  tcase_add_test(tcase, capital_scientific_notation_17);
  tcase_add_test(tcase, capital_scientific_notation_18);
  tcase_add_test(tcase, capital_scientific_notation_19);

  suite_add_tcase(suite, tcase);
  return suite;
}