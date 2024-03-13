#include "my_string.h"
/*
Breaks string str into a series of tokens separated by delim
*/
char *my_strtok(char *str, const char *delim) {
  static char *next_ptr;
  char *token = MY_NULL;
  if (str != MY_NULL) {
    next_ptr = str;
  }
  int has_match = 1;
  while (*next_ptr && has_match) {
    const char *delim_ptr = delim;
    has_match = 0;
    while (*delim_ptr) {
      if (*next_ptr == *delim_ptr) {
        has_match = 1;
      }
      delim_ptr++;
    }
    if (has_match) {
      next_ptr++;
    }
  }
  if (*next_ptr != '\0') {
    token = next_ptr;
    has_match = 0;
    while (*next_ptr && !has_match) {
      const char *delim_ptr = delim;
      while (*delim_ptr && !has_match) {
        if (*next_ptr == *delim_ptr) {
          has_match = 1;
        }
        if (!has_match) {
          delim_ptr++;
        }
      }
      if (!has_match) {
        next_ptr++;
      }
    }
    if (*next_ptr) {
      *next_ptr = '\0';
      next_ptr++;
    }
  }
  return token;
}
