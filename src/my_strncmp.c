#include "my_string.h"
/*
Compares at most the first n bytes of str1 and str2
*/
int my_strncmp(const char* str1, const char* str2, my_size_t n) {
  const char* str_first = str1;
  const char* str_sec = str2;
  int result = 0;
  while (((str_first < str1 + n) || (str_sec < str2 + n)) && !result) {
    if (*str_first != *str_sec) {
      result = *str_first - *str_sec;
    }
    str_first++;
    str_sec++;
  }
  return result;
}