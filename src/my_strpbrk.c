#include "my_string.h"
/*
Finds the first character in the string str1 that
matches any character specified in str2
*/
char *my_strpbrk(const char *str1, const char *str2) {
  const char *p_str1 = str1;
  int found = 0;
  while (*p_str1 != '\0' && !found) {
    const char *p_str2;
    p_str2 = str2;
    while (*p_str2 != '\0' && !found) {
      if (*p_str1 == *p_str2) {
        found = 1;
      }
      p_str2++;
    }
    p_str1 += (found == 0);
  }

  if (!found) {
    p_str1 = MY_NULL;
  }
  return (char *)p_str1;
}