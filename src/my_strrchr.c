#include "my_string.h"
/*
Searches for the last occurrence of the character c
(an unsigned char) in the string pointed to by the argument str
*/
char* my_strrchr(const char* str, int c) {
  char* result = MY_NULL;
  char* str_end = (char*)str + my_strlen(str);
  if (c == '\0') {
    result = str_end;
  }
  while (str_end >= str && !result) {
    if (*str_end == c) {
      result = str_end;
    }
    str_end--;
  }
  return result;
}