#include "my_string.h"
/*
Searches for the first occurrence of the character
c (an unsigned char) in the string pointed to, by the argument str
*/
char* my_strchr(const char* str, int c) {
  char* result = MY_NULL;
  char* str_start = (char*)str;
  char* str_end = str_start + my_strlen(str);
  if (c == '\0') {
    result = str_end;
  }
  while (str_start < str_end && !result) {
    if (*str_start == c) {
      result = str_start;
    }
    str_start++;
  }
  return result;
}