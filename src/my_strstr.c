#include "my_string.h"
/*
Finds the first occurrence of the entire string needle
(not including the terminating null character) which appears in the string
haystack
*/
char *my_strstr(const char *haystack, const char *needle) {
  int flag1 = 0, flag2 = 0;
  char *ptr = MY_NULL;
  if (*needle == '\0') {
    flag1 = 1;
    ptr = (char *)haystack;
  }
  while (*haystack && !flag1) {
    const char *ptr_h = haystack;
    const char *ptr_n = needle;
    while (*ptr_h && *ptr_n && *ptr_h == *ptr_n && !flag2) {
      ptr_h++;
      ptr_n++;
    }
    if (*ptr_n == '\0') {
      flag2 = 1;
      ptr = (char *)haystack;
    }
    haystack++;
  }
  return ptr;
}