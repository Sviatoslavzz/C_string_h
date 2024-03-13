#include "my_string.h"
/*
Appends the string pointed to, by src to the end of the
string pointed to, by dest up to n characters long
*/
char* my_strncat(char* dest, const char* src, my_size_t n) {
  my_size_t dest_len = my_strlen(dest);
  my_size_t count = 0;
  for (; count < n && src[count] != '\0'; count++) {
    dest[dest_len + count] = src[count];
  }
  dest[dest_len + count] = '\0';
  return dest;
}