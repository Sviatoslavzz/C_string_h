#include "my_string.h"
/*
Compares the first n bytes of str1 and str2
*/
int my_memcmp(const void* str1, const void* str2, my_size_t n) {
  const unsigned char* str_first = str1;
  const unsigned char* str_sec = str2;
  int result = 0;
  while (((str_first < (unsigned char*)str1 + n) ||
          (str_sec < (unsigned char*)str2 + n)) &&
         !result) {
    if (*str_first != *str_sec) {
      result = (*str_first - *str_sec);
    }
    str_first++;
    str_sec++;
  }
  return result;
}