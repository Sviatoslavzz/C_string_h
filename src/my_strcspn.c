#include "my_string.h"
/*
Calculates the length of the initial segment of str1
which consists entirely of characters not in str2
*/
my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t len = 0;
  while (len < my_strlen(str1) && !my_strchr(str2, str1[len])) {
    len++;
  }
  return len;
}