#include "my_string.h"
/*
Computes the length of the string str up to
but not including the terminating null character
*/
my_size_t my_strlen(const char* str) {
  my_size_t count = 0;
  if (str != MY_NULL) {
    while (*str != '\0') {
      count++;
      str++;
    }
  }
  return count;
}